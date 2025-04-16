#include <ESP8266WiFi.h>
#include <WiFiManager.h>
#include <WiFiClient.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

void setup() {
    // WiFi.mode(WIFI_STA); // explicitly set mode, esp defaults to STA+AP
    Serial.begin(115200);
    
    WiFiManager wm;
    
    bool res;
    res = wm.autoConnect("AutoConnectAP","password"); // password protected ap

    if(!res) {
        Serial.println("Failed to connect");
        // ESP.restart();
    } 
    else {
        Serial.println("connected!)");
    }

}

void loop() {
    String response = apiRequest();
    JsonDocument doc;
    DeserializationError error = deserializeJson(doc, response);

    float temperature = doc["main"]["temp"];
    Serial.print("Temperature: ");
    Serial.println(kelvinToCelsius(temperature));
    delay(5000);
}


String apiRequest() {
    WiFiClient client;
    HTTPClient http;

    http.begin(client, "http://api.openweathermap.org/data/2.5/weather?q=merida&appid=192dbed2ac66d17d5f75780635e474fa");
    int httpCode = http.GET();
    return http.getString();
}

float kelvinToCelsius(float kelvin){
    return kelvin -273.15;
}