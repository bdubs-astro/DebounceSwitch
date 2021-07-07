/*
DebounceSwitch - a class for de-bouncing a mechanical switch

The parameters are the GPIO pin #, a debounce delay in ms, a flag that's true if using 
an external pullup resistor or false if using an internal pullup resistor, and a 
pair of callback functions that get called when the pin goes either high or low. 

The initPin() command configures the input pin, and returns the inital state of 
the switch. It must be called first.

The readPin(int swDelay) command returns the current state (de-bounced), and calls 
the corresponding callback function whenever the state changes.

Usage:
#include "DebounceSwitch.h"
const int swPin = 14;     // ESP8266 D5;
bool extPullup = true;
void loCallback();
void hiCallback();
DebounceSwitch mySwitch(swPin,extPullup,loCallback,hiCallback);

void setup() {
    bool swStateInit = mySwitch.initPin(); 
    const char *swStateStr[] = {"LOW", "HIGH"};
    Serial.printf("Initial switch state: %s.\n", swStateStr[swStateInit]);
}

void loop() {
    int swDelay = 100;  // debounce delay (ms)
    bool = mySwitch.readPin(int swDelay);
}

void loCallback() {
  Serial.printf("Switch just went LOW.\n");
}

void hiCallback() {
  Serial.printf("Switch just went HIGH.\n");
}

bdw 7-Jul-2021
*/

#ifndef DebounceSwitch_h
#define DebounceSwitch_h

#include "Arduino.h"

class DebounceSwitch {

public:
    DebounceSwitch(const int _pin,bool _extPullup,void (*_loCallback)(void),void (*_hiCallback)(void)) {
    
    pin = _pin;
    extPullup = _extPullup;
    loCallback = _loCallback;
    hiCallback = _hiCallback;
    
    // configure input pin
    if (extPullup)
        pinMode(pin,INPUT);       		  // requires external pullup resistor 
    else
        pinMode(pin,INPUT_PULLUP);    	// use internal pullup resistor
}

bool initPin();    
bool readPin(int debounceDelay); 
    
private:
    void (*loCallback)(void);
    void (*hiCallback)(void);
    int pin;
    bool extPullup;
    bool reading;
    bool currState;                       
    bool prevState;  
    unsigned long timePrev;                  
};

#endif
