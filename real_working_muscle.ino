/*
  ReadAnalogVoltage
  Reads an analog input on pin 0, converts it to voltage, and prints the result to the serial monitor.
  Graphical representation is available using serial plotter (Tools > Serial Plotter menu)
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.
  This example code is in the public domain.
*/
  int start_time = millis();
  int num_blinks = 0;

void vibrate_and_light(){
  digitalWrite(7, HIGH);
  digitalWrite(3, HIGH);
  delay(3000);
  digitalWrite(7, LOW);
  digitalWrite(3, LOW);
  delay(3000);
  vibrate_and_light();
}

// the setup routine runs once when you press reset:
void setup() {
   pinMode(7, OUTPUT);
   pinMode(3, OUTPUT);
   vibrate_and_light();
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  //vibrate_and_light();
  // read the input on analog pin 0:
  int sensorValue = analogRead(A5);
  Serial.println(sensorValue);
  if (millis() >= start_time + 3000){
      num_blinks = 0;
    }
  if (sensorValue >= 30){
    if (num_blinks == 0){
      start_time = millis();
    }
    num_blinks++;
    if (num_blinks >= 3){
      vibrate_and_light();
    }
  }
  
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  //threshold: 60 on the raw sensor value
  // if it hits this 3 times in 5 seconds, turn on lights and vibration
}
