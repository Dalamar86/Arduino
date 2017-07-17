/*
 By Robert Wilson
 17 July 2017
 */


const int ButtonPin = 7;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pins 12-13 as outputs and 11 as input.
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(ButtonPin, INPUT);
   Serial.begin(9600);  //init serial to 9600b/s  
}

// the loop function runs over and over again forever
void loop() {
  int sensorValue = digitalRead(ButtonPin);
  
  if(sensorValue ==0)
  {
    Serial.println(sensorValue);  //Print High upon detection of magnetic field
    
    digitalWrite(12, LOW);      // Initialize LEDs to off
    digitalWrite(13, LOW);      // Initialize LEDs to off
    
    digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(200);              // wait for 2/10 a second
    digitalWrite(12, LOW);    // turn the LED off by making the voltage LOW
    delay(200);              // wait for 2/10 a second 
  
    digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(200);              // wait for 2/10 a second
    digitalWrite(12, LOW);    // turn the LED off by making the voltage LOW
    delay(200);              // wait for 2/10 a second
  
    digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(200);              // wait for 2/10 a second
    digitalWrite(12, LOW);    // turn the LED off by making the voltage LOW
    delay(200);              // wait for 2/10 a second
  
    digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(700);              // wait for 7/10 a second
    digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
    delay(200);              // wait for 2/10 a second
  
    digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(700);              // wait for 7/10 a second
    digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
    delay(200);              // wait for 2/10 a second
  
    digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(700);              // wait for 7/10 a second
    digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
    delay(200);              // wait for 2/10 a second
  
       digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(200);              // wait for 2/10 a second
    digitalWrite(12, LOW);    // turn the LED off by making the voltage LOW
    delay(200);              // wait for 2/10 a second 
  
    digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(200);              // wait for a second
    digitalWrite(12, LOW);    // turn the LED off by making the voltage LOW
    delay(200);              // wait for 2/10 a second
  
    digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(200);              // wait for 2/10 a second
    digitalWrite(12, LOW);    // turn the LED off by making the voltage LOW
    delay(500);              // wait for half a second
  }
  else
  {
   Serial.println(sensorValue);   //Print Low when no magnetic field is detected
   digitalWrite(13, LOW);  // turn the LED on  (HIGH is the voltage level)
   digitalWrite(12, LOW);  // turn the LED on  (HIGH is the voltage level)
  }  
}
