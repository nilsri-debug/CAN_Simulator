#include "ECU.h"
#include <iostream>
using namespace std;

ECU::ECU(int id)
{
	Id = id;																						// store ECU ID
}
int ECU::get_id()
{
	return Id;																						// return ECU ID
}

CANMessage ECU::createMessage(uint32_t id, uint8_t dlc, uint8_t data[])
{
	CANMessage message;
	
	message.identifier = id;																		// set CAN identifier
	message.dlc = dlc;																				// set Data Length Code
	for (int i = 0; i < dlc; i++)
	{
		message.data[i] = data[i];
	}
	return message;

}
void ECU::receiveMessage(const CANMessage& message)
{
	hasReceivedMessage = true;
	receivedMessage = message;
}
CANMessage ECU::get_received_message()
{
	return receivedMessage;
}
bool ECU::get_hasreceivedMesage()
{
	return hasReceivedMessage;
}