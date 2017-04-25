//colors: 'r' = red, 'b' = blue, 'g' = green
// 'w' = white, 'p' = purple

int red_cathode_pwm = 3;
int green_cathode_pwm = 5;
int blue_cathode_pwm = 6;

int red_analog = A5;
int green_analog = A6;
int blue_analog = A7;

char color;
int intensity = 50;
boolean ledEnable = false;

int red_pot_voltage;
int green_pot_voltage;
int blue_pot_voltage;

int red_intensity;
int green_intensity;
int blue_intensity;



void setup() {
  pinMode(red_cathode_pwm, OUTPUT);
  pinMode(green_cathode_pwm, OUTPUT);
  pinMode(blue_cathode_pwm, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    color = Serial.read();

    if (color == 'e') {
      ledEnable = true;
    } else if (color == 'd') {
      ledEnable = false;
    }
  }

  if (ledEnable) {
    controlLeds(color);
  } else {
    controlPots();
  }

}

void controlLeds (char col) {
  if (col == 'r') {
    analogWrite(red_cathode_pwm, intensity);
    analogWrite(green_cathode_pwm, 0);
    analogWrite(blue_cathode_pwm, 0);
  }
  else if (col == 'g') {
    analogWrite(red_cathode_pwm, 0);
    analogWrite(green_cathode_pwm, intensity);
    analogWrite(blue_cathode_pwm, 0);
  }
  else if (col == 'b') {
    analogWrite(red_cathode_pwm, 0);
    analogWrite(green_cathode_pwm, 0);
    analogWrite(blue_cathode_pwm, intensity);
  }
  else if (col == 'w') {
    analogWrite(red_cathode_pwm, intensity);
    analogWrite(green_cathode_pwm, intensity);
    analogWrite(blue_cathode_pwm, intensity);
  }
  else if (col == 'p') {
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

void controlPots() {
  red_pot_voltage = analogRead(red_analog);
  green_pot_voltage = analogRead(green_analog);
  blue_pot_voltage = analogRead(blue_analog);
  red_intensity = map(red_pot_voltage, 0, 1023, 0, 255);
  green_intensity = map(green_pot_voltage, 0, 1023, 0, 255);
  blue_intensity = map(blue_pot_voltage, 0, 1023, 0, 255);

  analogWrite(red_cathode_pwm, red_intensity);
  analogWrite(green_cathode_pwm, green_intensity);
  analogWrite(blue_cathode_pwm, blue_intensity);

  //Serial.print(red_intensity); Serial.print(" "); Serial.print(green_intensity); Serial.print(" "); Serial.println(blue_intensity);
  //delay(100);
}

