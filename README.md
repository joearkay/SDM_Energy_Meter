# Template library for reading SDM120 / SDM220 / SDM630 Modbus Energy meters.


## Updated codebase by JRK to demonstrate usage on an Arduino Uno. 

**Master Branch:**
Original codebase modified and updated to work on the Arduino Microcontroller Platform (tested on Arduino Uno).
This includes `SDM_Energy_Meter\examples\sdm_simple` which is an example that demonstrates the reading of all variables from a SDM120 device. For wiring diagram, please see the `Arduino_Wiring_Diagram_SDM120.jpg` in the main folder. 

**Particle Branch (The one you are on now):**
Codebase developed for Particle Electron/Photon, ported from Arduino modified codebase (from original). For a wiring diagram, please see the `Particle_Wiring_Diagram_SDM120.jpg` in the main folder. 

### Original readme.md from contributor (Reaper7):


Reading via Hardware Serial or Software Serial (library https://github.com/plerup/espsoftwareserial)<br>
and rs232<->rs485 converter with automatic flow direction control (look at hardware_sdm220.jpg)<br>
or with converters with additional pins for flow control, like MAX485.<br>
(In this case MAX485 DE and RE pins must be connected together to one of esp pin and this pin must be passed when initializing the library)
```
//lib init when Software Serial is used:
#include <SDM.h>
SDM<4800, 13, 15, 12> sdm;  //baudrate, rx pin, tx pin, dere pin(optional for max485)

//lib init when Hardware Serial is used:
#define USE_HARDWARESERIAL
#include <SDM.h>
SDM<4800, 12, false> sdm;  //baudrate, dere pin(optional for max485), swap hw serial pins from 3/1 to 13/15 
```

Tested on wemos d1 mini->ESP8266 with Arduino 1.8.3 & 2.3.0 esp8266 core

crc calculation by Jaime García (https://github.com/peninquen/Modbus-Energy-Monitor-Arduino/)

UPDATE:<br>
- (31.10.2016) new registers for SDM120 and SDM630 by beireken (https://github.com/beireken/SDM220t)

2016 - 2017 Reaper7

[paypal.me/reaper7md](https://www.paypal.me/reaper7md)