/*** this is test program to drive servo motor to the angle higher than its current position
 * while monitoring the current value
driving servo above or below its limits will damage the motors***/

#include <Servo.h>
 
Servo Servo1;          
int Angle= 150; // Set angle , give input of required angle between min and max strokelengh
int Servo_ang =0; //intial Servo Angle
int current_sen =0;
int threshold =1026; //enter Current sensor threshold value where motor should stop
  

void setup() 
{ 
 Serial.begin (9600);
 Servo1.attach(9); 
 analogReference(852);
  digitalWrite(A1,LOW);
   Serial.println("Current senor0 =");
   Servo1.write(Servo_ang);
   delay(1000);
}
  
void loop()
{
 
  current_sen= analogRead(A1);
  
  Serial.print("Current sensor intial value=");
   Serial.print(current_sen);
   Serial.println();
	while (current_sen <threshold && Servo_ang <= Angle)
   {
    Servo1.write(Servo_ang);
   
     delay(800);
     current_sen= analogRead(A1);
     Serial.print("Current senor =");  Serial.print(current_sen);
     Serial.println();
     Serial.print("servo angle ="); Serial.print(Servo_ang);
     Serial.println();
     Servo_ang= Servo_ang+5;
      break;
   }
} 

 
