#pragma once
#include <vector>
#include "ECU.h"

struct CANTransmission
{
	CANMessage message;
	int transmitterID;
};

class CANBus
{
public:
	void registerECU(ECU&);
	void transmit(const std::vector<CANTransmission>& transmissions);

	CANTransmission arbitrate(const CANTransmission& transmission1, const CANTransmission& transmission2);
private:
	std::vector<ECU*> ecus;
};

