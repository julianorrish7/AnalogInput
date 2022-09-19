// I, Julia Norrish, 000839030 certify that this material is my original work.  No other person's work has been used without due acknowledgement.

#include <Arduino.h> 
 
void setup() { 
  // configure the USB serial monitor 
  Serial.begin(115200); 
} 
 
void loop() { 
  int iVal; 
 
  // read digitized value from the D1 Mini's A/D convertor 
  iVal = analogRead(A0); 
  float temperature = int(iVal)/20.48;
  String tempJudgement = "";

if (temperature < 10){
  tempJudgement = "Cold!";
}
else if (temperature > 9 && temperature < 16)
{
  tempJudgement = "Cool";
}
else if (temperature > 14 && temperature < 26)
{
  tempJudgement = "Perfect";
}
else if (temperature > 24 && temperature < 31)
{
  tempJudgement = "Warm";
}
else if (temperature > 29 && temperature < 36)
{
  tempJudgement = "Hot";
}
else if (temperature > 35)
{
  tempJudgement = "Too Hot!";
}




 
  // print value to the USB port 
  Serial.println("Digitized output of " + String(iVal) + " is equivalent to a temperature input of " + String(temperature) + " deg. C, which is " + tempJudgement); 
 
  // wait 2 seconds
  delay(2000); 
} 