#include <iostream>
using namespace std;

#include "CANMessage.h"
#include "ECU.h"
#include "CANBus.h"

int main()
{
    ECU ecu1(1);
    ECU ecu2(2);
    ECU ecu3(3);

    CANBus bus;

    // ECUs beim CAN-Bus registrieren
    bus.registerECU(ecu1);
    bus.registerECU(ecu2);
    bus.registerECU(ecu3);

    // Nachrichtendaten
    uint8_t data[3];

    data[0] = 0x12;
    data[1] = 0x34;
    data[2] = 0x56;

    // ECU1 erstellt Nachricht
    CANMessage message1 = ecu1.createMessage(0x100, 3, data);
    CANMessage message2 = ecu2.createMessage(0x200, 3, data);

    // ECU1 sendet Nachricht über den Bus
    bus.transmit(message1, ecu1.get_id(), message2, ecu2.get_id());

    
    CANMessage output = bus.arbitrate(message1, message2);
    cout << "The winning Identifier is:"<< hex << output.identifier << endl;
    
    
    /*
    // Test 1: ECU1 darf die Nachricht nicht empfangen
    if (!ecu1.get_hasreceivedMesage())
    {
        cout << "Test 1 passed: Sender hat die Nachricht nicht empfangen." << endl;
    }
    else
    {
        cout << "Test 1 failed: Sender hat die Nachricht empfangen." << endl;
    }

    // Test 2: ECU2 muss eine Nachricht empfangen
    if (ecu2.get_hasreceivedMesage())
    {
        cout << "Test 2 passed: ECU2 hat eine Nachricht empfangen." << endl;
    }
    else
    {
        cout << "Test 2 failed: ECU2 hat keine Nachricht empfangen." << endl;
    }

    // Test 3: ECU3 muss eine Nachricht empfangen
    if (ecu3.get_hasreceivedMesage())
    {
        cout << "Test 3 passed: ECU3 hat eine Nachricht empfangen." << endl;
    }
    else
    {
        cout << "Test 3 failed: ECU3 hat keine Nachricht empfangen." << endl;
    }

    // Test 4: ECU2 muss genau die gesendete Nachricht erhalten haben
    CANMessage receivedMessage2 = ecu2.get_received_message();

    if (receivedMessage2 == message)
    {
        cout << "Test 4 passed: ECU2 hat die richtige Nachricht erhalten." << endl;
    }
    else
    {
        cout << "Test 4 failed: ECU2 hat eine falsche Nachricht erhalten." << endl;
    }

    // Test 5: ECU3 muss genau die gesendete Nachricht erhalten haben
    CANMessage receivedMessage3 = ecu3.get_received_message();

    if (receivedMessage3 == message)
    {
        cout << "Test 5 passed: ECU3 hat die richtige Nachricht erhalten." << endl;
    }
    else
    {
        cout << "Test 5 failed: ECU3 hat eine falsche Nachricht erhalten." << endl;
    }

    return 0;
    */
}
