#include "Report.h"

/// Add this key to the report.
/// The scancode is the value of the teensy keyboard library's KEY_A etc constants.
void Report::addKey(uint8_t scancode){
  if(scancode == 0){
    return;
  }
  if(isFull()){
    // Serial.println("WARNING: Report is full, key dropped.");
    return;
  }
  key_codes[num_keys] = scancode;
  num_keys++;
}

/// Add this modifier to the report.
void Report::addMod(uint8_t _mod_byte){
  // We can always add to the mod_byte, even though we can only fit 6 key_codes
  mod_byte = mod_byte | _mod_byte;
}

/// Return true if no more keys can be added to the report.
bool Report::isFull() const{
  return num_keys >= NUM_KEYS_IN_REPORT;
}

void Report::clear(){
  for(uint8_t i = 0; i < NUM_KEYS_IN_REPORT; i++) {
    key_codes[i] = 0;
  }
  mod_byte = 0;
  num_keys = 0;
}

void Report::printDebug() const{
  Serial.print("sending keys: ");
  for(uint8_t i = 0; i < NUM_KEYS_IN_REPORT; i++){
    Serial.print(key_codes[i]);
    Serial.print(" ");
  }
  Serial.print(", mod: ");
  Serial.println(mod_byte);
}

/// Send the report to the host computer, so the keys will be typed.
void Report::send() {
    Keyboard.set_key1(key_codes[0]);
    Keyboard.set_key2(key_codes[1]);
    Keyboard.set_key3(key_codes[2]);
    Keyboard.set_key4(key_codes[3]);
    Keyboard.set_key5(key_codes[4]);
    Keyboard.set_key6(key_codes[5]);
    Keyboard.set_modifier(mod_byte);
    Keyboard.send_now();
}
