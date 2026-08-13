#include <iostream>
using namespace std;
#include "CANMessage.h"
#include "ECU.h"

void print_message(const CANMessage& message)
{
	cout << hex << message.identifier << endl;
	cout << dec << static_cast<int>(message.dlc) << endl;
	for (int i = 0; i < message.dlc; i++)
	{
		cout << hex << static_cast<int>(message.data[i]) << endl;
	}
}
int main()
{

	
	ECU ecu1(3);
	uint8_t data[3];

	data[0] = 0x12;
	data[1] = 0x34;
	data[2] = 0x56;
	CANMessage message = ecu1.createMessage(0x100, 3, data);
	print_message(message);
}