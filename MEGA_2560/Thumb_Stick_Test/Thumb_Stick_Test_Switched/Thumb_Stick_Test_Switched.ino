/*
 By Robert Wilson
 17 July 2017
*/

const int Switch_SPST = 25;
const int Switch_12V = 45;
const int Switch_LED = 50;
const int Key = 30;
const int Blue_LED = 12;
const int Red_LED = 13;
const int Yellow_LED = 11;
const int Green_LED = 10;
const int Thumb_Stick = A0;
const int Thumb_Stick_2 = A1;
#include "Mouse"


const int xAxis = A0;         //analog sensor for X axis  
const int yAxis = A1;         // analog sensor for Y axis

int range = 12;               // output range of X or Y movement
int responseDelay = 2;       // response delay of the mouse, in ms
int threshold = range/4;      // resting threshold
int center = range/2;         // resting position value
int minima[] = { 
  1023, 1023};                // actual analogRead minima for {x, y}
int maxima[] = {
  0,0};                       // actual analogRead maxima for {x, y}
int axis[] = {
  xAxis, yAxis};              // pin numbers for {x, y}
int mouseReading[2];          // final mouse readings for {x, y}


void setup() {
  // 
  pinMode(Switch_SPST, INPUT);
  pinMode(Switch_LED, INPUT);
  pinMode(Switch_12V, INPUT);
  pinMode(Thumb_Stick, INPUT);
   pinMode(Thumb_Stick_2, INPUT);
  pinMode(Key, INPUT);
  pinMode(Red_LED, OUTPUT);
  pinMode(Blue_LED, OUTPUT);
  pinMode(Yellow_LED, OUTPUT);
  pinMode(Green_LED, OUTPUT);
  
   Serial.begin(9600); //init serial to 9600b/s
  digitalWrite(Red_LED, LOW);
  digitalWrite(Blue_LED, LOW);
  digitalWrite(Yellow_LED, LOW);
  digitalWrite(Green_LED, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  int Switch_LED_Value = digitalRead(Switch_LED);
  int Switch_SPST_Value = digitalRead(Switch_SPST);
  int Key_Value = digitalRead(Key);
  if(Key_Value)
  {
    if((Switch_LED_Value == 1) && (Switch_SPST_Value == 1))
    {
      digitalWrite(Blue_LED, LOW);
      digitalWrite(Yellow_LED, LOW);
      digitalWrite(Green_LED, HIGH);
      digitalWrite(Red_LED, LOW); 
    }
    else if(Switch_LED_Value)
    {
      digitalWrite(Blue_LED, HIGH);
      digitalWrite(Yellow_LED, LOW);
      digitalWrite(Green_LED, LOW);
      digitalWrite(Red_LED, LOW);
    }
    else if(Switch_SPST_Value)
    {
      digitalWrite(Blue_LED, LOW);
      digitalWrite(Yellow_LED, HIGH);
      digitalWrite(Green_LED, LOW);
      digitalWrite(Red_LED, LOW);
    }
    else
    {
      digitalWrite(Blue_LED, LOW);
      digitalWrite(Yellow_LED, LOW);
      digitalWrite(Green_LED, LOW);
      digitalWrite(Red_LED, HIGH);
    }
  }
  else
  {
    digitalWrite(Blue_LED, LOW);
    digitalWrite(Yellow_LED, LOW);
    digitalWrite(Green_LED, LOW);
    digitalWrite(Red_LED, LOW);
  }
  int Switch_12V_Value = digitalRead(Switch_12V);
  int Thumb_Stick_Value = analogRead(Thumb_Stick);
  int Thumb_Stick_2_Value = analogRead(Thumb_Stick_2);
  
  Serial.print("Thumb 1:  ");
  Serial.println(Thumb_Stick_Value);
  delay(200);
  
  Serial.print("Thumb 2:  ");
  Serial.println(Thumb_Stick_2_Value);
  delay(1000);
  
  
  
  if(Switch_12V_Value)
  {
    Mouse.begin();
    if(Thumb_Stick_Value == HIGH)
    {
      Mouse.click();
    }
    else
    {
      // read and scale the two axes:
  int xReading = readAxis(0);
  int yReading = readAxis(1);

// move the mouse:
    Mouse.move(xReading, yReading, 0);
    delay(responseDelay);
    }
  }
}


/*
  reads an axis (0 or 1 for x or y) and scales the 
  analog input range to a range from 0 to <range>
*/

int readAxis(int axisNumber) {
  int distance = 0;    // distance from center of the output range

  // read the analog input:
  int reading = analogRead(axis[axisNumber]);

// of the current reading exceeds the max or min for this axis,
// reset the max or min:
  if (reading < minima[axisNumber]) {
    minima[axisNumber] = reading;
  }
  if (reading > maxima[axisNumber]) {
    maxima[axisNumber] = reading;
  }

  // map the reading from the analog input range to the output range:
  reading = map(reading, minima[axisNumber], maxima[axisNumber], 0, range);

 // if the output reading is outside from the
 // rest position threshold,  use it:
  if (abs(reading - center) > threshold) {
    distance = (reading - center);
  } 

  // the Y axis needs to be inverted in order to 
  // map the movemment correctly:
  if (axisNumber == 1) {
    distance = -distance;
  }

  // return the distance for this axis:
  return distance;
}
