/*
 By Robert Wilson
 17 July 2017
*/

const int DATA_Pin = 7;

void setup() 
{
  // initialize digital pins 12-13 as outputs and 11 as an input.
  pinMode(DATA_Pin, INPUT);    // Hall Efect Sensor
  pinMode(12, OUTPUT);         // Blue LED
  pinMode(13, OUTPUT);         // Yellow LED
    Serial.begin(9600);  // Init serial to 9600b/s
  
  digitalWrite(12, LOW);      // Initialize LEDs to off
  digitalWrite(13, LOW);      // Initialize LEDs to off
}

void loop() 
{
  // Cgecks hall sensor and responds with LED, this runs repeatedly:
  int SensorValue = digitalRead(DATA_Pin);
    
  if(SensorValue == 1)
  {
    Serial.println(SensorValue);
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
  }
  else
  {
   Serial.println(SensorValue); 
   digitalWrite(13, LOW);
   digitalWrite(12, HIGH);
  }
}
