# DebounceSwitch

A c++ class for de-bouncing a mechanical switch.

The parameters are the GPIO pin #, a flag that's true if using an internal pullup 
resistor, a pair of callback functions that get called when the pin goes either high 
or low, and a debounce delay in ms. 

The initPin() command must be called first. It configures the input pin, and returns the inital state of 
the switch.

The readPin(int debounceDelay) command returns the current state (de-bounced), and calls 
the corresponding callback function whenever the state changes.

![image](https://user-images.githubusercontent.com/83251604/124835632-a2b34480-df4f-11eb-8c24-43cae28c3d74.png)

# ESP8266 D1 Mini

![image](https://user-images.githubusercontent.com/83251604/124826307-af7d6b80-df42-11eb-8ce8-97c496b6cfc2.png)
Source: https://www.mischianti.org/2021/04/26/wemos-d1-mini-high-resolution-pinout-and-specs/

![image](https://user-images.githubusercontent.com/83251604/124815934-e13c0580-df35-11eb-96e1-772857aab4bb.png)

Source: https://randomnerdtutorials.com/esp8266-pinout-reference-gpios/

# ESP32 Dev Kit
![image](https://user-images.githubusercontent.com/83251604/124827544-27986100-df44-11eb-92ff-94bd9abdaff3.png)

Source: https://forum.fritzing.org/t/esp32s-hiletgo-dev-boad-with-pinout-template/5357

