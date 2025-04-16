void postRequest(){
}

String getRequest() {
    WiFiClient client;
    HTTPClient http;

    http.begin(client, "http://api.openweathermap.org/data/2.5/weather?q=merida&appid=192dbed2ac66d17d5f75780635e474fa");
    int httpCode = http.GET();
    return http.getString();
}

float kelvinToCelsius(float kelvin){
    return kelvin -273.15;
}