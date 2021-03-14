/*  
 * IDE: Arduino IDE 1.8.13
 * Board: LOLIN(WEMOS) D1 R2 & mini.
 *
 * Hardware:
 * - ESP8266 WeMos D1 mini board.
 * - 10k-20k GL5528 photoresistor.
 * - 10k resistor.
*/

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid   = "****";
const char* passwd = "****";
String iot_server_url = "http://your_zeroiot_server_address:3000/insolation"; // zeroiot
String device_id = "esp8266_wemos_1";

void setup() {
  Serial.begin(115200);

  // Hide SSID itself.
  WiFi.enableAP(0);

  WiFi.begin(ssid, passwd);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Waiting for connection");
  }   
}



int insolation;
void loop() {
  insolation = analogRead(A0);
  
  Serial.print("insolation: "); Serial.println(insolation);
  send_insolation_to_iot_server(insolation);

  delay(60 * 1000); // 1 min.
}


void send_insolation_to_iot_server(int insolation) {

  // WiFi library should automatically reconnect to WiFi network.

  String attributes = String("{")
    + "\"insolation\":\"" + String(insolation) + "\""
    + ",\"device\":\""    + device_id          + "\""
    + "}";
  
  String data = String("{")
    + "\"type\":\"insolation\""
    + ",\"attributes\":" + attributes
    + "}";
 
  String json_to_send = String("{")
    + "\"data\":" + data
    + "}";
  //Serial.print("json_to_send: "); Serial.println(json_to_send);

  HTTPClient http;
  http.begin(iot_server_url);
  http.addHeader("Content-Type", "application/vnd.api+json");
  int http_code = http.POST(json_to_send);
  
  //Serial.print("http code: "); Serial.println(http_code);
  //String payload = http.getString();
  //Serial.print("payload: "); Serial.println(payload);
  
  http.end();
}

