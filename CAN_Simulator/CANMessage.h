#pragma once
#include <cstdint>
struct CANMessage
{
	uint32_t identifier;
	uint8_t dlc;
	uint8_t data[8];
};

