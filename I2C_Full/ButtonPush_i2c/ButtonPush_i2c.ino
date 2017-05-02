#include <Servo.h>
#include<Wire.h>

#define ADDR 0x04

Servo servoup;
Servo servodown;

int servopin_up = 10;
int servopin_down = 9;
int off_pos_up = 180; //angle when idle
int off_pos_down = 0;
int on_pos_up = 50; //angle when pushing button
int on_pos_down = 130;
int command = 0;
int amount = 0;
int switch_delay = 500;
int incoming = 0;
int amount1 = 0;
int number = 0;
String value;

String inString = "";
boolean isReceived = false;

void setup() {
  servoup.attach(servopin_up);
  servoup.write(off_pos_up);
  servodown.attach(servopin_down);
  servodown.write(off_pos_down);

  Serial.begin(9600);
  Wire.begin(ADDR);

  Wire.onReceive(receiveData);
  Serial.println("Arduino 1 ready!");
}

void loop() {


  if (isReceived) {
    Serial.print("String received: ");
    Serial.println(inString);
    isReceived = false;
  }

  int maxIndex = inString[0]-48;

  for (int i = maxIndex-2; i >= 0; i--) {
    incoming += pow(10, i) * (inString[maxIndex - i]-48);
  }

  if (inString[1] == 'd' && incoming < 48) {
    command = 1; //up
  }
  else if (inString[1] == 'u' && incoming < 48) {
    command = -1; //down
  } 


  amount = map(incoming, 0, 48, 0, 17000);
  incoming = 0; //reset to zero to avoid repeat commands
  //}

  if (command == 1) {
    servoup.write(on_pos_up);
    delay(amount); //time to press button

    servoup.write(off_pos_up);
    delay(switch_delay);
    command = 0; //reset to zero
    amount = 0;

  }
  else if (command == -1) {
    servodown.write(on_pos_down);
    delay(amount);
    servodown.write(off_pos_down);
    delay(switch_delay);
    command = 0;
    amount = 0;
  }

  inString = "";
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
