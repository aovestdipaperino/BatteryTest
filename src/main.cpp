
#include <Adafruit_BusIO_Register.h>
#include <Adafruit_MAX1704x.h>

#include "BluetoothSerial.h"


Adafruit_MAX17048 pwr_mgmt;

BluetoothSerial SerialBT;


void setup()
{
    //WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0);
    Serial.begin(115200);
    Wire.begin(17, 19);
    pwr_mgmt.begin();
    SerialBT.begin("RemoteTest"); //Bluetooth device name
    pwr_mgmt.quickStart();
    delay(500);
}

void loop()
{

    SerialBT.print("VCELL V   : ");
    SerialBT.println(pwr_mgmt.cellVoltage());
    SerialBT.print("VCELL SOC : ");
    SerialBT.print(pwr_mgmt.cellPercent());
    SerialBT.println(" \%");
    SerialBT.println();
    delay(1000);
}