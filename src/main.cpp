#include <Arduino.h>
#include <FlexCAN_T4.h>
#include <Brake_IR_Sensor.h>
#include <IR_Config.h>

FlexCAN_T4<CAN2, RX_SIZE_256, TX_SIZE_16> Can0;
CAN_message_t msg;

byte configData[8] = {
  0x75, 0x30,       // Programming constant (30000)
  0x04, 0xC4,       // New CAN ID = 0x04C4 (depends on wheel location (RR, etc))
  80,              // Emissivity = 0.25 (based on material)
  8,                // 100 Hz
  40,              // 4 channels
  1                 // 1 Mbit/s
};

bool config = 0;

void setup() {
    Serial.begin(115200);
    while (!Serial);  // Wait for Serial to connect

    Can0.begin();
    Can0.setBaudRate(1000000);  // 1Mbit/s

    Serial.println("CAN2 Ready...");
    
    if (config) {
      configSensor(configData, msg, Can0);
    }
    

}


void loop() {
  if (!config){
    if (Can0.read(msg)) {
      printTempsFromMsg(msg);
      delay(200);
    }
  }
}
