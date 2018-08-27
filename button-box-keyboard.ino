#include <Arduino.h>
#include "Report.h"

// WARNING: This code assumes the buttons are already perfectly debounced in
// hardware (with an RC filter and schmitt trigger), so it does not debounce in
// software. Don't try to use it with un-debounced buttons, or you'll see lots
// of short unintended presses!

#define NUM_BUTTONS 3

// The KEY_* scancodes are defined in the teensyduino keyboard library. For the
// full list, see https://www.pjrc.com/teensy/td_keyboard.html. For some reason
// they are longer than a byte, even though we only care about the least
// significant byte, so we have to mask them with 0xFF before storing them as
// a uint8_t.
uint8_t keys[NUM_BUTTONS] = {KEY_1&0xFF, KEY_2&0xFF, KEY_3&0xFF};

// Pin numbers the buttons are attached to.
uint8_t pins[NUM_BUTTONS] = {14, 12, 11};

// The previous state of each button.
bool was_down[NUM_BUTTONS] = {0};

// Uncomment to print useful debug messages.
// #define DEBUG

void setup() {

#ifdef DEBUG
  Serial.begin(115200);
#endif

  for(uint8_t i = 0; i < NUM_BUTTONS; i++)  {
    // No pullup needed, schmitt trigger output is not open-drain.
    pinMode(pins[i], INPUT);
  }
}


void loop() {

  Report report;
  if (readyToSend(&report)) {
    report.send();

#ifdef DEBUG
    report.printDebug();
#endif
  }

  // Sleep, in milliseconds. Sending only takes ~0.5 microseconds, so we don't
  // need to account for that in the sleep time.
  delay(1);
}


bool readyToSend(Report* report) {
  bool something_changed = 0;
  for(uint8_t i = 0; i < NUM_BUTTONS; i++) {
    bool is_down = isDown(i);
    if (is_down != was_down[i]) {
        // New press or release!
        something_changed = 1;
    }
    if (is_down){
      // Include it in the report, although we won't bother to send the report
      // unless at least one button changed state since last time.
      report->addKey(keys[i]);
    }
    was_down[i] = is_down;
  }
  return something_changed;
}


bool isDown(uint8_t button_index) {
  return digitalRead(pins[button_index]) == HIGH;
}
