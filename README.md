# GreenHouseProject
NodeMCU Implementation for Green House Project at BALITKABI Malang as part of my Internship Program

At the moment in the world, especially in Europe and United States of America, implementation for Smart Farming is already quite a lot. 
But in Indonesia the usage of Smart Farming is still not quite so much, it is proven by many farmers in Indonesia still using a traditional method for their farm. 
Smart Farming itself is a method of farming where farmer didn’t have to go outside for farming activities. 
One of the usage of Smart Farming concept is to use IoT based devices, like for example is Monitoring Device and Automatic Irrigation, like the one that exist in green house at BALITKABI Malang. 
But this device still using a SD Card as it’s storage device and still make farmers to go to the green house to pick the SD Card itself. 
For that, it is required for a method to display the data to the Internet, by implementing a MCU Node to this Monitoring Device. 
So the device can do it’s monitoring duty and send the data to the internet on it’s own, and farmers didn’t need to be in the green house everyday.

Result : 

1. The implementation of the MCU Node on the Arduino Nano can be done using a serial software communication protocol as a way for the two devices communicate with each other 
   and send data from sensing results obtained by automatic monitoring and watering tools.
   
2. Sending data from sensing monitoring tools and automatic watering to ThingSpeak can be done using the MCU Node that communicates with the Arduino Nano using the configured Serial 
   Software communication protocol. The data from the sensing tool is sent to Arduino Nano using NRF24L01, which is then sent to the ESP 8266 Module. 
   The ESP 8266 Module is connected to WiFi or HotSpot Tethering to then send the sensing data to ThingSpeak, 
   where the data will be processed directly by ThingSpeak into easy-to understand graphs.
