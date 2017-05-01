#include <Wire.h>

#define ARD1_ADDR 0x04

String inString = "";
boolean isReceived = false;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin(ARD1_ADDR);

  Wire.onReceive(receiveData);

  Serial.println("Arduino 1 ready!");


}

void loop() {
  // put your main code here, to run repeatedly:

  if (isReceived) {
    Serial.print("String received: ");
    Serial.println(inString);
    isReceived = false;
    inString = "";
  }

  delay(100);
}

void receiveData(int byteCount) {

  int inChar;

  isReceived = false;

  while (Wire.available()) {
    inChar = Wire.read();
    inString += char(inChar);
  }

  isReceived = true;
}

