/*******************************************************************************
@file     tango_spark_V0.0.1.ino
@author   Samuel Yamoah
@date     31.08.2017
@modified 31.08.2017
@brief    Tango Spark LED Dress for Cocktail night
*******************************************************************************/

// Constants Setup:
const int PWM_1 = 1;
const int PWM_2 = 2;
const int PWM_3 = 3;
const int PWM_4 = 4;
const int PWM_5 = 5;
const int PWM_6 = 6;
const int MAX_REPEATS = 30;
const int MAX_DELAY = 500;
const int MIN_DELAY = 50;

// Changing variables:
int delay_time = MAX_DELAY;

void setup() {
  // put your setup code here, to run once:
  pinMode(PWM_1, OUTPUT);
  pinMode(PWM_2, OUTPUT);
  pinMode(PWM_3, OUTPUT);
  pinMode(PWM_4, OUTPUT);
  pinMode(PWM_5, OUTPUT);
  pinMode(PWM_6, OUTPUT);

}

void loop() {

  // Simple chase (maybe speedup)
  for(int repeats = 0; repeats <= MAX_REPEATS; repeats++){
    digitalWrite(PWM_1, HIGH);
    digitalWrite(PWM_2, LOW);
    digitalWrite(PWM_3, LOW);
    digitalWrite(PWM_4, LOW);
    digitalWrite(PWM_5, LOW);
    digitalWrite(PWM_6, LOW);
    delay(delay_time);
    digitalWrite(PWM_1, LOW);
    digitalWrite(PWM_2, HIGH);
    digitalWrite(PWM_3, LOW);
    digitalWrite(PWM_4, LOW);
    digitalWrite(PWM_5, LOW);
    digitalWrite(PWM_6, LOW);
    delay(delay_time);
    digitalWrite(PWM_1, LOW);
    digitalWrite(PWM_2, LOW);
    digitalWrite(PWM_3, HIGH);
    digitalWrite(PWM_4, LOW);
    digitalWrite(PWM_5, LOW);
    digitalWrite(PWM_6, LOW);
    delay(delay_time);
    digitalWrite(PWM_1, LOW);
    digitalWrite(PWM_2, LOW);
    digitalWrite(PWM_3, LOW);
    digitalWrite(PWM_4, HIGH);
    digitalWrite(PWM_5, LOW);
    digitalWrite(PWM_6, LOW);
    delay(delay_time);
    digitalWrite(PWM_1, LOW);
    digitalWrite(PWM_2, LOW);
    digitalWrite(PWM_3, LOW);
    digitalWrite(PWM_4, LOW);
    digitalWrite(PWM_5, HIGH);
    digitalWrite(PWM_6, LOW);
    delay(delay_time);
    digitalWrite(PWM_1, LOW);
    digitalWrite(PWM_2, LOW);
    digitalWrite(PWM_3, LOW);
    digitalWrite(PWM_4, LOW);
    digitalWrite(PWM_5, LOW);
    digitalWrite(PWM_6, HIGH);
    delay(delay_time);

    delay_time -= 10;
    if (delay_time <= MIN_DELAY) delay_time = MIN_DELAY;
    //if (repeats >= MAX_REPEATS) delay_time = MAX_DELAY;
  }
   delay_time = MAX_DELAY;

}
