
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

const byte addresses[][6] = { "ZielCze","CzeZiel",};

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
   
   radio.openReadingPipe(1, addresses[1]); // CzeZiel
    if (radio.available()) {
      while (!radio.available());{
      int text = "";
      radio.read(&text, sizeof(text));
      Serial.println(text);
     if(text==1){
      delay(2500);
      }
     if(text==2){
      
         
         digitalWrite(ledPin, HIGH);
         delay(2500);
         digitalWrite(ledPin, LOW);
      }
    }
    }
   buttonState = digitalRead(buttonPin);
   if (buttonState == LOW){
    
   radio.stopListening();
   int text = 105;
   radio.openWritingPipe(addresses[0]); // ZielCze
   radio.write(&text, sizeof(text));
   radio.write(&text, sizeof(text));
  } 
  

}
