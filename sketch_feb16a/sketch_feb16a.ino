 
       
#define TRIGGER 2  // D4 pin of Node MCU
#define ECHO 0     // D3 pin of Node-MCU
#define BLYNK_PRINT Serial    
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h> // Blynk Librery

char auth[] = "XhiikDQv4hvRByK3KgvAHhYYbzEGeO7T";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Sanglap"; 
char pass[] = "EEE1707046";
void setup() {
  
  Serial.begin (9600);
  Blynk.begin(auth, ssid, pass); // Taking WiFi credentials.
  pinMode(TRIGGER, OUTPUT); // trigger throw a signel to the object
  pinMode(ECHO, INPUT);     // takes the returning signal
 
}

void loop() {
  
  long duration, distance;
  digitalWrite(TRIGGER, LOW);  
  delayMicroseconds(2); 
  
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10); 
  
  digitalWrite(TRIGGER, LOW);
  duration = pulseIn(ECHO, HIGH);
  distance = (duration/2) / 29.1; // Calculating distance 

   if (distance <=50) {
    Blynk.virtualWrite(V1, "Full"); // Printing that space is full when the distance of a object less or  50 cm
}
  else {
    Blynk.virtualWrite(V1,"Vacent"); // Print vacent when there is no car
  } // V0 is a virtual pin assigned by blynk platform
}
