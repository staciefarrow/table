//colors: 'r' = red, 'b' = blue, 'g' = green
// 'w' = white, 'p' = purple

int red_cathode_pwm = 3;
int green_cathode_pwm = 5;
int blue_cathode_pwm = 6;

int red_analog = A5;
int green_analog = A6;
int blue_analog = A7;

char color;
//int intensity = 50;
boolean ledEnable = true;

int red_pot_voltage;
int green_pot_voltage;
int blue_pot_voltage;

int red_intensity;
int green_intensity;
int blue_intensity;

String hexColor;



void setup() {
  pinMode(red_cathode_pwm, OUTPUT);
  pinMode(green_cathode_pwm, OUTPUT);
  pinMode(blue_cathode_pwm, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  while (Serial.available() > 0) {
    String reading = Serial.readString();

    if (reading == "e") {
      ledEnable = true;
    } else if (reading == "s") {
      ledEnable = false;
    } else {
      hexColor = reading;
    }
  }

  if (ledEnable) {
    controlLeds(color);
  } else {
    controlPots();
  }

}

void controlLeds (char col) {
  
  int red = hexToRGB(hexColor[0], hexColor[1]);
  int green = hexToRGB(hexColor[2], hexColor[3]);
  int blue = hexToRGB(hexColor[4], hexColor[5]);
  
  analogWrite(red_cathode_pwm, red);
  analogWrite(green_cathode_pwm, green);
  analogWrite(blue_cathode_pwm, blue);
  
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

int hexToDec(char hexChar) {
  if (hexChar < 58 && hexChar > 47) {
    return (hexChar - 48);
  } else if (hexChar < 103 && hexChar > 96) {
    return (hexChar - 87);
  } else {
    return 0;
  }
}

int hexToRGB(char hex1, char hex2) {
  return 16 * hexToDec(hex1) + hexToDec(hex2);
}

