/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-ultrasonic-sensor-servo-motor
 */

#include <Servo.h>
Servo s1;
const int s=2;
// variables will change:
const int TRIG_PIN  = 6;  // Arduino pin connected to Ultrasonic Sensor's TRIG pin
const int ECHO_PIN  = 7;  // Arduino pin connected to Ultrasonic Sensor's ECHO pin
const int DISTANCE_THRESHOLD = 100; // centimeters
void setup() {
  Serial.begin (9600);       // initialize serial port
  pinMode(TRIG_PIN, OUTPUT); // set arduino pin to output mode
  pinMode(ECHO_PIN, INPUT);  // set arduino pin to input mode
  s1.attach(9);   // attaches the servo on pin 9 to the servo object
  s1.write(0);
}

void loop() {
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // measure duration of pulse from ECHO pin
  float duration_us = pulseIn(ECHO_PIN, HIGH);
  // calculate the distance
  float distance_cm = 0.017 * duration_us;

  if(distance_cm < DISTANCE_THRESHOLD){

    for(int i=0; i<=90; i++){
      s1.write(i);
      delay(5);
    }

    for(int i=90; i>=0; i--){
      s1.write(i);
      delay(5);
    }

  
  }
    
  else{
    s1.write(0);  // rotate servo motor to 0 degree
    delay(50);
  }

}

