//#define num_sensors 2
const float volt_sensor_const = 5.0/1024;
float R1 = 30000.0;
float R2 = 7500.0;
const float v_ref = 5.0;

float readVoltage(int vpin){
  int adc_val = analogRead(vpin);
  float volts = 1.0 * adc_val * volt_sensor_const / (R2 / (R1 + R2));
  return volts;
}
