/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/USER/Desktop/lab13/src/lab13.ino"
void isr();
void setup();
void printToDisplay(String output);
void loop();
#line 1 "c:/Users/USER/Desktop/lab13/src/lab13.ino"
SYSTEM_THREAD(ENABLED);
#include <Wire.h>
#include "oled-wing-adafruit.h"
#include <blynk.h>

volatile bool interruptOccured = false;
OledWingAdafruit display;
int counter = 0;

void isr() {
  interruptOccured = !interruptOccured;
}


void setup() {
  Serial.begin(9600);
  
  display.setup();
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Trail");
  display.display();

  attachInterrupt(D7, isr, FALLING); 
  interrupts();

  pinMode(D6, INPUT);
  pinMode(D7, INPUT_PULLUP);
}

void printToDisplay(String output)
{
  //reset display
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);

      //output to display
  display.println(output);
  display.display();
}

void loop() {
  display.loop();

  if (digitalRead(D6) == 1 && !interruptOccured)
  {
    counter += 1;
  }

  Serial.println(digitalRead(D6));
  Serial.println(digitalRead(D7));

  printToDisplay((String) counter);

}