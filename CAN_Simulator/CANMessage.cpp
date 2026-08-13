#include "CANMessage.h"
bool CANMessage::operator==(const CANMessage& message)
{
	if (identifier != message.identifier || dlc != message.dlc)
	{
		return false;
	}
	
	for (int i = 0; i < dlc; i++)
	{
		if (data[i] != message.data[i])
		{
		
			return false;
		}
		
	}
	return true;
}