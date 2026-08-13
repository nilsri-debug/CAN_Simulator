#include "CANBus.h"
void CANBus::registerECU( ECU& ecu)
{
	ecus.push_back(&ecu);
}
void CANBus::transmit(const CANMessage& message, int transmitterID)
{

	for (int i = 0; i < ecus.size(); i++)
	{
		int ecus_id =ecus[i]->get_id();
		if (ecus_id != transmitterID)
		{
			ecus[i]->receiveMessage(message);
		}
		else
		{
			continue;
		}
	}
}