********************************************************************************
Portable Climate Sensor<br/>
<p float="left">
<img src = "Project Photo/1.jpg" width = "200" height = "400" />
<img src = "Project Photo/2.jpg" width = "200" height = "400" />
<img src = "Project Photo/3.jpg" width = "200" height = "400" />
<img src = "Project Photo/4.jpg" width = "200" height = "400" />
<img src = "Project Photo/5.jpg" width = "200" height = "400" />
<img src = "Project Photo/6.jpg" width = "400" height = "400" />
</p>

Created by E-Protocol
https://github.com/e-protocol

Specs: Linux Debian x64, Qt 5.15.1, Arduino Nano

Description: 
This project is about portable device, which shows current temperature,
pressure and humidity by connecting Android phones via Bluetooth.
It also allows to scan for any bluetooth device within the range - 
Max 30 m on open space. Shows Low Energy Bluetooth devices by placing "LE" 
near device name. The Device is found as P-Climate Sensor. Pairing pin 4444.
Device can be charged fromg phone charger. Project includes some photos.
********************************************************************************

Arduino part

********************************************************************************

Components list:

1) Arduino Nano
2) BME 280 Sensor
3) DC-DC converter 0.9-5V Input 5V Output
4) TP4056 charge module for 18650 batteries
5) 2x 18650 battery 2400 mA
6) double battery holder
7) 3x little slot shields
8) USB-Micro port
9) 2x leds 3v
10) 2x Resistors 22 Ohm
11) couple of wires M-F for Arduino
12) 1x key buttton
13) 0.25mm wires
14) Bluetooth HC-06 module
15) plastic electrical box
16) some Solder and flux
17) some hot glue

Arduino programm(sketch):

1) Requires Arduino libraries: Adafruit_Sensor, Adafruit_BME280
2) Requires make settings of HC-06 Bluetooth module before uploading sketch, i.e. pin and device name setup.
Used pin in project 4444, device name P-Climate Sensor

