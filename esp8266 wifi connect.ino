
#include "SoftwareSerial.h"
String ssid="nirmal kumar";
String password="nirmal@1234";

SoftwareSerial soft(8,9);
void setup(){
  Serial.begin(115200);
  soft.begin(9600);
  soft.println("ESP 32.....");
  Serial.println("AT");//AT command set for esp32 or esp-32
  //verify that in ESP8266AT commandSet
  delay(10);
  
if(Serial.find("OK")==0){
  soft.println("esp32 not found");
  while(1);//Which determines the esp32 to check again and again
  }

  soft.println("wifi...");
  Serial.println("AT+CWJAP=\"" + ssid="\",\"" + password="\"");
  delay(10);

  if(Serial.find("OK")==0){
    soft.println("could not connect the wifi");
    while(1);
    }
    else{
      soft.println("connected successfully");
      
    }
}
void loop(){
  
}
