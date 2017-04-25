#include <Servo.h>

Servo servoup;
Servo servodown;

int servopin_up = 10;
int servopin_down = 9;
int off_pos_up = 150; //angle when idle
int off_pos_down = 30;
int on_pos_up = 30; //angle when pushing button
int on_pos_down = 150;
int command = 0;
int amount = 0;
int switch_delay = 500;
int incoming = 0;
int amount1 = 0;
int i = 0;
int number = 0;

void setup() {
  servoup.attach(servopin_up);
  servoup.write(off_pos_up);
  servodown.attach(servopin_down);
  servodown.write(off_pos_down);
  Serial.begin(9600);
}

void loop() {
  i = 0;
    if (Serial.available() > 0) {
      i = 100;
      while (Serial.available() > 0) {
       // read the incoming byte:
       delay(10);
       number = Serial.read() - 48;
       incoming = incoming + i*number;
       Serial.print(i);
       Serial.print("_");
       Serial.println(incoming);
       i = i/10;
       // 1 to 127 means down, 128 to 255 means up
      }

//  while (Serial.available() > 0) {
//
//    String value = Serial.readString();
//
//    for (int i = value.length() - 1; i >= 0; i--) {
//      incoming += 10 * i * value[i];
//    }
//
//  }


  if (incoming > 127) {
    command = 1; //up
    amount1 = incoming - 127;
    amount = map(amount1, 0, 128, 0, 3000);
  }
  else if (incoming > 0) {
    command = -1; //down
    amount1 = incoming;
    amount = map(amount1, 0, 128, 0, 3000);
  }
  incoming = 0; //reset to zero to avoid repeat commands
  amount1 = 0;


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

