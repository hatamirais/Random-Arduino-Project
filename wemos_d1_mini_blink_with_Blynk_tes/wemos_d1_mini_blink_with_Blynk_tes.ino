#define BLYNK_PRINT Serial
 
#include <ESP8266WiFi.h>

#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.

// Go to the Project Settings (nut icon).

char auth[] = "2CQeK9QuD_tGD-tOyg_3kCon-90KP_Gv";
 
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Redmi";
char pass[] = "1sampai8";

int LED = D8; // Define LED as an Integer (whole numbers) and pin D8 on Wemos D1 Mini Pro

void setup()
{
  // Debug console
  Serial.begin(115200);
 pinMode(LED, OUTPUT); //Set the LED (D8) as an output
  Blynk.begin(auth, ssid, pass);

}

void loop()
{
  Blynk.run();
 
}
 
// This function will be called every time button Widget
// in Blynk app writes values to the Virtual Pin V3
BLYNK_WRITE(V3) {
 int pinValue = param.asInt(); // Assigning incoming value from pin V3 to a variable
 if (pinValue == 1) {
    digitalWrite(LED, HIGH); // Turn LED on.
  } else {
    digitalWrite(LED, LOW); // Turn LED off.
 }
}
