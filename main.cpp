#include <Arduino.h>
#include "DebounceSwitch.h"

// I/O ...
#define swPin 14                // ESP8266 D5
#define intPullup false         // use internal pullup resistor?
int debounceDelay = 100;        // (ms)
void loCallback(), hiCallback();
DebounceSwitch mySwitch(swPin, intPullup, loCallback, hiCallback);
#ifndef LED_BUILTIN 
#define LED_BUILTIN 2           // ESP8266
#endif

void setup() {
  // establish serial comms ...
  Serial.begin(9600);
  while(!Serial) {;}                // wait for connection
  Serial.printf("\n\nSerial monitor connected.\n\n");

  // configure indicator LED ...
  pinMode(LED_BUILTIN, OUTPUT); 

  // initialize switch ...
  bool swStateInit = mySwitch.initPin(); 
  digitalWrite(LED_BUILTIN, !swStateInit);    // ESP8266 built-in LED is active LOW
  
  const char *swStateStr[] = {"LOW", "HIGH"};
  Serial.printf("\tInitial input state is %s.\n\n", swStateStr[swStateInit]); 
}

void loop() {
  bool swState = mySwitch.readPin(debounceDelay); 
}

// callback functions ...
void loCallback() {
  digitalWrite(LED_BUILTIN, !LOW);          // ESP8266 built-in LED is active LOW
  Serial.printf("\tInput just went LOW.\n\n"); 
}

void hiCallback() {
  digitalWrite(LED_BUILTIN, !HIGH);         // ESP8266 built-in LED is active LOW
  Serial.printf("\tInput just went HIGH.\n\n");
}
