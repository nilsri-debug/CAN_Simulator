#include "pch.h"
#include <gtest/gtest.h>

#include "CANMessage.h"
#include "CANBus.h"
#include "ECU.h"

TEST(CANBusTest, MessageIsForwardedToECU)
{
    // Arrange
    ECU ecu1(1);
    ECU ecu2(2);
    ECU ecu3(3);

    CANBus bus;

    bus.registerECU(ecu1);
    bus.registerECU(ecu2);
    bus.registerECU(ecu3);

    uint8_t data[3];

    data[0] = 0x12;
    data[1] = 0x34;
    data[2] = 0x56;

    CANMessage message = ecu1.createMessage(0x100, 3, data);

    // Act
    bus.transmit(message, ecu1.get_id(), message, ecu1.get_id());

    // Assert
    EXPECT_FALSE(ecu1.get_hasreceivedMesage());
    EXPECT_TRUE(ecu2.get_hasreceivedMesage());
    EXPECT_TRUE(ecu3.get_hasreceivedMesage());
    EXPECT_TRUE(ecu2.get_received_message() == (message));
    EXPECT_TRUE(ecu3.get_received_message() == (message));
}
TEST(CANBusTest, TransmitterDoesentReceivedMessage)
{

}
TEST(CANBusTest, Arbitrate_winningmessage2)
{

    //Arrange
    CANBus bus;
   
    ECU ecu1(1);
    ECU ecu2(2);
    ECU ecu3(3);

    bus.registerECU(ecu1);
    bus.registerECU(ecu2);
    bus.registerECU(ecu3);
    
    uint8_t data[3] = { 0x12, 0x34, 0x56 };

    CANMessage message1 = ecu1.createMessage(0x300, 3, data);
    CANMessage message2 = ecu2.createMessage(0x100, 3, data);

    //Act
    bus.transmit(message1, ecu1.get_id(), message2, ecu2.get_id());

    //Assert
    EXPECT_TRUE(ecu1.get_hasreceivedMesage());
    EXPECT_TRUE(ecu3.get_hasreceivedMesage());
    EXPECT_FALSE(ecu2.get_hasreceivedMesage());
    EXPECT_FALSE(ecu2.get_hasreceivedMesage());
    EXPECT_TRUE(ecu1.get_received_message() == message2);
    EXPECT_TRUE(ecu3.get_received_message() == message2);
}
TEST(CANBusTest, Arbitrate_winningmessage1)
{

    //Arrange
    CANBus bus;

    ECU ecu1(1);
    ECU ecu2(2);
    ECU ecu3(3);

    bus.registerECU(ecu1);
    bus.registerECU(ecu2);
    bus.registerECU(ecu3);

    uint8_t data[3] = { 0x12, 0x34, 0x56 };

    CANMessage message1 = ecu1.createMessage(0x50, 3, data);
    CANMessage message2 = ecu2.createMessage(0x100, 3, data);

    //Act
    bus.transmit(message1, ecu1.get_id(), message2, ecu2.get_id());

    //Assert
    EXPECT_FALSE(ecu1.get_hasreceivedMesage());
    EXPECT_TRUE(ecu3.get_hasreceivedMesage());
    EXPECT_TRUE(ecu2.get_hasreceivedMesage());
    EXPECT_TRUE(ecu2.get_received_message() == message1);
    EXPECT_FALSE(ecu1.get_hasreceivedMesage());
    EXPECT_TRUE(ecu3.get_received_message() == message1);
}

TEST(CANBusTest, Arbitrate_message1_same_as_message2)
{

    //Arrange
    CANBus bus;

    ECU ecu1(1);
    ECU ecu2(2);
    ECU ecu3(3);

    bus.registerECU(ecu1);
    bus.registerECU(ecu2);
    bus.registerECU(ecu3);

    uint8_t data[3] = { 0x12, 0x34, 0x56 };

    CANMessage message1 = ecu1.createMessage(0x100, 3, data);
    CANMessage message2 = ecu2.createMessage(0x100, 3, data);

    //Act
    bus.transmit(message1, ecu1.get_id(), message2, ecu2.get_id());

    //Assert
    EXPECT_FALSE(ecu1.get_hasreceivedMesage());
    EXPECT_TRUE(ecu3.get_hasreceivedMesage());
    EXPECT_TRUE(ecu2.get_hasreceivedMesage());
    EXPECT_TRUE(ecu2.get_received_message() == message1);
    EXPECT_FALSE(ecu1.get_hasreceivedMesage());
    EXPECT_TRUE(ecu3.get_received_message() == message1);
}