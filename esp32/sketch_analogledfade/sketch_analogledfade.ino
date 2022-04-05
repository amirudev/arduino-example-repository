const int ledPin = 13;
const int ledPin2 = 5;
const int ledPin3 = 23;

const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;

void setup() {
  // put your setup code here, to run once:
  ledcSetup(ledChannel, freq, resolution);

  ledcAttachPin(ledPin, ledChannel);
  ledcAttachPin(ledPin2, ledChannel);
  ledcAttachPin(ledPin3, ledChannel);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
    ledcWrite(ledChannel, dutyCycle);
    delay(5);
  }

  for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
    ledcWrite(ledChannel, dutyCycle);
    delay(5);
  }
}
