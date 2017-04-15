//colors: 'r' = red, 'b' = blue, 'g' = green
// 'w' = white, 'p' = purple

int red_cathode_pwm = 3;
int green_cathode_pwm = 5;
int blue_cathode_pwm = 6;
char color;
int intensity = 50;

void setup() {
    pinMode(red_cathode_pwm, OUTPUT);
    pinMode(green_cathode_pwm, OUTPUT);
    pinMode(blue_cathode_pwm, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    if (Serial.available() > 0) {
        color = Serial.read();
    }
        
    if (color == 'r') {
        analogWrite(red_cathode_pwm, intensity);
        analogWrite(green_cathode_pwm, 0);
        analogWrite(blue_cathode_pwm, 0);
    }
    else if (color == 'g') {
        analogWrite(red_cathode_pwm, 0);
        analogWrite(green_cathode_pwm, intensity);
        analogWrite(blue_cathode_pwm, 0);
    }
    else if (color == 'b') {
        analogWrite(red_cathode_pwm, 0);
        analogWrite(green_cathode_pwm, 0);
        analogWrite(blue_cathode_pwm, intensity);
    }
    else if (color == 'w') {
        analogWrite(red_cathode_pwm, intensity);
        analogWrite(green_cathode_pwm, intensity);
        analogWrite(blue_cathode_pwm, intensity);
    }
    else if (color == 'p') {
        analogWrite(red_cathode_pwm, intensity);
        analogWrite(green_cathode_pwm, 0);
        analogWrite(blue_cathode_pwm, intensity);
    }
    else {
        analogWrite(red_cathode_pwm, 0);
        analogWrite(green_cathode_pwm, 0);
        analogWrite(blue_cathode_pwm, 0);
    }
}
