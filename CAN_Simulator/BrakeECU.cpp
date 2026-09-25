#include "BrakeECU.h"
#include "CANBus.h"

BrakeECU::BrakeECU(int id)
	: ECU(id)
{
	brakeInOperation = false;
}
// activate Brake
CANTransmission  BrakeECU::activateBrake()
{
	uint8_t data[1] = { 0x01 };
	brakeInOperation = true;
	CANMessage message = createMessage(0x100, 1, data);		// create a CAN message indicating that the brake is active
	int id = get_id();
	CANTransmission transmission;
	transmission.message = message;
	transmission.transmitterID = id;
	return transmission;
}

void BrakeECU::deactivateBrake()
{
	brakeInOperation = false;								// set false to deactivate brake
}

bool BrakeECU::get_brakeInOperation()
{
	return brakeInOperation;								// get Brake Status
}