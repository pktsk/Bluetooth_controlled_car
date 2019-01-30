#include <SoftwareSerial.h>

SoftwareSerial mySerial(0, 1); // RX, TX

char chByte = 0;  // incoming serial byte
String strInput = "";    // buffer for incoming packet
String strLeft = "left";
String strRight = "right";
String strUp = "up";
String strDown = "down";
String strStop ="stop";

void setup() {

 pinMode(2, OUTPUT);
 pinMode(3, OUTPUT);
 pinMode(4, OUTPUT);
 pinMode(5, OUTPUT);
 
 // initialize serial:
 mySerial.begin(9600);
 Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {

 while (mySerial.available() > 0)
 {
  // get incoming byte:
  chByte = mySerial.read();
  
  if (chByte == '\r')
  {
   //compare input message
   if(strInput.equals(strLeft))
   {
    motor('L');
    Serial.println(strInput);
     }

     if(strInput.equals(strRight))
   {
    motor('R');
    Serial.println(strInput);
     }

     if(strInput.equals(strUp))
   {
    Serial.println(strInput);
    motor('U');
     }

     if(strInput.equals(strDown))
   {
    Serial.println(strInput);
    motor('D');
     }
     if(strInput.equals(strStop))
   {
    Serial.println(strInput);
    motor('S');
     }
   //reset strInput
   strInput = "";
  }
  else
  {
  strInput += chByte;
  }
 }
}


void motor(char input){
  switch(input){
    case 'U':
      digitalWrite(2,LOW);
      digitalWrite(3,HIGH);
      digitalWrite(4,LOW);
      digitalWrite(5,HIGH);
      break;

     case 'D':
      digitalWrite(2,HIGH);
      digitalWrite(3,LOW);
      digitalWrite(4,HIGH);
      digitalWrite(5,LOW);
      break;

     case 'L':
//starttime = millis();
//endtime = starttime;
//while ((endtime - starttime) <=1000) // do this loop for up to 1000mS
//{
// code here
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,HIGH);
//endtime = millis();
//}
//      digitalWrite(2,LOW);
//      digitalWrite(3,HIGH);
//      digitalWrite(4,LOW);
//      digitalWrite(5,HIGH);
      break;

     case 'R':
//starttime = millis();
//endtime = starttime;
//while ((endtime - starttime) <=1000) // do this loop for up to 1000mS
//{
// code here 
      digitalWrite(2,LOW);
      digitalWrite(3,HIGH);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
//endtime = millis();
//}
//      digitalWrite(2,LOW);
//      digitalWrite(3,HIGH);
//      digitalWrite(4,LOW);
//      digitalWrite(5,HIGH);      
      break;

     case 'S':
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      break;
  }
}

