#include <ESP8266WiFi.h>
#include <WiFiManager.h>
#include <WiFiClient.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

const long interval = 15000; // Each 10 seconds
unsigned long lastMillis = 0;

void setup() {
    Serial.begin(115200);
    
    WiFiManager wm;
    
    bool res;
    res = wm.autoConnect("AutoConnectAP","password"); // password protected ap

    if(!res) {
        Serial.println("Failed to connect");
    } 
    else {
        Serial.println("connected!)");
    }
}

void loop() {
    unsigned long currentMillis = millis();

    if ((currentMillis - lastMillis) >= interval){
        lastMillis = currentMillis;

        String response = getRequest();
        JsonDocument doc;
        DeserializationError error = deserializeJson(doc, response);

        float temperature = doc["main"]["temp"];
        Serial.print("Temperature: ");
        Serial.println(kelvinToCelsius(temperature));
        delay(1000);
        postRequest();
    }
}
