#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid     = "TOTOLINK_N200RE";      // SSID of local network
const char* password = "hatami007";   // Password on network
String result;
String motion ;

void setup() 
{
  pinMode(D4, INPUT);
  pinMode(D7, INPUT);
  Serial.begin(115200);
  delay(10);
  // Connect to Wi-Fi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to...");
  Serial.println(ssid);


  WiFi.begin(ssid, password);
}

void loop() //Where stuffz happens
{
 if(digitalRead(D4)== HIGH)  // ||digitalRead(D7)== HIGH) Removed MQ2 or condition
  {
   motion = digitalRead(D4); //PIR sensor pin
   delay(1000);
   Serial.println("Alarm detected!"); //Send things to serial for handy dandy info
   Serial.print("motion ");
   Serial.println(motion);
  } 
  else 
  {
    Serial.println("no trigger"); //enable for debugging of no event being triggered
  }

  if (client.connect("www.*****.*************.com",80)) { // REPLACE WITH YOUR SERVER ADDRESS
    client.println("POST /add.php HTTP/1.1"); 
    client.println("Host: *****.*************.com"); // SERVER ADDRESS HERE TOO
    client.println("Content-Type: application/x-www-form-urlencoded"); 
    client.print("Content-Length: "); 
    client.println(data.length()); 
    client.println(); 
    client.print(data); 
  } 

  if (client.connected()) { 
    client.stop();  // DISCONNECT FROM THE SERVER
  }

  delay(300000); // WAIT FIVE MINUTES BEFORE SENDING AGAIN
}
}
