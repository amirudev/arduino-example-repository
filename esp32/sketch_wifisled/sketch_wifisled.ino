#include<WiFi.h>

int pinLed = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  Serial.println("Setup ESP32 WiFIi Done!");

  pinMode(pinLed, OUTPUT);

  Serial.println("Setup ESP32 Output Done!");
}

void loop() {
//  Resetting output
  digitalWrite(pinLed, LOW);
  
  // put your main code here, to run repeatedly:
  Serial.println("Scanning Start ...");

  int n = WiFi.scanNetworks();
  Serial.println("Scanning Done!");

  if (n == 0) {
    Serial.println("No Networks Found");
  } else {
    Serial.print(n);
    Serial.println(" WiFi Founds!");

    for (int i = 0; i < n; i++) {
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print(")");
      Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? " " : "*");
      delay(10);

      if (WiFi.SSID(i) == "Xperia XZ3_1438") {
        Serial.println("Your WiFi Found!");
        digitalWrite(pinLed, HIGH);
      }
    }
  }

  Serial.println();

  delay(30000);
}
