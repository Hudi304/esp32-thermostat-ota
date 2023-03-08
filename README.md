# ESP32 Thermostat Ota

This project features the Back End (firmware) of an I.O.T. system that is able to controll any gas heater.

## UNIT TEST THE CODE ON THE BOARD (PlatformIO Test) BEFORE COMMITING CODE

## Features: 
- Serves a react app that consumes the API
- Exposes a number of endpoints that let the UI controll the system
- Exposes a webSocket that lets the UI update in real time
- Can be programmed over the air (OTA) [this way more then one device can be updated without needing phisical acces to it]
- Is resilient to IP changes (if the router assigns a different IP [when it resets for example] to the device it it stil accesible via an URL through mDNS)
- Meajures the ambient temperature every 5 seconds and starts teh heater or stops it ddepending on the settings
- Temperature controll hysteresis (uses the house itself as a thermal battery so that it reduces the wear on the heater)

## Planned features
- Switching from enbedding the web page files directly into the firmware (although a perfectly valid option in embedded) to writing the files directly to the flash memmory using S.P.I.F.F.S. [Serial Peripheral Interface Flash File System] - this should enable us to update the served Web App without reprogramming the microcontroller.
