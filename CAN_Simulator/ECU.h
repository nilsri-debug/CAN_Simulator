#pragma once
#include "CANMessage.h"
class ECU
{
public:
	ECU(int id);
	int get_id();
	CANMessage createMessage(uint32_t id, uint8_t dlc, uint8_t data[]);
	void receiveMessage(const CANMessage& message);
	CANMessage get_received_message();
private:
	int Id = 0;
	CANMessage receivedMessage;
};

