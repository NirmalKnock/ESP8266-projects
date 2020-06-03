#include<ESP8266WiFi.h>
const char ssid[]="nirmal kumar";
const char password[]="nirmal@1234";
const char hostname[]="google.com";
const String uri="/index.html";
const int port =80;
WiFiClient client;
void setup(){
  // Initialize serial
Serial.begin(9600);
delay(100);
  // connect wifi
Serial.print("connecting to wifi");
Serial.print("ssid");
WiFi.begin(ssid,password);
while(WiFi.status()!=WL_CONNECTED){
  delay(500);
  Serial.print(".");

}
Serial.println();
//Show connected
Serial.println("connected");
}
void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(WiFi.localIP());
  delay(1000);
  Serial.println(hostname);
  if (client.connect(hostname,port)==0){
    Serial.println("connection failed"); 
  }

  //sending the request file
  client.print("GET" + uri +"HTTP/1.1\r\n" + 
  "Host:" +hostname + "\r\n" +
  "Connection :close\r\n" +
  "\r\n");
  delay(500);

// print reply from server
while(client.available()){
  String ln =client.readStringUntil('\r');
  Serial.print(ln);
}

//close TCP connection
client.stop();
Serial.println();
Serial.println("connection closed");
delay(5000);


}
