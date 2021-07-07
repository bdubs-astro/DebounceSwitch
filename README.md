# DebounceSwitch

A class for de-bouncing a mechanical switch.

The parameters are the GPIO pin #, a debounce delay in milliseconds, a flag that's true if using 
an external pullup resistor or false if using an internal pullup resistor, and a 
pair of callback functions that get called when the pin goes either high or low. 

The initPin() command must be called first. It configures the input pin, and returns the inital state of 
the switch.

The readPin(int swDelay) command returns the current state (de-bounced), and calls 
the cooresponding callback function whenever the state changes.



![image](https://user-images.githubusercontent.com/83251604/124815881-cbc6db80-df35-11eb-852c-f5a654f3ed44.png)

![image](https://user-images.githubusercontent.com/83251604/124815934-e13c0580-df35-11eb-96e1-772857aab4bb.png)
https://randomnerdtutorials.com/esp8266-pinout-reference-gpios/

