#include <SoftwareSerial.h>
#include <DHT.h>
#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
SoftwareSerial SUART(4, 5); //SRX=Dpin-D2; STX-DPin-D1
//--------------------------------------------
const char* ssid = "APELU"; //nama Wifi sesuaikan dengan WiFi anda
const char* password = "orausahmaido"; //password WiFi sesuaikan dengan WiFi anda
//int keyIndex = 0;
int rataKelembapan;
int rataSuhu;
int cahaya;
WiFiClient client;
unsigned long myChannelNumber = 986547;
const char * myWriteAPIKey = "0XY2WLNC7AUGOKPY";

void setup()
{
  Serial.begin(115200); //enable Serial Monitor
  SUART.begin(115200); //enable SUART Port
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
  //delay(1000);
}

void loop() {

  //Connect or reconnect to WiFi
  if (WiFi.status() != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    while (WiFi.status() != WL_CONNECTED) {
      WiFi.begin(ssid, password);  // Connect to WPA/WPA2 network. Change this line if using open or WEP network
      Serial.print(".");
      delay(5000);
    }
    Serial.println("\nConnected.");
  }

  byte n = SUART.available(); //n != 0 means a character has arrived
  if (n > 0)
  {
    if (SUART.find('A')) rataSuhu        = SUART.parseInt();
    if (SUART.find('B')) rataKelembapan  = SUART.parseInt();
    if (SUART.find('C')) cahaya          = SUART.parseInt();
    
    Serial.println(rataSuhu);
    Serial.println(rataKelembapan);//show character on Serial Monitor
    Serial.println(cahaya);
    delay(1000);
  }

   // set the fields with the values
  ThingSpeak.setField(1, rataSuhu);
  ThingSpeak.setField(2, rataKelembapan);
  ThingSpeak.setField(3, cahaya);


  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  delay(5000);

}
