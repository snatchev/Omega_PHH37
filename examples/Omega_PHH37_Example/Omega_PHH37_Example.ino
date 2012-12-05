
#include <Omega_PHH37.h>

Omega_PHH37 Meter = Omega_PHH37();

void setup()
{
  Meter.begin();
}

void loop()
{
  delay(2000);
  if(Meter.read()) {
    Serial.print("mV: ");
    Serial.println(Meter.mV());
  }
  else {
    Serial.println("could not get data");
  }
}
