#include "MIDIUSB.h"

// Single Button MIDI controller.
// This is great if you just want some simple MIDI controller foundation
// code, or if you only need one button. I built this as a PTT button 
// for SDR-Console.
//
// For this to work you need to use an Arduino with the atmega32u4 chip
// as it supports running the arduino as a native MIDI device.
// Simply wire a switch between pin 8 and GND, power it up and you'll
// have a MIDI device that sends a noteOn and noteOff with each keypress.

int buttonState = 0;  
int prevButtonState = 0;

void setup() {
  pinMode(8, INPUT_PULLUP);
}

void loop() {
  buttonState = digitalRead(8);

  if (buttonState != prevButtonState){
  
    if (buttonState == LOW) {
      noteOn(1, 47, 127);
    }else{
      noteOff(1, 47, 0);
    }
    MidiUSB.flush();
    prevButtonState = buttonState;
    delay(200);
  }
}

void noteOn(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
}

void noteOff(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
}

void controlChange(byte channel, byte control, byte value) {
  midiEventPacket_t event = {0x0B, 0xB0 | channel, control, value};
  MidiUSB.sendMIDI(event);
}
