#include "easyLStorage.h"
#include "LSD.h"
#include "LStorage.h"
#include "Arduino.h"

#define SDCARD LSD // use SD card DRIVE
LFile DB;
String Data = ""; // a string to hold incoming data From DB.TXT
char c;


easyLStorage::easyLStorage()
{

}
boolean easyLStorage::start(){
   Serial.println("LOADING SD CARD...");  //to check the SD Card
  if (!SDCARD.begin()){
    Serial.print("SD FAILED!"); //the Codes will stop if SD CARD Failed
    return false;
  }else{
    Serial.print("SD OK!\n");
    return true;
  }
}

String easyLStorage::getData(){
  String _DATA = "";
    DB = SDCARD.open("DB.txt"); // re-open the file for reading:
    if (DB) {
        //Serial.println("DB.txt:");
        DB.seek(0);
        // read from the file until there's nothing else in it:
        while (DB.available()) {
          c = DB.read();
          if(c == '\n'){
            break;
          }
          _DATA += c;
        }
        // close the file:
        DB.close();
    } else {
        // if the file didn't open, print an error:
        Serial.println("error opening DB.txt");
    }
    return _DATA;
}

boolean easyLStorage::cacheData(String _SDATA){
  // open the file. note that only one file can be open at a time,
    // so you have to close this one before opening another.
    DB = SDCARD.open("DB.txt", FILE_WRITE);

    // if the file opened okay, write to it:
    if (DB) {
        Serial.print("Writing to DB.txt...");
        DB.println(_SDATA);
        Serial.println(_SDATA);
        DB.close(); // close the file:
        Serial.println("done.");
    } else {

        Serial.println("error opening DB.txt"); // if the file didn't open, print an error:
    }
}

boolean deleteData(){
  Serial.println("helllooooo");
}

void data(){
  Serial.println("asdasdasdasdasd");
}
