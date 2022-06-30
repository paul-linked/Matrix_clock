#include <LedControl.h>
#include <Wire.h>                      
#include <DS3231.h>
RTClib rtc;


int timeInSec = 0;
int increment = 86400 / 100;
int counter = 0;
int timeHour = 0;
int timeMin = 0;
int timeSec = 0;

int DIN = 12; // connect pins
int CS = 11;                                                                                                                                                                                 
int CLK = 10;

byte d0[8] = {0x00, 0x3c, 0x24, 0x24, 0x24, 0x24, 0x3c, 0x00,};  //matrix thingies
byte d1[8] = {0x00, 0x38, 0x18, 0x18, 0x18, 0x18, 0x3c, 0x00,};
byte d2[8] = {0x00, 0x38, 0x04, 0x0c, 0x18, 0x20, 0x3c, 0x00,};
byte d3[8] = {0x00, 0x38, 0x04, 0x04, 0x18, 0x04, 0x04, 0x38,};
byte d4[8] = {0x00, 0x24, 0x24, 0x3c, 0x04, 0x04, 0x04, 0x00,};
byte d5[8] = {0x00, 0x3c, 0x20, 0x20, 0x1c, 0x04, 0x3c, 0x00,};
byte d6[8] = {0x00, 0x1c, 0x20, 0x20, 0x3c, 0x24, 0x3c, 0x00,};
byte d7[8] = {0x00, 0x3c, 0x04, 0x08, 0x08, 0x10, 0x10, 0x00,};
byte d8[8] = {0x00, 0x3c, 0x24, 0x34, 0x2c, 0x24, 0x3c, 0x00,};
byte d9[8] = {0x00, 0x3c, 0x24, 0x3c, 0x04, 0x04, 0x3c, 0x00,};

LedControl lc = LedControl(DIN, CLK, CS, 0); //set up led matrix



void setup() {

  lc.shutdown(0, false);
  lc.setIntensity(0, 5); 
  lc.clearDisplay(0);

//  if (! rtc.begin()) {
//    Serial.println("Couldn't find RTC");
//    while (1); // check if clock is connected
  }
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));   // set time


  setTime();
  counter = timeInSec / increment; // set initial time
  
}

void loop() {

  setTime();

  if (timeInSec % increment == 0) {   //check time
    counter++;
  }
  
  if (counter == 100) {    // reset
    counter = 0;
  }
  
  printTime(counter);
  
}

void setTime() { 
  DateTime ahh = rtc.now();
  timeHour = ahh.hour();
  timeMin = ahh.minute();
  timeSec = ahh.second();
  timeInSec = (timeHour * 60 * 60) + (timeMin * 60) + timeSec;
}

void printTime(int counter) {   //does digit thing idk really why i did this
  if (counter < 10) {
    printNumber(counter);
  }
  else {
    int digit1 = counter % 10;
    int digit2 = counter % 10 % 10;
    printNumber(digit1);
    delay(1000);
    printNumber(digit2);
  }
}

void printNumber(int digit) { //display number

  if (digit == 0) {
    for (int i = 0; i < 8; i++) {
      lc.setRow(0, i, d0[i]);
    }
  }
  if (digit == 1) {
    for (int i = 0; i < 8; i++) {
      lc.setRow(0, i, d1[i]);
    }
  }
  if (digit == 2) {
    for (int i = 0; i < 8; i++) {
      lc.setRow(0, i, d2[i]);
    }
  }
  if (digit == 3) {
    for (int i = 0; i < 8; i++) {
      lc.setRow(0, i, d3[i]);
    }
  }
  if (digit == 4) {
    for (int i = 0; i < 8; i++) {
      lc.setRow(0, i, d4[i]);
    }
  }
  if (digit == 5) {
    for (int i = 0; i < 8; i++) {
      lc.setRow(0, i, d5[i]);
    }
  }
  if (digit == 6) {
    for (int i = 0; i < 8; i++) {
      lc.setRow(0, i, d6[i]);
    }
  }
  if (digit == 7) {
    for (int i = 0; i < 8; i++) {
      lc.setRow(0, i, d7[i]);
    }
  }
  if (digit == 8) {
    for (int i = 0; i < 8; i++) {
      lc.setRow(0, i, d8[i]);
    }
  }
  if (digit == 9) {
    for (int i = 0; i < 8; i++) {
      lc.setRow(0, i, d9[i]);
    }
  }

}
