#pragma once
#include <vector>
#include "ECU.h"


class CANBus
{
public:
	void registerECU( ECU&);
	void transmit(const CANMessage& message, int transmitterID);
private:
	std::vector<ECU*> ecus;
};

