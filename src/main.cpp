#include <Arduino.h>
#include <FlexCAN_T4.h>

FlexCAN_T4<CAN2, RX_SIZE_256, TX_SIZE_16> Can0;
CAN_message_t msg;

void setup() {
    Serial.begin(115200);
    while (!Serial);  // Wait for Serial to connect

    Can0.begin();
    Can0.setBaudRate(500000);  // Match your CAN bus speed

    Serial.println("CAN2 Ready to receive...");
}

void loop() {
    if (Can0.read(msg)) {
        Serial.print("ID: 0x");
        Serial.print(msg.id, HEX);
        Serial.print("  Data: ");
        for (int i = 0; i < msg.len; i++) {
            Serial.printf("%02X ", msg.buf[i]);
        }
        Serial.println();
    }
}
