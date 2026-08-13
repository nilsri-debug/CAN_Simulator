#include "ECU.h"
#include <iostream>
using namespace std;

ECU::ECU(int id)
{
	Id = id;
}
int ECU::get_id()
{
	return Id;
}

CANMessage ECU::createMessage(uint32_t id, uint8_t dlc, uint8_t data[])
{
	CANMessage message;
	
	message.identifier = id;
	message.dlc = dlc;
	for (int i = 0; i < dlc; i++)
	{
		message.data[i] = data[i];
	}
	return message;

}
void ECU::receiveMessage(const CANMessage& message)
{
	receivedMessage = message;
}
CANMessage ECU::get_received_message()
{
	return receivedMessage;
}