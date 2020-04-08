# Single Button MIDI controller.
A bare bones Arduino ATmega32U4 MIDI implementation with one button.

This is great if you just want some simple MIDI controller foundation
code, or if you only need one button. I built this as a PTT button 
for SDR-Console for QO-100.

For this to work you need to use an Arduino with the atmega32u4 chip
as it supports running the arduino as a native MIDI device.
Simply wire a switch between pin 8 and GND, power it up and you'll
have a MIDI device that sends a noteOn and noteOff with each keypress.
