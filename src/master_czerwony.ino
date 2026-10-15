
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

const byte addresses[][6] = {"ZolNieb", "ZolCze","ZolZiel","NiebZol","CzeZol","ZielZol"};

const int buttonPin = 3;     
const int ledPin =  4; 
int buttonState = 0; 

void setup() {
  Serial.begin(9600);
  radio.begin();
  
  
  
  
  
  radio.setPALevel(RF24_PA_MAX);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
   
}

void loop() {
   
   radio.startListening(); 
   
   radio.openReadingPipe(1, addresses[3]); // NiebZol
    if (radio.available()) {
      while (!radio.available());{
      char text1[32] = "";
      radio.read(&text1, sizeof(text1));
      Serial.println(text1);
      delay(5000);
      }
    }
    
   radio.openReadingPipe(1, addresses[4]); // CzeZol
    if (radio.available()) {
      while (!radio.available());{
      char text1[32] = "";
      radio.read(&text1, sizeof(text1));
      Serial.println(text1);
      delay(5000);
      }
    }
   radio.openReadingPipe(1, addresses[5]); // ZielZol
    if (radio.available()) {
      while (!radio.available());{
      char text1[32] = "";
      radio.read(&text1, sizeof(text1));
      Serial.println(text1);
      delay(5000);
      }
    }
   
   buttonState = digitalRead(buttonPin);
   if (buttonState == LOW){

    digitalWrite(ledPin, HIGH);
    
   radio.stopListening();
   const char text[] = "1";
   radio.openWritingPipe(addresses[0]); // ZolNieb
   radio.write(&text, sizeof(text));
   radio.write(&text, sizeof(text));
   radio.openWritingPipe(addresses[1]); // ZolCze
   radio.write(&text, sizeof(text));
   radio.write(&text, sizeof(text));
   radio.openWritingPipe(addresses[2]); // ZolZiel
   radio.write(&text, sizeof(text));
   radio.write(&text, sizeof(text));
   delay(5000);
  } 
  
  else {
    
    digitalWrite(ledPin, LOW);
    
    
  }
}
