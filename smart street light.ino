
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <NTPClient.h>

// Wi-Fi credentials
const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";

// Define pin numbers
const int LDRPin = A0; // LDR connected to analog pin A0
const int LEDPin = D1; // LED connected to digital pin D1
const int servoPin = D2; // Servo connected to digital pin D2

// NTP client setup
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", 19800, 60000);  // UTC +5:30 (19800 seconds) for IST

void setup() {
  Serial.begin(115200);
  
  // Initialize the pins
  pinMode(LEDPin, OUTPUT);
  pinMode(servoPin, OUTPUT);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Initialize the NTP client
  timeClient.begin();
}

void loop() {
  timeClient.update();
  String formattedTime = timeClient.getFormattedTime();

  int ldrValue = analogRead(LDRPin);  // Read the value from the LDR sensor

  // Turn on the LED if the LDR value is below a certain threshold (indicating darkness)
  if (ldrValue < 500) {
    if (digitalRead(LEDPin) == LOW) {  // Check if LED was previously off
      digitalWrite(LEDPin, HIGH);  // Turn on LED
      Serial.println("Switched on at " + formattedTime);
    }
  } else {
    if (digitalRead(LEDPin) == HIGH) {  // Check if LED was previously on
      digitalWrite(LEDPin, LOW);  // Turn off LED
      Serial.println("Switched off at " + formattedTime);
    }
  }

  // Rotate the servo 90 degrees clockwise
  rotateServo(90);  
  delay(60000);  // Wait for 1 minute (60000 milliseconds)
  
  // Return the servo to its original position
  rotateServo(0);  
  delay(60000);  // Wait for 1 minute (60000 milliseconds)
}

void rotateServo(int angle) {
  // Calculate the pulse width corresponding to the given angle
  int pulseWidth = map(angle, 0, 180, 500, 2500); // Map angle to servo pulse width (500µs to 2500µs)

  // Generate the pulse for the servo
  for (int i = 0; i < 50; i++) {  // Send 50 pulses (for stability)
    digitalWrite(servoPin, HIGH);
    delayMicroseconds(pulseWidth);
    digitalWrite(servoPin, LOW);
    delay(20 - pulseWidth / 1000);  // Wait for the rest of the 20ms period
  }
}
