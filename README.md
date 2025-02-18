# Smart Street Light Using NodeMCU

This project automates street lighting using a NodeMCU (ESP8266). It detects ambient light using an LDR sensor, controls an LED accordingly, and logs activity with timestamps retrieved via an NTP server. Additionally, a servo motor is used for demonstration purposes.

## Features
- Automatically turns the LED on in low light conditions.
- Logs switching activity with timestamps.
- Uses an NTP server to get accurate time.
- Rotates a servo motor periodically.
- Connects to Wi-Fi for real-time clock synchronization.

## Requirements
### Hardware:
- NodeMCU (ESP8266)
- Light Dependent Resistor (LDR)
- LED
- Servo Motor
- Resistors and jumper wires

### Software:
- Arduino IDE
- ESP8266 Board Library
- Required Libraries:
  ```sh
  pip install opencv-python deepface numpy
  ```

## Installation and Usage
1. Clone the repository:
   ```sh
   git clone https://github.com/your-username/smart-street-light.git
   cd smart-street-light
   ```
2. Open `smart_street_light.ino` in Arduino IDE.
3. Install the required libraries in Arduino IDE:
   - ESP8266WiFi
   - WiFiUdp
   - NTPClient
4. Modify `ssid` and `password` in the script to match your Wi-Fi credentials.
5. Upload the code to NodeMCU.
6. Open the Serial Monitor at 115200 baud rate to observe logs.

## How It Works
1. The system connects to Wi-Fi and syncs time from an NTP server.
2. The LDR sensor measures ambient light intensity.
3. If the light intensity drops below a threshold, the LED turns on.
4. The system logs the time when the LED switches on or off.
5. The servo motor rotates at scheduled intervals for demonstration.

## Troubleshooting
- Ensure correct Wi-Fi credentials.
- Verify all connections, especially LDR and LED polarity.
- Check if the ESP8266 board is installed in the Arduino IDE.



