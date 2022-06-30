#include <DS3231.h>
RTClib rtc;


int timeHour = 0;
int timeMin = 0;
int timeSec = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  DateTime now = rtc.now();
  
  Serial.println(now.hour());
  Serial.println(now.minute());
  Serial.println(now.second());
//  Serial.print("Hello World!");
  setTime();
}

void loop() {
  // put your main code here, to run repeatedly:
//  DateTime now = rtc.now();
  
//  Serial.print(now.hour());
}

void setTime() { 
  DateTime ahh = rtc.now();
  timeHour = ahh.hour();
  timeMin = ahh.minute();
  timeSec = ahh.second();
  int timeInSec = (timeHour * 60) * 60;// + (timeMin * 60) + timeSec;
  Serial.println(timeInSec);
}
