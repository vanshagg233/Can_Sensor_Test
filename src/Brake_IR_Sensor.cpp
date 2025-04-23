#include <Brake_IR_Sensor.h>

void printTempsFromMsg(CAN_message_t msg) {
    switch (msg.id) {
        case 1220: case 1221: case 1222: case 1223:
            Serial.print("LF: ");
            break;
        case 1225: case 1226: case 1227: case 1228:
            Serial.print("RF: ");
            break;
        case 1230: case 1231: case 1232: case 1233:
            Serial.print("LR: ");
            break;
        case 1235: case 1236: case 1237: case 1238:
            Serial.print("RR: ");
            break;
        default:
            return;
    }

    for (int i = 0; i < 4; i++) {
        int16_t raw = (msg.buf[i*2] << 8) | msg.buf[i*2 + 1];
        float temp = raw * 0.1 - 100;
        Serial.printf("%.1f°C ", temp);
    }
    Serial.println();
}