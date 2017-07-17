/*
 By Robert Wilson
 17 July 2017
  Test Program for running the motor
*/
  // Set the LED outputs
    const int Red_LED = 11;       // Set Red LED to port Red_LED
    const int Blue_LED = 12;      // Set Blue LED to port Blue_LED
    const int Yellow_LED = 13;    // Set Yellow LED to port Yellow_LED
  // Set the Sensor Inputs
    const int Phase_1 = 4;        // First Phase Hall Effect Sensor tied to port D-4
    const int Phase_2 = 5;        // Second Phase Hall Effect Sensor tied to port D-5
    const int Phase_3 = 6;        // Third Phase Hall Effect Sensor tied to port D-6
    
void setup() 
{
  // Initialize all components, to run once:
    pinMode(Red_LED, OUTPUT);        // Initialize Red LED
    pinMode(Blue_LED, OUTPUT);       // Initialize Blue LED
    pinMode(Yellow_LED, OUTPUT);     // Initialize Yellow LED

    pinMode(Phase_1, INPUT);         // Initialize First Phase Hall Sensor
    pinMode(Phase_2, INPUT);         // Initialize Second Phase Hall Sensor
    pinMode(Phase_3, INPUT);         // Initialize Thrird Phase Hall Sensor
      Serial.begin(9600);            // Initialize Serial to 9600 b/s
    
  // Set the LED's to off initially 
    digitalWrite(Red_LED, LOW);
    digitalWrite(Blue_LED, LOW);
    digitalWrite(Yellow_LED, LOW);
}

// This runs repeatedly:
void loop()
{  
  // Set the Sensor Values
    int SensorValue_1 = digitalRead(Phase_1);
    int SensorValue_2 = digitalRead(Phase_2);
    int SensorValue_3 = digitalRead(Phase_3);
    
  // If Statement to determine Which Phase is run
    if(SensorValue_1 == 0)
    {
      Serial.println(SensorValue_1);
      Serial.println(SensorValue_2);
      Serial.println(SensorValue_3);
      
      // Set the Yellow and Blue LED's to off and Red to on if third Sensor is tripped
        digitalWrite(Red_LED, HIGH);
        digitalWrite(Blue_LED, LOW);
        digitalWrite(Yellow_LED, LOW);
    }
    else if(SensorValue_2 == 1)
    {
      Serial.println(SensorValue_1);
      Serial.println(SensorValue_2);
      Serial.println(SensorValue_3);
      
      // Set the Red and Yellow LED's to off and Blue to on if third Sensor is tripped
        digitalWrite(Red_LED, LOW);
        digitalWrite(Blue_LED, HIGH);
        digitalWrite(Yellow_LED, LOW);
    }
    else if(SensorValue_3 == 1)
    {
      Serial.println(SensorValue_1);
      Serial.println(SensorValue_2);
      Serial.println(SensorValue_3);
      
      // Set the Red and Blue LED's to off and Yellow to on if third Sensor is tripped
        digitalWrite(Red_LED, LOW);
        digitalWrite(Blue_LED, LOW);
        digitalWrite(Yellow_LED, HIGH);
    }
    else
    {
      Serial.println(SensorValue_1);
      Serial.println(SensorValue_2);
      Serial.println(SensorValue_3);
      
      // Set the LED's to off if no Sensor is tripped
        digitalWrite(Red_LED, LOW);
        digitalWrite(Blue_LED, LOW);
        digitalWrite(Yellow_LED, LOW);
    }
}
