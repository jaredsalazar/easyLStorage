#include <easyLStorage.h>


easyLStorage sd;
int count = 0;

void setup() {
  Serial.begin(9600);
  sd.start();  //Starts the SD Card
  sd.deleteData(); //delete first line of data from sd card
 delay(1000);

}

void loop() {


}
