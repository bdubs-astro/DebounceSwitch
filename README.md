<h1> DebounceSwitch </h1>

__A c++ class for de-bouncing a mechanical switch.__

- The required parameters are:
  - the GPIO input pin #
  - a flag that's true if using an internal pullup resistor, or false otherwise
  - a pair of callback functions that get called when the input pin goes either  low or high
  - a debounce delay in milliseconds

- The ```initPin()``` member function must be called first. It configures the input pin, and returns the inital state of 
the switch.

- The ```readPin(debounceDelay)``` member function returns the current state (de-bounced), and calls 
the appropriate callback function whenever the pin's state changes.

<h2> Sample Code:</h2>

```
#include <Arduino.h>
#include "DebounceSwitch.h"

#define DEVICE 0    // ! Arduino Nano Every = 0, ESP8266 = 1

// I/O ...
#if DEVICE == 0
// ? Arduino Nano Every
#define LED_BUILTIN 13          // ? built in LED on pin 13     
#define LED_ON HIGH             // ? active high
#define swPin 12                // ? Arduino Nano Every D12
#define intPullup true          // ? use internal pullup resistor?
#elif DEVICE == 1
// ? ESP8266
#define LED_BUILTIN 2           // ? built in LED on pin 2  
#define LED_ON LOW              // ? active low
#define swPin 13                // ? ESP8266 D7
#define intPullup false         // ? use internal pullup resistor?
#endif

#ifndef LED 
#define LED LED_BUILTIN          
#endif

// configure switch ...
void loCallback(), hiCallback();
DebounceSwitch mySwitch(swPin, intPullup, loCallback, hiCallback);

void setup() {
  // establish serial comms ...
  Serial.begin(115200);
  while(!Serial) {;}                // wait for connection
  delay(3000);                      // settling time
  Serial.println(); Serial.println("Serial monitor connected."); 
  Serial.println();

  // configure indicator LED ...
  pinMode(LED, OUTPUT); 

  // initialize switch ...
  bool swStateInit = mySwitch.initPin(); 
  digitalWrite(LED, swStateInit ? !LED_ON : LED_ON);  // ! active low

  const char *swStateStr[] = {"LOW", "HIGH"};
  Serial.print("Initial input state is ");
  Serial.print(swStateStr[swStateInit]);
  Serial.println("."); Serial.println();
}

void loop() {
  int debounceDelay = 50;           // (ms)
  mySwitch.readPin(debounceDelay); 
}

// callback functions ...
void loCallback() {
  digitalWrite(LED, LED_ON);                        // ! active low
  Serial.println("Input just went LOW."); Serial.println();
}

void hiCallback() {
  digitalWrite(LED, !LED_ON);                       // ! active low
  Serial.println("Input just went HIGH."); Serial.println();
}
```

<h2> Digital Inputs: Pullup vs. Pulldown Resistors </h2>

<img src = "./images for README/NO switch.png" width = "600"/> 

<img src = "./images for README/NC switch.png" width = "600"/> 


<h2>ESP8266 D1 Mini Pinout</h2>

<img src = "./images for README/WeMos D1 mini pinout.png" width = "800"/>

Source: https://www.mischianti.org/2021/04/26/wemos-d1-mini-high-resolution-pinout-and-specs/

<img src = "./images for README/WeMos D1 mini pins table.png" width = "600"/>

Source: https://randomnerdtutorials.com/esp8266-pinout-reference-gpios/


<h2>ESP32 Dev Kit C v4 Pinout</h2>

<img src = "./images for README/ESP32 pinout.png" width = "700"/>

Source: https://forum.fritzing.org/t/esp32s-hiletgo-dev-boad-with-pinout-template/5357

<img src = "./images for README/ESP32 LOLIN pinout.png" width="800"/>

Source: https://www.mischianti.org/2021/07/17/esp32-devkitc-v4-high-resolution-pinout-and-specs/


<h2>Arduino Nano Every Pinout</h2>

<img src = "./images for README/Arduino Nano Every pinout.png" width="800"/>

Source: https://docs.arduino.cc/hardware/nano-every/