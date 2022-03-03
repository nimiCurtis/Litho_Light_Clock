#include <Arduino.h>
#include <FastLED.h>
#define LED_PIN1      3
#define LED_PIN2      4
#define NUM_LEDS    3
#define BUTTON_PIN A0

CRGB leds1[NUM_LEDS];
CRGB leds2[NUM_LEDS]; 
uint64_t minute = 60*1000L ;
int previousState;
  
void setup() {
  
  Serial.begin(9600);
  previousState = 0;
  FastLED.addLeds<WS2812, LED_PIN1, GRB>(leds1, NUM_LEDS);
  FastLED.addLeds<WS2812, LED_PIN2, GRB>(leds2, NUM_LEDS);
}
  
void loop() {
  
  delay(300) ; 
  int analogValue = analogRead(BUTTON_PIN);
  int actualState;
  
  if(analogValue < 200) actualState = 1;
  else if(analogValue < 800) actualState = 3;
  else actualState = 2;
  
  if (actualState != previousState){
    previousState = actualState;
    switch(actualState){
    case 1:
      FastLED.clear() ;
      FastLED.show();
      Serial.print("Button state: ");
      Serial.println(actualState);
      break;
    case 2:
      FastLED.clear() ;
      FastLED.show();
      Serial.print("Button state: ");
      Serial.println(actualState);
      break;
    case 3:      
      Serial.print("Button state: ");
      Serial.println(actualState);
      
      leds1[0] = CRGB (255, 130, 130);
      leds2[0] = CRGB (255, 130, 130);
      FastLED.show();
      leds1[1] = CRGB (245, 73, 73);
      leds2[1] = CRGB (245, 73, 73);
      FastLED.show();
      leds1[2] = CRGB (240, 20, 20);
      leds2[2] = CRGB (240, 20, 20);
      FastLED.show();

      delay(0.1*minute);

      leds1[0] = CRGB (255, 255, 153);
      leds2[0] = CRGB (255, 255, 153);
      FastLED.show();
      leds1[1] = CRGB (255,255, 51);
      leds2[1] = CRGB (255, 255, 51);
      FastLED.show();
      leds1[2] = CRGB (204, 204, 0);
      leds2[2] = CRGB (204, 204, 0);
      FastLED.show();

      delay(0.1*minute);
      break;
    }
  }


}


