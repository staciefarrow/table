int motor_back_right_dir = 2;
int motor_back_right_pwm = 3;

int motor_back_left_dir = 4;
int motor_back_left_pwm = 5;

int motor_front_right_dir = 7;
int motor_front_right_pwm = 6;

int motor_front_left_dir = 8;
int motor_front_left_pwm = 9;

char dir;

int max_speed =255;
int speeds = 255; // set the speed of all motors (range 0-255)

void setup() {
    pinMode(motor_back_right_dir, OUTPUT);
    pinMode(motor_back_right_pwm , OUTPUT);
    
    pinMode(motor_back_left_dir , OUTPUT);
    pinMode(motor_back_left_pwm , OUTPUT);
    
    pinMode(motor_front_right_dir , OUTPUT);
    pinMode(motor_front_right_pwm , OUTPUT);
    
    pinMode(motor_front_left_pwm , OUTPUT);
    pinMode(motor_front_left_dir , OUTPUT);
    
    Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0){
    dir = Serial.read();
  }
    
    if (dir == 'f') { //forward
        analogWrite(motor_back_right_pwm, speeds);
        analogWrite(motor_back_left_pwm, speeds);
        analogWrite(motor_front_right_pwm, speeds);
        analogWrite(motor_front_left_pwm, speeds);    
        digitalWrite(motor_back_right_dir, HIGH);
        digitalWrite(motor_back_left_dir, LOW);
        digitalWrite(motor_front_right_dir, HIGH);
        digitalWrite(motor_front_left_dir, LOW);
    }
    else if (dir == 'b') { //backward
        analogWrite(motor_back_right_pwm, speeds);
        analogWrite(motor_back_left_pwm, speeds);
        analogWrite(motor_front_right_pwm, speeds);
        analogWrite(motor_front_left_pwm, speeds);
        digitalWrite(motor_back_right_dir, LOW);
        digitalWrite(motor_back_left_dir, HIGH);
        digitalWrite(motor_front_right_dir, LOW);
        digitalWrite(motor_front_left_dir, HIGH);
    }
    else if (dir == 'r') { //right
        analogWrite(motor_back_right_pwm, speeds);
        analogWrite(motor_back_left_pwm, speeds);
        analogWrite(motor_front_right_pwm, speeds);
        analogWrite(motor_front_left_pwm, speeds);
        digitalWrite(motor_back_right_dir, LOW);
        digitalWrite(motor_back_left_dir, LOW);
        digitalWrite(motor_front_right_dir, HIGH);
        digitalWrite(motor_front_left_dir, HIGH);
    }
    else if (dir == 'l') { //left
        analogWrite(motor_back_right_pwm, speeds);
        analogWrite(motor_back_left_pwm, speeds);
        analogWrite(motor_front_right_pwm, speeds);
        analogWrite(motor_front_left_pwm, speeds);
        digitalWrite(motor_back_right_dir, HIGH);
        digitalWrite(motor_back_left_dir, HIGH);
        digitalWrite(motor_front_right_dir, LOW);
        digitalWrite(motor_front_left_dir, LOW);
    }
    else if (dir == 'c') { //clockwise
        analogWrite(motor_back_right_pwm, speeds);
        analogWrite(motor_back_left_pwm, speeds);
        analogWrite(motor_front_right_pwm, speeds);
        analogWrite(motor_front_left_pwm, speeds);
        digitalWrite(motor_back_right_dir, LOW);
        digitalWrite(motor_back_left_dir, LOW);
        digitalWrite(motor_front_right_dir, LOW);
        digitalWrite(motor_front_left_dir, LOW);
    }
    else if (dir == 'o'){ //counterclockwise
        analogWrite(motor_back_right_pwm, speeds);
        analogWrite(motor_back_left_pwm, speeds);
        analogWrite(motor_front_right_pwm, speeds);
        analogWrite(motor_front_left_pwm, speeds);
        digitalWrite(motor_back_right_dir, HIGH);
        digitalWrite(motor_back_left_dir, HIGH);
        digitalWrite(motor_front_right_dir, HIGH);
        digitalWrite(motor_front_left_dir, HIGH);
    }
    else if (dir == 's') { //stop
        analogWrite(motor_back_right_pwm, 0);
        analogWrite(motor_back_left_pwm, 0);
        analogWrite(motor_front_right_pwm, 0);
        analogWrite(motor_front_left_pwm, 0);
    }
    else if (dir == '0') {
        speeds = max_speed * 1.0;
        set_all_motor_speeds(speeds);
    }
        else if (dir == '1') {
        speeds = max_speed * 0.1;
        set_all_motor_speeds(speeds);
    }
        else if (dir == '2') {
        speeds = max_speed * 0.2;
        set_all_motor_speeds(speeds);
    }
        else if (dir == '3') {
        speeds = max_speed * 0.3;
        set_all_motor_speeds(speeds);
    }
        else if (dir == '4') {
        speeds = max_speed * 0.4;
        set_all_motor_speeds(speeds);
    }
        else if (dir == '5') {
        speeds = max_speed * 0.5;
        set_all_motor_speeds(speeds);
    }
        else if (dir == '6') {
        speeds = max_speed * 0.6;
        set_all_motor_speeds(speeds);
    }
        else if (dir == '7') {
        speeds = max_speed * 0.7;
        set_all_motor_speeds(speeds);
    }
    else if (dir == '8') {
        speeds = max_speed * 0.8;
        set_all_motor_speeds(speeds);
    }
    else if (dir == '9') {
        speeds = max_speed * 0.9;
        set_all_motor_speeds(speeds);
    }
    else {
        analogWrite(motor_back_right_pwm, 0);
        analogWrite(motor_back_left_pwm, 0);
        analogWrite(motor_front_right_pwm, 0);
        analogWrite(motor_front_left_pwm, 0);
    }
}

void set_all_motor_speeds(int value) {
  analogWrite(motor_back_right_pwm, value);
  analogWrite(motor_back_left_pwm, value);
  analogWrite(motor_front_right_pwm, value);
  analogWrite(motor_front_left_pwm, value);
}
