#include "easyLStorage.h"
#include "LSD.h"
#include "LStorage.h"
#include "Arduino.h"

#define SDCARD LSD // use SD card DRIVE
LFile DB;
String Data = ""; // a string to hold incoming data From DB.TXT


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
 DB = SDCARD.open("DB.TXT");
  if (DB) {                                // Open DB.TXT
    while (Serial.available()) {           // Loop while DB.TXT is connected
      char inChar = (char)DB.read();       // get the new byte/character
      Data += inChar;                      // add it to the string data
      if (inChar == '\n')                  // if the incoming character is a newline,
      {
      break;
      }                             // the looping will stop getting character
    }
    Serial.print(Data);                    //Print the Combined Searched Character
    return Data;                          //Send the String
    DB.close();                            //Close DB.TXT
  }else{
    Serial.println("ERROR GETTING DATA!"); // if the file didn't open, print an error:
  }
}

boolean easyLStorage::deleteLine(){
   DB = SDCARD.open("DB.TXT",FILE_WRITE);    // OPEN the DATA.TXT and set it to WRITE MODE
  if (DB){
    DB.seek(0);                             // move the cursor at the beginning of the value
    while (Serial.available()) {
      char inChar = (char)DB.read();        // get the new byte/charater
      Serial.print(inChar);                 // print the character
      if (inChar == '}'){                   // condition for the incoming charater is '{'
        DB.seek(DB.position());             // Set the cursor into the current position
        for (int d = DB.position();d>0;d--){// Loop while Cursor Position is not in the beginning of DB.TXT
          DB.print((char)8);                // Print Charater 8(BackSpace) in the DB.TXT
          if(DB.position() == 0){           // Stop Printing if the Cursor Position is in the beginning of DB.TXT
            Serial.println("Line Deleted!");
            return true;
            break;
          }
        }
        break;
      }
    }
    DB.close();
  } else {
   Serial.print("ERROR DELETING!");   //Print Error if the DATA.TXT did not open
   return false;
  }
}

boolean easyLStorage::cacheData(String data){
   DB = SDCARD.open("DB.TXT", FILE_WRITE); //OPEN the DATA.TXT and set it to WRITE MODE
  if (DB) {
    DB.println(data);                       //Write the DATA in DATA.TXT
    DB.close();                             //Close the DATA.TXT
    return true;
  } else {
   Serial.print("ERROR CACHING!");          //Print Error if the DATA.TXT did not open
   return false;
  }
}
