#define trigger D0
#define echo D1
#define BLYNK_PRINT Serial  
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "x8yT0c1ZiVvEIl8DSoaDkEPzJ1ieRvP1";
char ssid[] = "srivastava";
char pass[] = "akhilesh45";

void setup() 
{
  Serial.begin (9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
}
void loop()
{
  
  long duration, distance, reading;
  digitalWrite(trigger, LOW);  
  delayMicroseconds(2); 
  
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10); 
  
  digitalWrite(trigger, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration/2) / 29.1;
  reading = (10-distance);
  Serial.println(reading);

  
  Blynk.virtualWrite(V3, distance);
  Blynk.virtualWrite(V4, reading);

  
  if (distance >= 9) {
    Blynk.virtualWrite(V0, 255);
    if (distance == 9){
    Blynk.email("tanyashrivastava2000@gmail.com","EMPTY!!,Please refill the tank");
    Blynk.notify("EMPTY!!,Please refill the tank");
    }
}
  else {
    Blynk.virtualWrite(V0, 0);
  }

 if (distance >= 5) {
    Blynk.virtualWrite(V1, 255);
}
  else {
    Blynk.virtualWrite(V1, 0);
  }

   if (distance >=3) {
    Blynk.virtualWrite(V2, 255);


}
  else {
    Blynk.virtualWrite(V2, 0);
  }
Blynk.run();
}
