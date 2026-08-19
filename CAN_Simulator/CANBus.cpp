#include "CANBus.h"
#include "ECU.h"
void CANBus::registerECU( ECU& ecu)
{
	ecus.push_back(&ecu);
}
void CANBus::transmit(const CANMessage& message1, int transmitterID1, const CANMessage& message2, int transmitterID2)
{
	CANMessage output = arbitrate(message1, message2);
	int winner_id;
	if (output == message1)
	{
		winner_id = transmitterID1;

	}
	else
	{
		winner_id = transmitterID2;
	}
	for (int i = 0; i < ecus.size(); i++)
	{
		
		int ecus_id =ecus[i]->get_id();
		if (ecus_id != winner_id)
		{
			ecus[i]->receiveMessage(output);
		}
		else
		{
			continue;
		}
	}
}
CANMessage CANBus::arbitrate(const CANMessage& message1, const CANMessage& message2)
{
	if (message1.identifier < message2.identifier)
	{
		return message1;
	}
	else if (message1.identifier > message2.identifier)
	{
		return message2;
	}
	else if (message1.identifier == message2.identifier)
	{
		return message1;
	}
}