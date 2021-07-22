#include <Arduino.h>
#include "DebounceSwitch.h"

// I/O
#define swPin 14                // ESP8266 D5
#define intPullup false   
#ifndef LED_BUILTIN 
#define LED_BUILTIN 2           // ESP8266
#endif

// Switch stuff ...
int debounceDelay = 100;        // (ms)
void loCallback();
void hiCallback();
DebounceSwitch mySwitch(swPin, intPullup, loCallback, hiCallback);

void setup() {
  // establish serial comms ...
  Serial.begin(9600);
  while(!Serial) {;}                // wait for connection
  Serial.printf("\n\nSerial monitor connected to ESP8266.\n\n");

  // configure LED ...
  pinMode(LED_BUILTIN, OUTPUT); 

  // initialize switch ...
  bool swStateInit = mySwitch.initPin(); 
  const char *swStateStr[] = {"LOW", "HIGH"};
  Serial.printf("\tInitial switch state: %s.\n\n", swStateStr[swStateInit]); 
}

void loop() {
  bool swState = mySwitch.readPin(debounceDelay); 
}

// callback functions ...
void loCallback() {
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.printf("\tSwitch went LOW.\n\n"); 
}

void hiCallback() {
  digitalWrite(LED_BUILTIN, LOW);
  Serial.printf("\tSwitch went HIGH.\n\n");
}