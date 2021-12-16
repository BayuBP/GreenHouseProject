/* node Base 00 Sebagai Sink */
#include <SoftwareSerial.h>
#include <RF24Network.h>
#include <RF24.h>
#include <SPI.h>

SoftwareSerial SUART(2, 3); //SRX=Dpin-2; STX-DPin-3
RF24 radio(9, 10);               // nRF24L01 (CE,CSN)
RF24Network network(radio);      // Include the radio in the network
const uint16_t this_node = 00;   // Address of our node in Octal format ( 04,031, etc)
const uint16_t node01 = 01;
const uint16_t node02 = 02;
double kelembapan[4];
double suhu, rataSuhu, rataKelembapan, cahaya;

void setup() {
  SPI.begin();
  radio.begin();
  network.begin(90, this_node); //(channel, node address)
  radio.setDataRate(RF24_2MBPS);
  Serial.begin(115200);
  SUART.begin(115200);
}


void loop() {
  
  network.update();
  //===== Receiving =====//
  while ( network.available() ) {     // Is there any incoming data?
    RF24NetworkHeader header;
    double incomingData[6];
    network.read(header, &incomingData, sizeof(incomingData)); // Read the incoming data
    if (header.from_node == 1) {    // If data comes from Node 01
      suhu = incomingData[4];
      Serial.println("Node 1 :");
      Serial.println(incomingData[0]); // bed 1
      Serial.println(incomingData[3]); // bed 2
      Serial.println(incomingData[1]); // bed 3
      Serial.println(incomingData[2]); // bed 4
      kelembapan[0] = incomingData[0];
      kelembapan[1] = incomingData[3];
      kelembapan[2] = incomingData[1];
      kelembapan[3] = incomingData[4];
      Serial.println(incomingData[4]); // suhu
      rataKelembapan = (kelembapan[0] + kelembapan[1] + kelembapan[2] + kelembapan[3]) / 4;
    }
    if (header.from_node == 2) {    // If data comes from Node 02
      Serial.println("Node 2 :");
      Serial.println(incomingData[0]); // suhu
      Serial.println(incomingData[1]); // cahaya
      rataSuhu = (suhu + incomingData[0]) / 2;
      cahaya = incomingData[1];
    }
    delay(1000);
  }
  SUART.print(
        'A' + String((double)rataSuhu) +
        'B' + String((double)rataKelembapan) + 
        'C' + String((double)cahaya));
  delay(1000);
}
