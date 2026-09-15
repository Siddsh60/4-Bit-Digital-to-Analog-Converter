// 4-Bit R-2R Ladder DAC — Arduino Firmware
// Steps through all 16 input combinations to generate a staircase waveform,
// then reads the resulting analog voltage back via A0 for verification.

const int dacPins[4] = {2, 3, 4, 5}; // LSB -> MSB
int delayTime = 1;                    // ms between steps (controls frequency)
float Vref = 5;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 4; i++) {
    pinMode(dacPins[i], OUTPUT);
  }
}

void writeDAC(byte value) {
  for (int i = 0; i < 4; i++) {
    digitalWrite(dacPins[i], (value >> i) & 0x01);
  }
}

void loop() {
  // Rising staircase: 0 -> 15
  for (byte i = 0; i < 16; i++) {
    writeDAC(i);
    delay(delayTime);
    float voltage = analogRead(A0) * (Vref / 1023.0);
    Serial.println(voltage);
  }

  // Falling staircase: 15 -> 1
  for (byte i = 15; i > 0; i--) {
    writeDAC(i);
    delay(delayTime);
    float voltage = analogRead(A0) * (Vref / 1023.0);
    Serial.println(voltage);
  }
}
