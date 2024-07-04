#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL6yVBsPhKa"
#define BLYNK_TEMPLATE_NAME "Smart Garden"
#define BLYNK_AUTH_TOKEN "xc4HQu7oRc-rM2LifE4ycP342Kj88R7I"
#include <ArduinoJson.h>
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "xc4HQu7oRc-rM2LifE4ycP342Kj88R7I";
char ssid[] = "SAI GONWA";
char pass[] = "Taonoiroido";

const byte RX = D6;
const byte TX = D5;
SoftwareSerial mySerial = SoftwareSerial(RX, TX);

float temperature;
float humidity;

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();
  readUARTData();
}

void readUARTData() {
  if (mySerial.available()) {
    StaticJsonDocument<200> doc;
    DeserializationError error = deserializeJson(doc, mySerial);

    if (error) {
      Serial.print(F("deserializeJson() failed: "));
      Serial.println(error.c_str());
      return;
    }

    temperature = doc["temperature"].as<float>();
    humidity = doc["humidity"].as<float>();
    
    Serial.print("Received JSON: ");
    serializeJson(doc, Serial);
    Serial.println();
    Serial.print("Temperature: ");
    Serial.println(temperature);
    Serial.print("Humidity: ");
    Serial.println(humidity);
  
    doc.clear();
    Serial.println("-----------------------------------");
    Blynk.virtualWrite(V0, temperature);
    Blynk.virtualWrite(V1, humidity);
  }
}