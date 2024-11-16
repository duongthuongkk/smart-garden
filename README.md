# **An application of the smart garden to control temperature and humidity**

## Descriptions
The system can track temperature and humidity in real-time situations and send data logs to the Blynk server.
## Features
- Use STM32 to read temperature and humidity from a GY-SHT30-D sensor module via I2C interfaces.
- This data is stored in a buffer and it will be sent to LCD for displaying.
- Use the UART protocol to communicate between STM32 and ESP8266 for transferring data logs.
- The logs will be sent to the Blynk server for user management.
