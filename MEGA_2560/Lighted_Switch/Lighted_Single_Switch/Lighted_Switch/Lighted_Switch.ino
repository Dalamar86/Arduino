/*
 By Robert Wilson
 17 July 2017
*/

const int Switch_Out = 25;
const int Switch_In = 50;
const int Blue_LED = 12;
const int Red_LED = 13;
void setup() {
  // 
  pinMode(Switch_Out, OUTPUT);
  pinMode(Switch_In, INPUT);
  pinMode(Red_LED, OUTPUT);
  pinMode(Blue_LED, OUTPUT);
   Serial.begin(9600); //init serial to 9600b/s
  digitalWrite(Red_LED, LOW);
  digitalWrite(Red_LED, LOW);
  digitalWrite(Switch_Out, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  int Switch_Value = digitalRead(Switch_In);
  Serial.println(Switch_Value);   //Print Low when no magnetic field is detected
    if(Switch_Value == 0)
    {
      digitalWrite(Blue_LED, LOW);
      digitalWrite(Red_LED, HIGH);
    }
    else
    {
      digitalWrite(Red_LED,LOW);
      digitalWrite(Blue_LED, HIGH);
    }
}
