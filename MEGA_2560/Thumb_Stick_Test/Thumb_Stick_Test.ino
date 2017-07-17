/*
 By Robert Wilson
 17 July 2017
*/

const int Thumb_Stick = A1;
const int Blue_LED = 12;
const int Red_LED = A15;
void setup() {
  // put your setup code here, to run once:
  pinMode(Thumb_Stick, INPUT);
  pinMode(Red_LED, OUTPUT);
  pinMode(Blue_LED, OUTPUT);
   Serial.begin(9600); //init serial to 9600b/s
  digitalWrite(Blue_LED, LOW);
  digitalWrite(Red_LED, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
   int Thumb_Value = analogRead(Thumb_Stick);
   Serial.println(Thumb_Value);   //Print Low when no magnetic field is detected
 
      
      if(Thumb_Value == 0)
      {
       digitalWrite(Blue_LED, HIGH); 
      }
        else
        {
        digitalWrite(Blue_LED, LOW);
        analogWrite(Red_LED, Thumb_Value);
        }
}
