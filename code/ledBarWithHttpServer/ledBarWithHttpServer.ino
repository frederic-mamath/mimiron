#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <Adafruit_NeoPixel.h>

const char* ssid = "wifi-name";
const char* password = "password";

#define LED_PIN 14
#define NUM_PIXELS 20

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_PIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

ESP8266WebServer server(80);

void handleRoot() {
  String message = "LED strip is currently ";
  message += (strip.getPixelColor(0) > 0) ? "on" : "off";
  server.send(200, "text/plain", message);
}

void handleOn() {
  strip.fill(strip.Color(255, 0, 0), 0, NUM_PIXELS);
  strip.show();
  server.send(200, "text/plain", "LED strip turned on");
}

void handleOff() {
  strip.fill(strip.Color(0, 0, 0), 0, NUM_PIXELS);
  strip.show();
  server.send(200, "text/plain", "LED strip turned off");
}

void setup() {
  strip.begin();
  strip.show();

  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/led/on", handleOn);
  server.on("/led/off", handleOff);

  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
