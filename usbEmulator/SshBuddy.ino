#include "Keyboard.h"

#define LED_PIN LED_BUILTIN

void setup() {
  // Initialize LED
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);
  
  // Wait for computer to recognize USB device
  delay(2000);
  
  // Start USB keyboard emulation
  Keyboard.begin();
  delay(500);
  
  // Open Run dialog: Windows Key + R
  Keyboard.press(KEY_LEFT_GUI);  // Windows key
  Keyboard.press('r');
  delay(100);
  Keyboard.releaseAll();
  delay(500);  // Wait for Run dialog to appear
  
  // Type dashboard URL
  Keyboard.print("https://node2.tasdidnoor.com");
  delay(200);
  
  // Press Enter to launch browser
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();
  
  // Blink LED to confirm completion
  digitalWrite(LED_PIN, LOW);
  delay(500);
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  // Nothing needed - one-time action
}