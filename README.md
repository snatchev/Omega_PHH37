Arduino Omega PHH37 Library
===

This library communicates with the [Omega PHH-37 handheld pH meter](http://www.omega.com/pptst/PHH-37.html) over RS232

Features
---

Read realtime (~1 sec sampling rate) data from device

* pH
* mV
* temperature

Installation
---

Place the source in your [Arduino libraries folder](http://arduino.cc/en/Guide/Libraries)

MAX232 chip required for converting RS232 voltage to TTL.

![schematic](http://3.bp.blogspot.com/_xBOs6PWgasI/THnpcjC5zHI/AAAAAAAAAMw/xG8d9NQjHys/s1600/schematic+max232.gif)

Also, check the [tutorial how to use wire MAX232](http://arduino.cc/en/Tutorial/ArduinoSoftwareRS232).
The part about the software serial is out of date.

_NOTE_: connect the PHH37 Rx/Tx wires to pins 0, 1 on the Arduino UNO.
When uploading a new sketch, you must disconnect these two wires. Otherwise the sketch will not upload.

Currently, this library only supports using Serial on the UNO.

Examples
---

```arduino

#include <Omega_PHH37.h>

Omega_PHH37 Meter = Omega_PHH37();

void setup()
{
  Meter.begin();
}

void loop()
{
  delay(1000);
  if(Meter.read()) {
    Serial.print("mV: ");
    Serial.println(Meter.mV());
  }
  else {
    Serial.println("could not get data");
  }
}
```

Protocol
---


