/*******************************************************************************
@file     tango_spark_V0.0.1.ino
@author   Samuel Yamoah
@date     31.08.2017
@modified 31.08.2017
@brief    Tango Spark LED Dress for Cocktail night
*******************************************************************************/

// Constants Setup:
const int OUT_2 = 2;
const int PWM_1 = 3;
const int PWM_2 = 5;
const int PWM_3 = 6;
//const int PWM_4 = ;
//const int PWM_5 = ;
//const int PWM_6 = ;

const int PWMS[3] = {PWM_1, PWM_2, PWM_3};

const int MAX_REPEATS = 50;
const int MAX_DELAY = 500;
const int MIN_DELAY = 50;

// Changing variables:
int delay_time = MAX_DELAY;

void setup() {
  // put your setup code here, to run once:

  pinMode(PWM_1, OUTPUT);
  pinMode(PWM_2, OUTPUT);
  pinMode(PWM_3, OUTPUT);
  //pinMode(PWM_4, OUTPUT);
  //pinMode(PWM_5, OUTPUT);
  //pinMode(PWM_6, OUTPUT);
  Serial.begin(9600);


}

void loop() {
    
  // fade in from min to max in increments of 5 points
    for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
      // sets the value (range from 0 to 255):
      analogWrite(PWM_1, fadeValue);
      // wait for 50 milliseconds to see the dimming effect
      delay(50);
    }

    // fade out from max to min in decrements of 5 points
    for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
      // sets the value (range from 0 to 255):
      analogWrite(PWM_1, fadeValue);
      // wait for 50 milliseconds to see the dimming effect
      delay(50);
    }


      // fade in from min to max in increments of 5 points
    for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
      // sets the value (range from 0 to 255):
      analogWrite(PWM_2, fadeValue);
      // wait for 50 milliseconds to see the dimming effect
      delay(50);
    }

    // fade out from max to min in decrements of 5 points
    for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
      // sets the value (range from 0 to 255):
      analogWrite(PWM_2, fadeValue);
      // wait for 50 milliseconds to see the dimming effect
      delay(50);
    }


      // fade in from min to max in increments of 5 points
    for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
      // sets the value (range from 0 to 255):
      analogWrite(PWM_3, fadeValue);
      // wait for 50 milliseconds to see the dimming effect
      delay(50);
    }

    // fade out from max to min in decrements of 5 points
    for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
      // sets the value (range from 0 to 255):
      analogWrite(PWM_3, fadeValue);
      // wait for 50 milliseconds to see the dimming effect
      delay(50);
    }
}

//
//// Fade Chase
//void fade_chase(){
//   digitalWrite(OUT_2, HIGH);
//   delay(50);
//   digitalWrite(OUT_2, LOW);
//   delay(50);
//   digitalWrite(OUT_2, HIGH);
//   delay(50);
//   digitalWrite(OUT_2, LOW);
//   delay(50);
//  for(int i = 0; 3; i++){
//    
//  // fade in from min to max in increments of 5 points
//    for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
//      // sets the value (range from 0 to 255):
//      analogWrite(PWMS[i], fadeValue);
//      // wait for 50 milliseconds to see the dimming effect
//      delay(50);
//    }
//
//    // fade out from max to min in decrements of 5 points
//    for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
//      // sets the value (range from 0 to 255):
//      analogWrite(PWMS[i], fadeValue);
//      // wait for 50 milliseconds to see the dimming effect
//      delay(50);
//    }
//    digitalWrite(PWMS[i], LOW);
//  }
//}

