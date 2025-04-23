#include <IR_Config.h>

void configSensor(byte* data, CAN_message_t msg, FlexCAN_T4<CAN2, RX_SIZE_256, TX_SIZE_16> CanBUS) {
    // Prepare the config message
    msg.id = 0x4C4;
    msg.len = 8;
    for (int i = 0; i < msg.len; i++) {
    msg.buf[i] = data[i];
    }
    Serial.println("Starting to send config...");

    // Send once per second for 10 seconds
    for (int i = 0; i < 10; i++) {
    CanBUS.write(msg);
    Serial.println("Message sent");
    delay(1000);
    }

    Serial.println("Configuration complete!");
}