/*******************************************************************************
@file     tango_spark_lilly_pad.ino
@author   Samuel Yamoah
@version  2.0.1
@date     31.08.2017
@modified 12.09.2017
@brief    Tango Spark LED Dress for Cocktail night
*******************************************************************************/

// Constants Setup:
const int OUT_1 = 3;
const int OUT_2 = 5;
const int OUT_3 = 6;
const int OUT_4 = 9;
const int OUT_5 = 10;
const int OUT_6 = 11;

const int TOTAL_OUT = 6;
const int OUTS[TOTAL_OUT] = {OUT_1, OUT_2, OUT_3, OUT_4, OUT_5, OUT_6};

const int MAX_REPEATS = 50;
const int MIN_DELAY = 50;
const int MAX_DELAY = 500;
const int FAST_MAX_REPEATS = 30;
const int FAST_MIN_DELAY = 5;
const int FAST_MAX_DELAY = 50;

// Changing variables:
int delay_time = MAX_DELAY;
int fast_delay_time = FAST_MAX_DELAY;

void setup() {
  // put your setup code here, to run once:
  pinMode(OUT_1, OUTPUT);
  pinMode(OUT_2, OUTPUT);
  pinMode(OUT_3, OUTPUT);
  pinMode(OUT_4, OUTPUT);
  pinMode(OUT_5, OUTPUT);
  pinMode(OUT_6, OUTPUT);

//  Serial.begin(9600);


}

void loop() {
  fade_chase();
  random_strobe();
  solid_chase();
  random_chase();
  all_pulse();
  random_strobe();
  increment_chase();

}


//Solid chase
void solid_chase(){
  // Simple chase (maybe speedup)
  for(int repeats = 0; repeats <= MAX_REPEATS; repeats++){
    digitalWrite(OUT_1, HIGH);
    digitalWrite(OUT_2, LOW);
    digitalWrite(OUT_3, LOW);
    digitalWrite(OUT_4, LOW);
    digitalWrite(OUT_5, LOW);
    digitalWrite(OUT_6, LOW);
    delay(delay_time);
    digitalWrite(OUT_1, LOW);
    digitalWrite(OUT_2, HIGH);
    digitalWrite(OUT_3, LOW);
    digitalWrite(OUT_4, LOW);
    digitalWrite(OUT_5, LOW);
    digitalWrite(OUT_6, LOW);
    delay(delay_time);
    digitalWrite(OUT_1, LOW);
    digitalWrite(OUT_2, LOW);
    digitalWrite(OUT_3, HIGH);
    digitalWrite(OUT_4, LOW);
    digitalWrite(OUT_5, LOW);
    digitalWrite(OUT_6, LOW);
    delay(delay_time);
    digitalWrite(OUT_1, LOW);
    digitalWrite(OUT_2, LOW);
    digitalWrite(OUT_3, LOW);
    digitalWrite(OUT_4, HIGH);
    digitalWrite(OUT_5, LOW);
    digitalWrite(OUT_6, LOW);
    delay(delay_time);
    digitalWrite(OUT_1, LOW);
    digitalWrite(OUT_2, LOW);
    digitalWrite(OUT_3, LOW);
    digitalWrite(OUT_4, LOW);
    digitalWrite(OUT_5, HIGH);
    digitalWrite(OUT_6, LOW);
    delay(delay_time);
    digitalWrite(OUT_1, LOW);
    digitalWrite(OUT_2, LOW);
    digitalWrite(OUT_3, LOW);
    digitalWrite(OUT_4, LOW);
    digitalWrite(OUT_5, LOW);
    digitalWrite(OUT_6, HIGH);
    delay(delay_time);

    delay_time -= 10;
    if (delay_time <= MIN_DELAY) delay_time = MIN_DELAY;
  }
   delay_time = MAX_DELAY;
    digitalWrite(OUT_1, LOW);
    digitalWrite(OUT_2, LOW);
    digitalWrite(OUT_3, LOW);
    digitalWrite(OUT_4, LOW);
    digitalWrite(OUT_5, LOW);
    digitalWrite(OUT_6, LOW);
}

// Fade Chase
void fade_chase(){
  for(int i = 0; i < TOTAL_OUT; i++){

  // fade in from min to max in increments of 5 points
    for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
      // sets the value (range from 0 to 255):
      analogWrite(OUTS[i], fadeValue);
      // wait for 50 milliseconds to see the dimming effect
      delay(50);
    }

    // fade out from max to min in decrements of 5 points
    for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
      // sets the value (range from 0 to 255):
      analogWrite(OUTS[i], fadeValue);
      // wait for 50 milliseconds to see the dimming effect
      delay(50);
    }
    digitalWrite(OUTS[i], LOW);
  }
}

// Random Chase
void random_chase(){
  int prev_led = NULL;
  for(int repeats = 0; repeats < FAST_MAX_REPEATS; repeats++){

    int led = NULL;
    while (led == prev_led) led = random(TOTAL_OUT);
//    Serial.print(led);

  // fade in from min to max in increments of 5 points
    for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
      // sets the value (range from 0 to 255):
      analogWrite(OUTS[led], fadeValue);
      // wait for 50 milliseconds to see the dimming effect
      delay(fast_delay_time);
    }

    // fade out from max to min in decrements of 5 points
    for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
      // sets the value (range from 0 to 255):
      analogWrite(OUTS[led], fadeValue);
      // wait for 50 milliseconds to see the dimming effect
      delay(fast_delay_time);
    }
    prev_led = led;
    fast_delay_time -= 5;
    if (fast_delay_time <= FAST_MIN_DELAY) fast_delay_time = FAST_MIN_DELAY;
  }
  fast_delay_time = FAST_MAX_DELAY;
}


// Random Strobe
void random_strobe(){
  int prev_led = NULL;
  for(int repeats = 0; repeats < (MAX_REPEATS *2); repeats++){

    int led = NULL;
    while (led == prev_led) led = random(TOTAL_OUT + 1);

    digitalWrite(led, HIGH);
    delay(50);
    digitalWrite(led, LOW);
    delay(5);
    digitalWrite(led, HIGH);
    delay(50);
    digitalWrite(led, LOW);
    delay(50);
    digitalWrite(led, HIGH);
    delay(50);
    digitalWrite(led, LOW);
    delay(5);
    digitalWrite(led, HIGH);
    delay(50);
    digitalWrite(led, LOW);

    prev_led = led;
  }
}

// Increment on Chase
void increment_chase(){
  for(int repeats = 0; repeats < (FAST_MAX_REPEATS); repeats++){
    for(int led = 0; led <= TOTAL_OUT; led ++){
      digitalWrite(led, HIGH);
      delay(delay_time);
    }
    for(int led = 0; led <= TOTAL_OUT; led ++){
      digitalWrite(led, LOW);
      delay(delay_time);
    }
    delay_time -= 50;
    if (delay_time <= MIN_DELAY) delay_time = MIN_DELAY;
  }
  delay_time = MAX_DELAY;
}

// All on pulse
void all_pulse(){
  delay_time = MAX_DELAY;
  for(int repeats = 0; repeats < (MAX_REPEATS * 2); repeats++){
    for(int led = 0; led <= TOTAL_OUT; led ++){
      digitalWrite(led, HIGH);
    }

    delay(delay_time * 2);

    for(int led = 0; led <= TOTAL_OUT; led ++){
      digitalWrite(led, LOW);
    }
    delay(delay_time *2);
    delay_time -= 10;
    if (delay_time <= MIN_DELAY) delay_time = MIN_DELAY;
  }
  delay_time = MAX_DELAY;
}
