/*
 By Robert Wilson
 17 July 2017
*/

const int Switch_SPST = 25;
const int Switch_LED = 50;
const int Blue_LED = 12;
const int Red_LED = 13;
const int Yellow_LED = 11;
const int Green_LED = 10;

void setup() {
  // 
  pinMode(Switch_SPST, INPUT);
  pinMode(Switch_LED, INPUT);
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
  Serial.println(Switch_LED_Value);   //Print Low when no magnetic field is detected

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
