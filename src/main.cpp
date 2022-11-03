#include <Arduino.h>
#include "MAX17048.h"
#include "WiFi.h"
#include "esp32-hal-bt.h"

MAX17048 pwr_mgmt;

void setup()
{
  Serial.begin(115200);
  Wire.begin(17, 19);
  pwr_mgmt.attatch(Wire);
  WiFi.mode(WIFI_OFF); // just to be sure
  btStop();
}

void loop()
{
  static float prevPerc = 0;
    delay(1000);

  if (pwr_mgmt.accuratePercent() == prevPerc) return;

  prevPerc = pwr_mgmt.accuratePercent();
  Serial.print("VCELL V   : ");
  Serial.println(pwr_mgmt.voltage());
  Serial.print("VCELL SOC : ");
  Serial.print(pwr_mgmt.accuratePercent());
  Serial.println(" \%");
  Serial.println();

}