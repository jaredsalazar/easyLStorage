#include <easyLStorage.h>


easyLStorage sd;
int count = 0;

void setup() {
  Serial.begin(9600);
  sd.start();  //Starts the SD Card

}

void loop() {
  String message = "hello world";
sd.cacheData(message); //Gets the First line of data
 delay(1000);

}
