int red_cathode_pwm = 3;
int green_cathode_pwm = 5;
int blue_cathode_pwm = 6;

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
    red_pot_voltage = analogRead(A0);
    green_pot_voltage = analogRead(A1);
    blue_pot_voltage = analogRead(A2);
    red_intensity = map(red_pot_voltage, 0, 1023, 0, 255);
    green_intensity = map(green_pot_voltage, 0, 1023, 0, 255);
    blue_intensity = map(blue_pot_voltage, 0, 1023, 0, 255);
    
    analogWrite(red_cathode_pwm, red_intensity);
    analogWrite(green_cathode_pwm, green_intensity);
    analogWrite(blue_cathode_pwm, blue_intensity);
}
