
void setup() {
  // Set pins 2 to 6 as OUTPUT
  for (int i = 2; i<=6; i++){
    pinMode(i, OUTPUT);
    digitalWrite(i,HIGH);
  }

  for (int analogPin = A0; analogPin <= A10; analogPin++) {
    pinMode(analogPin, INPUT);
  }

}

void loop() {
  int voltage = 12;
  int powerValues[9];

  float voltage1 = readVoltage(A9);
  float voltage2 = readVoltage(A10);

  for (int currentAnalogPin = A0; currentAnalogPin <= A8; currentAnalogPin++) {
    float current = currentRead(currentAnalogPin);
    if (currentAnalogPin == A0){
      voltage = voltage1;
    }
    else if (currentAnalogPin == A1){
      voltage = voltage2;
    }

    powerValues[currentAnalogPin - A0] = int(current*voltage*10);
  }

}