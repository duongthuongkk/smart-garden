# ** smart-garden **
The system can track temperature and humidity in real-time by combining STM32F103C8T6 and ESP8266. STM32 can read temperature and humidity from GY-SHT30-D sensor  module via I2C interfaces and communicate with I2C LCD. Then, the data will be sent to ESP8266 by using UART interfaces and will be streamed on Blynk web.
