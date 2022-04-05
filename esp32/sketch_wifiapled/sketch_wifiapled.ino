#include "C:\Users\wahyu\Documents\ArduinoData\packages\esp32\hardware\esp32\1.0.6\libraries\WiFi\src\WiFi.h"
#include <WiFiClient.h>
#include <WiFiAP.h>

#define LED_BUILTIN 13

const char *ssid = "ESP32 LED Control";

WiFiServer server(80);

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(115200);
  Serial.println();
  Serial.println("Configuring Access Point ...");

  WiFi.softAP(ssid);
  IPAddress ipAddress = WiFi.softAPIP();
  Serial.print("AP IP Address: ");
  Serial.println(ipAddress);
  server.begin();

  Serial.println("Server Started!");
}

void loop() {
  // put your main code here, to run repeatedly
  WiFiClient client = server.available();

  if (client) {
    Serial.println("New Client Connected");
    String currentLine = "";
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        if (c == '\n') {
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            client.print("Click <a href=\"/H\">here</a> to turn ON the LED.<br>");
            client.print("Click <a href=\"/L\">here</a> to turn OFF the LED. <br>");

            client.println();

            break;
          } else {
            currentLine = "";
          }
        } else if ( c != '\r') {
          currentLine += c;
        }

        if (currentLine.endsWith("GET /H")) {
          digitalWrite(LED_BUILTIN, HIGH);
          Serial.println("LED Turned ON!");
        } else if (currentLine.endsWith("GET /L")) {
          digitalWrite(LED_BUILTIN, LOW);
          Serial.println("LED Turned OFF!");
        }
      }
    }
  }
}
