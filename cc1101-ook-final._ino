#include "cc1101.h"

CC1101 cc1101;

#define LEDOUTPUT 7

void blinker()
{
    static int i = 0;
    digitalWrite(LEDOUTPUT, i ? HIGH : LOW);
    i = !i;
}

void setup()
{
    Serial.begin(9600);
    Serial.println("Starting CC1101...");

    pinMode(LEDOUTPUT, OUTPUT);
    digitalWrite(LEDOUTPUT, LOW);

    // blink once to signal the setup
    blinker();

    Serial.println("Initialize and set registers.");

    cc1101.init();

    Serial.println("Setting PA_TABLE.");
    config2();

    uint8_t syncWord[] = {0x55, 0x55};
    cc1101.setSyncWord(syncWord, false);
    cc1101.setCarrierFreq(CFREQ_302);
    cc1101.disableAddressCheck();

    delay(1000);

    Serial.print("CC1101_PARTNUM ");
    Serial.println(cc1101.readReg(CC1101_PARTNUM, CC1101_STATUS_REGISTER));
    Serial.print("CC1101_VERSION ");
    Serial.println(cc1101.readReg(CC1101_VERSION, CC1101_STATUS_REGISTER));
    Serial.print("CC1101_MARCSTATE ");
    Serial.println(cc1101.readReg(CC1101_MARCSTATE, CC1101_STATUS_REGISTER) & 0x1f);

    Serial.println("device initialized");
}

void send_data()
{
    CCPACKET data;

    data.length = 5;
    uint8_t le_data[] = {0b00101101, 0b10110110, 0b01001011, 0b00100100, 0b10010010};
    memset(data.data, 0, sizeof(data.data));
    memcpy(data.data, le_data, sizeof(le_data));

    if (!cc1101.sendData(data))
    {
        Serial.println("sent failed :(");
    }
}

void loop()
{
    blinker();
    send_data();
    delay(10);
}

void config2()
{
    enum
    {
        PA_POWER_MINUS_0  = 0x51,
        PA_POWER_MINUS_15 = 0x1D,
        PA_POWER_MINUS_30 = 0x03,
        PA_POWER_ORIGINAL = 0xC0,
    };
    uint8_t PA_TABLE[] = {0x00, PA_POWER_MINUS_0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    cc1101.writeBurstReg(CC1101_PATABLE, PA_TABLE, 8);
}
