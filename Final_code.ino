//////////Arduino control for Walk-e///////////////////

// Author: Kacper Sikorski 
// Date : 29/11/2023

// Description: This code is used to control the LED strip and vibration motors based on the commands sent from Raspberry Pi
// over serial communication UART port 

// import necessary libraries for the LED strip
#include <FastLED.h>

// all defines for LEDs 
#define LED_PIN     7
#define NUM_LEDS    144
#define RED     CRGB(255, 0, 0)

// RGB colours 
#define GREEN   CRGB(0, 255, 0)
#define ORANGE   CRGB(255,165,0)
#define NOCOLOUR CRGB(0, 0, 0) 
#define BLUE CRGB(0, 0, 255)

// Motor Pins 
#define MotorPin 13
#define MotorPin2 12

// control over LEDs 
CRGB leds[NUM_LEDS];



 

void setup() {

  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);

  pinMode(MotorPin, OUTPUT);  // sets the digital pin 13 as output
  pinMode(MotorPin2, OUTPUT);



  Serial.begin(9600);
  setColor(BLUE);
  delay(3000);
  setColor(NOCOLOUR);
  delay(3000);
}

 

void loop() {
   while (Serial.available() > 0) {
    // Read the incoming data
    char receivedData = Serial.read();
    
    // Print the received data
    Serial.print("Received data: ");
    Serial.println(receivedData);

    if (receivedData == 'r') {
       digitalWrite(MotorPin, LOW);
       digitalWrite(MotorPin2, LOW);
      setColor(NOCOLOUR);
      setColor(RED);
      digitalWrite(MotorPin, HIGH);
      digitalWrite(MotorPin2, HIGH);
      delay(1000);
   
      // Add your action here
    }
    else if (receivedData == 'o'){
       digitalWrite(MotorPin, LOW);
       digitalWrite(MotorPin2, LOW);
      setColor(NOCOLOUR);
      setColor(ORANGE);
      delay(1000);


    } 
    else if(receivedData == 'g'){
    digitalWrite(MotorPin, LOW);
    digitalWrite(MotorPin2, LOW);
    setColor(NOCOLOUR);
    setColor(GREEN);
    delay(1000);

  }
  else {
    digitalWrite(MotorPin, LOW);
    digitalWrite(MotorPin2, LOW);
    setColor(BLUE);
  }


   }
}

void setColor(CRGB color) {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = color;
  }
  FastLED.show();
}
