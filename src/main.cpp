#include <Arduino.h>
#include <FlexCAN_T4.h>

FlexCAN_T4<CAN2, RX_SIZE_256, TX_SIZE_16> Can0;
CAN_message_t msg;

byte configData[8] = {
  0x75, 0x30,       // Programming constant (30000)
  0x04, 0xC4,       // New CAN ID = 0x04C4
  25,              // Emissivity = 0.25
  8,                // 100 Hz
  40,              // 4 channels
  1                 // 1 Mbit/s
};

void setup() {
    Serial.begin(115200);
    while (!Serial);  // Wait for Serial to connect

    Can0.begin();
    Can0.setBaudRate(1000000);  // 1Mbit/s

    //Serial.println("CAN2 Ready to receive...");


    // Prepare the config message
    msg.id = 0x4C4;             // This should match the sensor's **current base ID**
    msg.len = 8;
    for (int i = 0; i < msg.len; i++) {
      msg.buf[i] = configData[i];
    }
    Serial.println("Starting to send config...");

    // Send once per second for 10 seconds
    for (int i = 0; i < 10; i++) {
      Can0.write(msg);
      Serial.println("Message sent");
      delay(1000);
  }

  Serial.println("Configuration complete!");
}


void loop() {
  /*
    if (Can0.read(msg)) {
        Serial.print("ID: 0x");
        Serial.print(msg.id, HEX);
        Serial.print("  Data: ");
        for (int i = 0; i < msg.len; i++) {
            Serial.printf("%02X ", msg.buf[i]);
        }
        Serial.println();
    }
  */
}
