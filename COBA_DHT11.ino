#include<SoftwareSerial.h>
SoftwareSerial SUART(2, 3); //SRX=Dpin-2; STX-DPin-3
#include <DHT.h>
DHT dht(4, DHT11); //Pin, Jenis DHT

void setup(){
 Serial.begin(115200);
 dht.begin();
 SUART.begin(115200); //enable SUART Port
}

void loop(){
 double kelembaban = dht.readHumidity();
 double suhu = dht.readTemperature();

 Serial.print("kelembaban: ");
 Serial.print(kelembaban);
 Serial.print(" ");
 Serial.print("suhu: ");
 Serial.println(suhu);

 SUART.print(
'A' + String((double)suhu) +
'B' + String((double)kelembaban));

  delay(1000); 
}
