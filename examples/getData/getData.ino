#include <easyLStorage.h>


easyLStorage sd;
int count = 0;

void setup() {
  Serial.begin(9600);
  sd.start();  //Starts the SD Card
}

void loop() {
  String mm;
 mm = sd.getData(); //Gets the First line of data
 Serial.println(mm);
 delay(1000);

}
