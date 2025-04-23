#include <Arduino.h>
#include <FlexCAN_T4.h>

void configSensor(byte* data, CAN_message_t msg, FlexCAN_T4<CAN2, RX_SIZE_256, TX_SIZE_16> Can0);