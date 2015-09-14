#include "easyLStorage.h"
#include "LSD.h"
#include "LStorage.h"
#include "Arduino.h"

#define SDCARD LSD // use SD card DRIVE
LFile DB;
char _FILE[] = "DB.txt"; // filename with .txt extension
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
    DB = SDCARD.open(_FILE); // re-open the file for reading:
    if (DB) {
        DB.seek(0);
        // read from the file until there's nothing else in it:
        while (DB.available()) {
          c = DB.read();
          if(c == '\n'){
            break;
          }
          if(c != '\b'){
            _DATA += c;
          }
        }
        // close the file:
        DB.close();
    } else {
        // if the file didn't open, print an error:
        Serial.println("error opening txt file" );
    }
    if(_DATA == ""){
      Serial.println("No Data..." );
    }
    return _DATA;
}

boolean easyLStorage::cacheData(String _SDATA){
  // open the file. note that only one file can be open at a time,
    // so you have to close this one before opening another.
    DB = SDCARD.open(_FILE, FILE_WRITE);

    // if the file opened okay, write to it:
    if (DB) {
        Serial.print("Caching....");
        DB.println(_SDATA);
        Serial.println(_SDATA);
        DB.close(); // close the file:
        Serial.println("done.");
    } else {

        Serial.println("error opening txt file" ); // if the file didn't open, print an error:
    }
}

boolean easyLStorage::deleteData(){
  ///Preparation and Counting Part///
  int _index = 0;
    DB = SDCARD.open(_FILE); // re-open the file for reading:
    if (DB) {
        DB.seek(0);
        // read from the file until there's nothing else in it:
        while (DB.available()) {
          c = DB.read();
          if(c == '\n'){
            _index++;
            Serial.println("# of Characters " + (String) _index);
            break;
          }
          _index++;
        }
        // close the file:
        DB.close();
    } else {
        // if the file didn't open, print an error:
        Serial.println("error opening txt file" );
        return false;
    }

    ///Deleting Part///
    for(int i = 0; i < _index; i++){
  // open the file. note that only one file can be open at a time,
    // so you have to close this one before opening another.
    DB = SDCARD.open(_FILE, FILE_WRITE);

    // if the file opened okay, write to it:
    if (DB) {
        DB.seek(i);
        Serial.print(".");
        DB.print("\b");
        DB.close(); // close the file:
        delay(10);
    }else {
      Serial.println("error opening txt file" ); // if the file didn't open, print an error:
      return false;
    }
  }
  Serial.print("Deleting Success");
  return true;
}
