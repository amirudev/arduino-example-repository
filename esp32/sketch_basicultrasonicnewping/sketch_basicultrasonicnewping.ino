#include <NewPing.h>

#define TRIGGER_PIN 13
#define ECHO_PIN 12
#define MAX_DISTANCE 200

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(200);
  unsigned int uS = sonar.ping();

  pinMode(ECHO_PIN, OUTPUT);
  digitalWrite(ECHO_PIN, LOW);

  pinMode(ECHO_PIN, INPUT);

  Serial.print("Ping: ");
  Serial.print(uS / US_ROUNDTRIP_CM);
  Serial.print("cm");
}
