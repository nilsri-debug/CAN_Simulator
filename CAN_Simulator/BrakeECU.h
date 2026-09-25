#pragma once
#include "ECU.h"
class BrakeECU : public ECU //public is necessary to inheriate public from ECU
{
public:
	BrakeECU(int id);

	CANTransmission activateBrake();
	void deactivateBrake();

	bool get_brakeInOperation();

private:
	bool brakeInOperation;

};

