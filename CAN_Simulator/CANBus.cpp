#include "CANBus.h"
#include "ECU.h"
void CANBus::registerECU( ECU& ecu)
{
	ecus.push_back(&ecu);																							// register ECU with the CAN bus
}
CANTransmission CANBus::arbitrate(const CANTransmission& transmission1, const CANTransmission& transmission2)		// Perform CAN arbitrition
{
	if (transmission1.message.identifier < transmission2.message.identifier)										// transmission with lower identificator wins
	{
		return transmission1;
	}
	else if (transmission1.message.identifier > transmission2.message.identifier)
	{
		return transmission2;
	}
	else
	{
		return transmission1;;
	}
}
void CANBus::transmit(const std::vector<CANTransmission>& transmissions)											// transmitt the the current winner
{
	CANTransmission winner = transmissions[0];
	for (int i = 1; i < transmissions.size(); i++)
	{
		winner = arbitrate(winner, transmissions[i]); 
	}

	for (int i = 0; i < ecus.size(); i++)																			// Compare all remaining transmissions with the current winner
	{
		int ecuid = ecus[i]->get_id();
		if (ecuid != winner.transmitterID)
		{
			ecus[i]->receiveMessage(winner.message);																// the winner doesen#t receive his one message
		}
	}
}

