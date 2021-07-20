<h1> DebounceSwitch </h1>

__A c++ class for de-bouncing a mechanical switch.__

The parameters are:
1. a GPIO pin #
2. a flag that's true if using an internal pullup resistor
3. a pair of callback functions that get called when the input pin goes either high or low
4. a debounce delay in milliseconds

:black_small_square: The ___initPin()___ function must be called first. It configures the input pin, and returns the inital state of 
the switch.

:black_small_square: The ___readPin(int debounceDelay)___ function returns the current state (de-bounced), and calls 
the corresponding callback function whenever the state changes.


<h2> Digital Inputs: Pullup vs. Pulldown Resistors </h2>

<img src = "https://user-images.githubusercontent.com/83251604/124932184-da160580-dfd0-11eb-92bd-8c26bc254a17.png" width = "700"/>


<h2>ESP8266 D1 Mini Pinout</h2>

<img src = "https://user-images.githubusercontent.com/83251604/124826307-af7d6b80-df42-11eb-8ce8-97c496b6cfc2.png" width = "800"/>

Source: https://www.mischianti.org/2021/04/26/wemos-d1-mini-high-resolution-pinout-and-specs/

<img src = "https://user-images.githubusercontent.com/83251604/124815934-e13c0580-df35-11eb-96e1-772857aab4bb.png" width = "600"/>

Source: https://randomnerdtutorials.com/esp8266-pinout-reference-gpios/

<h2>ESP32 Dev Kit C v4 Pinout</h2>

<img src = "https://user-images.githubusercontent.com/83251604/124827544-27986100-df44-11eb-92ff-94bd9abdaff3.png" width = "700"/>

Source: https://forum.fritzing.org/t/esp32s-hiletgo-dev-boad-with-pinout-template/5357

