#include <Servo.h> 

Servo servoup;
Servo servodown;

int servopin_up = 10;
int servopin_down = 9;
int off_pos_up = 30; //angle when idle
int off_pos_down = 30;
int on_pos_up = 50; //angle when pushing button
int on_pos_down = 50;
int command = 0;
int amount = 0;
int switch_delay = 500;
int incoming = 0; 
int amount1 = 0;
int i = 0;
int number = 0;
int ledPin[] = {4, 5, 6};

int ledOnTime = 200;
int ledOffTime = 200;

int ledState[] = {LOW,LOW,LOW};

unsigned long previousLedMillis = 0;
unsigned long previousServoMillis = 0;

void setup() {
  servoup.attach(servopin_up);
  servoup.write(off_pos_up);  
  servodown.attach(servopin_down);
  servodown.write(off_pos_down);
  Serial.begin(9600);

  for(int j = 0; j < 3; j++) {
    pinMode(ledPin[j], OUTPUT);
  }
  
}

void loop() {
 
  
  i = 0;
  if (Serial.available() > 0) {
    i = 1;
    while (Serial.available() > 0) {
     // read the incoming byte:
     number = Serial.read() - 48;
     incoming = incoming + i*number;
     Serial.print(i);
     Serial.print("_");
     Serial.println(incoming);
     i = i*10;
     // 1 to 127 means down, 128 to 255 means up
    }
  
      if (incoming > 127){
        command = 1; //up
        amount1 = incoming - 127;
        amount = map(amount1, 0, 128, 0, 3000);
      }
      else if (incoming > 0){
        command = -1; //down
        amount1 = incoming;
        amount = map(amount1, 0, 128, 0, 3000);
      }
    incoming = 0; //reset to zero to avoid repeat commands
    amount1 = 0;
    
  }

  unsigned long currentServoMillis = millis();
  
  if (command == 1){
    
    //delay(amount); //time to press button

    while(currentServoMillis - previousServoMillis <= amount) {
      servoup.write(on_pos_up);
      flashLeds();
      previousServoMillis = currentServoMillis;
      currentServoMillis = millis();
    }
      servoup.write(off_pos_up);
      delay(switch_delay);
      command = 0; //reset to zero
      amount = 0;
    
  }
  else if (command == -1) {
    while(currentServoMillis - previousServoMillis <= amount) {
      servoup.write(on_pos_down);
      flashLeds();
      previousServoMillis = currentServoMillis;
      currentServoMillis = millis();
    }
      servoup.write(off_pos_down);
      delay(switch_delay);
      command = 0; //reset to zero
      amount = 0;
  }

}

void flashLeds() {
  
      unsigned long currentLedMillis = millis();
    
    for(int j = 0; j < 3; j++){
      if((ledState[j] == HIGH) && (currentLedMillis-previousLedMillis >= ledOnTime)) {
        ledState[j] == LOW;
        previousLedMillis = currentLedMillis;
        digitalWrite(ledPin[j], ledState[j]);
      } else if ((ledState[j] == LOW) && (currentLedMillis-previousLedMillis >= ledOffTime)) {
        ledState[j] == HIGH;
        previousLedMillis = currentLedMillis;
        digitalWrite(ledPin[j], ledState[j]);
      }
    }
}

