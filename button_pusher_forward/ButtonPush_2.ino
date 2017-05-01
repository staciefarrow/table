#include <Servo.h>

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
//int i = 0;
int number = 0;
String value;

void setup() {
  servoup.attach(servopin_up);
  servoup.write(off_pos_up);
  servodown.attach(servopin_down);
  servodown.write(off_pos_down);
  Serial.begin(9600);
}

void loop() {
  //  i = 0;
  if (Serial.available() > 0) {

    while (Serial.available() > 0) {

      value = Serial.readString();
      int maxIndex = value.length() - 1;

      for (int i = maxIndex - 1; i >= 0; i--) {
        incoming += pow(10, i) * (value[maxIndex - i]-48);
      }
    }


    if (value[0] == 'd' && incoming < 48) {
      command = 1; //up
    }
    else if (value[0] == 'u' && incoming < 48) {
      command = -1; //down
    } 
    else {
      Serial.println("Please enter a direction (u for up, d for down) followed by a value between 0 and 48 cm");
    }
    
    amount = map(incoming, 0, 48, 0, 17000);
    incoming = 0; //reset to zero to avoid repeat commands
  }

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

}

