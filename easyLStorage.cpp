#include "easyLStorage.h"
#include "LSD.h"
#include "LStorage.h"
#include "Arduino.h"

#define SDCARD LSD // use SD card DRIVE
LFile DB;
<<<<<<< HEAD
char _FILE[] = "DB.txt"; // filename with .txt extension
=======
String Data = ""; // a string to hold incoming data From DB.TXT
>>>>>>> FETCH_HEAD
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
<<<<<<< HEAD
    DB = SDCARD.open(_FILE); // re-open the file for reading:
    if (DB) {
=======
    DB = SDCARD.open("DB.txt"); // re-open the file for reading:
    if (DB) {
        //Serial.println("DB.txt:");
>>>>>>> FETCH_HEAD
        DB.seek(0);
        // read from the file until there's nothing else in it:
        while (DB.available()) {
          c = DB.read();
          if(c == '\n'){
<<<<<<< HEAD
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
=======
            break;
          }
          _DATA += c;
>>>>>>> FETCH_HEAD
        }
        // close the file:
        DB.close();
    } else {
        // if the file didn't open, print an error:
<<<<<<< HEAD
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
=======
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
>>>>>>> FETCH_HEAD
}
