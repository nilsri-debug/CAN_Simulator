#pragma once
#include <vector>
#include "ECU.h"

struct CANTransmissi

class CANBus
{
public:
	void registerECU( ECU&);
	void transmit(const CANMessage& message1, int transmitterID1, const CANMessage& message2, int transmitterID2);
	CANMessage arbitrate(const CANMessage& message1, const CANMessage& message2);
private:
	std::vector<ECU*> ecus;
};

