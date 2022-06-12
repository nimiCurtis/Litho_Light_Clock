#include <Arduino.h>
#include <FastLED.h>
#include <TimeLib.h>
#include <DS1307RTC.h>

#define LED_PIN1    3
#define LED_PIN2    4
#define NUM_LEDS    3
#define BUTTON_PIN A0

CRGB leds1[NUM_LEDS];
CRGB leds2[NUM_LEDS]; 
int previousState;
int max_val = 240; 
int min_val = 0;
int r_val; int g_val; int b_val; 
bool is_led_set = false ; 
bool is_click = false ; 
tmElements_t tm;

void set_led_val(int red_val , int green_val , int blue_val ){
      leds1[0] = CRGB (red_val, green_val, blue_val);
      leds2[0] = CRGB (red_val, green_val, blue_val);
      FastLED.show();
      leds1[1] = CRGB (red_val, green_val, blue_val);
      leds2[1] = CRGB (red_val, green_val, blue_val);
      FastLED.show();
      leds1[2] = CRGB (red_val, green_val, blue_val);
      leds2[2] = CRGB (red_val, green_val, blue_val);
      FastLED.show();
}

void set_light_depends_on_time(){
  // 00:00 - 01:00
  if (tm.Hour==0){
    Serial.println(" time is after 00:00 ");
    r_val = min_val ; g_val = max_val  ; b_val = min_val ; 
    if(tm.Minute<30){
      set_led_val(r_val , g_val , b_val );
    }
    else{
      set_led_val(r_val , g_val , b_val + 30  ); // b = b  + (max_val/8)
    }
  }

  // 01:00 - 02:00
  if (tm.Hour==1){
    Serial.println(" time is after 01:00 ");
    r_val = min_val ; g_val = max_val  ; b_val = 60 ;  // b = (max_val/8)*2
    if(tm.Minute<30){
      set_led_val(r_val , g_val , b_val );
    }
    else{
      set_led_val(r_val , g_val , b_val + 30  ); // b = b  + (max_val/8)
    }
  }

  // 02:00 - 03:00
  if (tm.Hour==2){
    Serial.println(" time is after 02:00 ");
    r_val = min_val ; g_val = max_val  ; b_val = 120 ;  // b = (max_val/8)*4
    if(tm.Minute<30){
      set_led_val(r_val , g_val , b_val );
    }
    else{
      set_led_val(r_val , g_val , b_val + 30  ); // b = b  + (max_val/8)
    }
  }

  // 03:00 - 04:00
  if (tm.Hour==3){
    Serial.println(" time is after 03:00 ");
    r_val = min_val ; g_val = max_val  ; b_val = 180 ;  // b = (max_val/8)*6
    if(tm.Minute<30){
      set_led_val(r_val , g_val , b_val );
    }
    else{
      set_led_val(r_val , g_val , b_val + 30  ); // b = b  + (max_val/8)
    }
  }

  // 04:00 - 05:00
  if (tm.Hour==4){
    Serial.println(" time is after 04:00 ");
    r_val = min_val ; g_val = max_val  ; b_val = max_val ;  // b = max
    if(tm.Minute<30){
      set_led_val(r_val , g_val , b_val );
    }
    else{
      set_led_val(r_val , g_val - 30 , b_val  ); // g = g  - (max_val/8)
    }
  }

  // 05:00 - 06:00
  if (tm.Hour==5){
    Serial.println(" time is after 05:00 ");
    r_val = min_val ; g_val = 180  ; b_val = max_val ;  // g = (max_val/8)*6
    if(tm.Minute<30){
      set_led_val(r_val , g_val , b_val );
    }
    else{
      set_led_val(r_val , g_val - 30 , b_val  ); // g = g  - (max_val/8)
    }
  }

  // 06:00 - 07:00
  if (tm.Hour==6){
    Serial.println(" time is after 06:00 ");
    r_val = min_val ; g_val = 120  ; b_val = max_val ;  // g = (max_val/8)*4
    if(tm.Minute<30){
      set_led_val(r_val , g_val , b_val );
    }
    else{
      set_led_val(r_val , g_val - 30 , b_val  ); // g = g  - (max_val/8)
    }
  }

  // 07:00 - 08:00
  if (tm.Hour==7){
    Serial.println(" time is after 07:00 ");
    r_val = min_val ; g_val = 60  ; b_val = max_val ;  // g = (max_val/8)*2
    if(tm.Minute<30){
      set_led_val(r_val , g_val , b_val );
    }
    else{
      set_led_val(r_val , g_val - 30 , b_val  ); // g = g  - (max_val/8)
    }
  }

  // 08:00 - 09:00
  if (tm.Hour==8){
    Serial.println(" time is after 08:00 ");
    r_val = min_val ; g_val = min_val  ; b_val = max_val ;  // g = min
    if(tm.Minute<30){
      set_led_val(r_val , g_val , b_val );
    }
    else{
      set_led_val(r_val + 30 , g_val  , b_val  ); // r = r  + (max_val/8)
    }
  }

  // 09:00 - 10:00
  if (tm.Hour==9){
    Serial.println(" time is after 09:00 ");
    r_val = 60 ; g_val = min_val  ; b_val = max_val ;  // r = (max_val/8)*2
    if(tm.Minute<30){
      set_led_val(r_val , g_val , b_val );
    }
    else{
      set_led_val(r_val + 30 , g_val  , b_val  ); // r = r  + (max_val/8)
    }
  }

  // 10:00 - 11:00
  if (tm.Hour==10){
    Serial.println(" time is after 10:00 ");
    r_val = 120 ; g_val = min_val  ; b_val = max_val ;  // r = (max_val/8)*4
    if(tm.Minute<30){
      set_led_val(r_val , g_val , b_val );
    }
    else{
      set_led_val(r_val + 30 , g_val  , b_val  ); // r = r  + (max_val/8)
    }
  }

  // 11:00 - 12:00
  if (tm.Hour==11){
    Serial.println(" time is after 11:00 ");
    r_val = 180 ; g_val = min_val  ; b_val = max_val ;  // r = (max_val/8)*6
    if(tm.Minute<30){
      set_led_val(r_val , g_val , b_val );
    }
    else{
      set_led_val(r_val + 30 , g_val  , b_val  ); // r = r  + (max_val/8)
    }
  }

  // 12:00 - 13:00
  if (tm.Hour==12){
    Serial.println(" time is after 12:00 ");
    r_val = max_val ; g_val = min_val  ; b_val = max_val ;  // r = max
    if(tm.Minute<30){
      set_led_val(r_val , g_val , b_val );
    }
    else{
      set_led_val(r_val , g_val  , b_val - 30  ); // b = b  - (max_val/8)
    }
  }

  // 13:00 - 14:00
  if (tm.Hour==13){
    Serial.println(" time is after 13:00 ");
    r_val = max_val ; g_val = min_val  ; b_val = 180 ;  // b = (max_val/8)*6
    if(tm.Minute<30){
      set_led_val(r_val , g_val , b_val );
    }
    else{
      set_led_val(r_val , g_val  , b_val - 30  ); // b = b  - (max_val/8)
    }
  }

  // 14:00 - 15:00
  if (tm.Hour==14){
    Serial.println(" time is after 14:00 ");
    r_val = max_val ; g_val = min_val  ; b_val = 120 ;  // b = (max_val/8)*4
    if(tm.Minute<30){
      set_led_val(r_val , g_val , b_val );
    }
    else{
      set_led_val(r_val , g_val  , b_val - 30  ); // b = b  - (max_val/8)
    }
  }

  // 15:00 - 16:00
  if (tm.Hour==15){
    Serial.println(" time is after 15:00 ");
    r_val = max_val ; g_val = min_val  ; b_val = 60 ;  // b = (max_val/8)*2
    if(tm.Minute<30){
      set_led_val(r_val , g_val , b_val );
    }
    else{
      set_led_val(r_val , g_val  , b_val - 30  ); // b = b  - (max_val/8)
    }
  }

  // 16:00 - 17:00
  if (tm.Hour==16){
    Serial.println(" time is after 16:00 ");
    r_val = max_val ; g_val = min_val  ; b_val = min_val ;  // b = min
    if(tm.Minute<30){
      set_led_val(r_val , g_val , b_val );
    }
    else{
      set_led_val(r_val , g_val + 30 , b_val   ); // g = g  + (max_val/8)
    }
  }

  // 17:00 - 18:00
  if (tm.Hour==17){
    Serial.println(" time is after 17:00 ");
    r_val = max_val ; g_val = 60  ; b_val = min_val ;  // g = (max_val/8)*2
    if(tm.Minute<30){
      set_led_val(r_val , g_val , b_val );
    }
    else{
      set_led_val(r_val , g_val + 30 , b_val   ); // g = g  + (max_val/8)
    }
  }

  // 18:00 - 19:00
  if (tm.Hour==18){
    Serial.println(" time is after 18:00 ");
    r_val = max_val ; g_val = 120  ; b_val = min_val ;  // g = (max_val/8)*4
    if(tm.Minute<30){
      set_led_val(r_val , g_val , b_val );
    }
    else{
      set_led_val(r_val , g_val + 30 , b_val   ); // g = g  + (max_val/8)
    }
  }

  // 19:00 - 20:00
  if (tm.Hour==19){
    Serial.println(" time is after 19:00 ");
    r_val = max_val ; g_val = 180  ; b_val = min_val ;  // g = (max_val/8)*6
    if(tm.Minute<30){
      set_led_val(r_val , g_val , b_val );
    }
    else{
      set_led_val(r_val , g_val + 30 , b_val   ); // g = g  + (max_val/8)
    }
  }

  // 20:00 - 21:00
  if (tm.Hour==20){
    Serial.println(" time is after 20:00 ");
    r_val = max_val ; g_val = max_val  ; b_val = min_val ;  // g = max
    if(tm.Minute<30){
      set_led_val(r_val , g_val , b_val );
    }
    else{
      set_led_val(r_val - 30, g_val  , b_val   ); // r = r  - (max_val/8)
    }
  }

  // 21:00 - 22:00
  if (tm.Hour==21){
    Serial.println(" time is after 21:00 ");
    r_val = 180 ; g_val = max_val  ; b_val = min_val ; //  r  = (max_val/8)*6
    if(tm.Minute<30){
      set_led_val(r_val , g_val , b_val );
    }
    else{
      set_led_val(r_val - 30, g_val  , b_val   ); // r = r  - (max_val/8)
    }
  }

  // 22:00 - 23:00
  if (tm.Hour==22){
    Serial.println(" time is after 22:00 ");
    r_val = 120 ; g_val = max_val  ; b_val = min_val ; //  r  = (max_val/8)*4
    if(tm.Minute<30){
      set_led_val(r_val , g_val , b_val );
    }
    else{
      set_led_val(r_val - 30, g_val  , b_val   ); // r = r  - (max_val/8)
    }
  }

  // 23:00 - 00:00
  if (tm.Hour==23){
    Serial.println(" time is after 23:00 ");
    r_val = 60 ; g_val = max_val  ; b_val = min_val ; //  r  = (max_val/8)*2
    if(tm.Minute<30){
      set_led_val(r_val , g_val , b_val );
    }
    else{
      set_led_val(r_val - 30, g_val  , b_val   ); // r = r  - (max_val/8)
    }
  }
}

void setup() {
  
  Serial.begin(9600);
  previousState = 0;
  FastLED.addLeds<WS2812, LED_PIN1, GRB>(leds1, NUM_LEDS);
  FastLED.addLeds<WS2812, LED_PIN2, GRB>(leds2, NUM_LEDS);
  }

void loop() {
  
  delay(10) ; 
  int analogValue = analogRead(BUTTON_PIN);
  int actualState;
  
  if(analogValue < 200) actualState = 1;
  else if(analogValue < 800) actualState = 3;
  else actualState = 2;
  
  if (actualState != previousState){
    previousState = actualState;
    is_click = true;
  }

  if (actualState == 1){
      is_click = false;
      //Serial.print("Button state: ");
      //Serial.println(actualState);
      leds1[0] = CRGB (20, 185, 20);
      leds2[0] = CRGB (20, 185, 20);
      FastLED.show();
      leds1[1] = CRGB (200,220,20);
      leds2[1] = CRGB (200,220,20);
      FastLED.show();
      leds1[2] = CRGB (20,130,220);
      leds2[2] = CRGB (20,130,220);
      FastLED.show();
  }

  if (actualState == 2){
      is_click = false;
      // Serial.print("Button state: ");
      // Serial.println(actualState);
      FastLED.clear() ;
      FastLED.show();
  }

  if (actualState==3){
      //Serial.print("Button state: ");
      //Serial.println(actualState);
      if (RTC.read(tm)) {
        if (is_click == true){
          set_light_depends_on_time();
          is_click = false;
        }
        else {
          if (((float)tm.Minute/39 == 1) || ((float)tm.Minute == 0)){
            if (is_led_set == false){
              set_light_depends_on_time();
              is_led_set = true;
            }
          }
          else {
              is_led_set = false;
          }
        }
      }
      else{
        if (RTC.chipPresent()) {
          Serial.println("The DS1307 is stopped.  Please run the SetTime");
          Serial.println("example to initialize the time and begin running.");
          Serial.println();
        }       
        else {
          Serial.println("DS1307 read error!  Please check the circuitry.");
          Serial.println();
        }
      }
    }
  }


