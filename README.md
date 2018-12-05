# button-box-keyboard

Arduino code for a simple keyboard with 3 buttons. 


## Required Hardware

WARNING: This code assumes the buttons are already perfectly debounced in hardware (with an RC filter and schmitt trigger), so it does not debounce in software. Don't try to use it with un-debounced buttons, or you'll see lots of short unintended presses!

* Teensy 3.2  (Teensy LC should work also)

* micro USB cable

* pushbuttons

* resistor and capacitor for RC filter (one for each pushbutton)

* schmitt trigger inverter (one channel for each pushbutton)


## Installing

You don't need to install anything to use the button-box as a keyboard. To upload new firmware, however, you will need to:

1. Install the [Arduino IDE](https://www.arduino.cc/en/Main/Software). You must install the offline IDE version, instead of using the online "Arduino Create" tool.

2. Install the [Teensyduino](https://www.pjrc.com/teensy/teensyduino.html) add-on to the Arduino IDE, to support the `Teensy3.2` board used in the button-box.


## Running

1. Connect the button-box to the computer with a USB cable, if it wasn't already plugged in.

2. Launch the Arduino IDE. 

3. Open the file `button-box-keyboard.ino`. 

4. In the menu bar, select `Tools -> Board: -> "Teensy 3.2/3.1"`. 

5. Select `Tools -> USB Type: -> "Serial + Keyboard + Mouse + Joystick"`.

6. Select `Tools -> CPU Speed: -> "72 MHz"`.

7. Go to `Tools -> Port` and select which port the button-box is connected to. The port name will vary, but might look something like `/dev/cu.usbmodem*` on a Mac, or `/dev/ttyACM*` in linux. You can check by unplugging the button-box and seeing which entry in the port list disappears.

8. Compile and upload the firmware by clicking the round arrow button, or by selecting `Sketch -> Upload` in the menu bar. Look for messages printed in the bottom part of the window. If the upload was successful, you can now use the reconfigured button-box. 
