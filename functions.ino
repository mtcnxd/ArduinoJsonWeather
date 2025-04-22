void postRequest()
{
    // This method does not works yet! :-S

    WiFiClient client;
    HTTPClient http;

    http.begin(client, "https://www.mecanicarubio.com/arduino.php");
    http.addHeader("Content-Type", "application/json");

    String jsonData = "{}";

    int httpResponseCode = http.POST(jsonData);

    String response = http.getString();
    
    Serial.println("Code:");
    Serial.println(httpResponseCode);
    Serial.println("Response:");
    Serial.println(response);

    http.end();
}

String getRequest()
{
    WiFiClient client;
    HTTPClient http;

    http.begin(client, "http://api.openweathermap.org/data/2.5/weather?q=merida&appid=192dbed2ac66d17d5f75780635e474fa");
    int httpCode = http.GET();
    return http.getString();
}

float kelvinToCelsius(float kelvin)
{
    return kelvin -273.15;
}