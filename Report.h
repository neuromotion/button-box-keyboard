#ifndef REPORT_H_
#define REPORT_H_

#include "Arduino.h"

// This stores the modifiers and up to 6 keys included in one USB HID report. It
// can send itself to the host computer.

class Report {
 public:
  Report();
  void addKey(uint8_t scancode);
  void addMod(uint8_t _mod_byte);
  bool isFull() const;
  void clear();
  void printDebug() const;
  void send();

 private:
  uint8_t key_codes[6] = {0};
  uint8_t mod_byte = 0;
  uint8_t num_keys = 0;
};

#endif
