#ifndef easyLStorage_h
#define easyLStorage_h

#include "Arduino.h"

class easyLStorage
{
public:
  easyLStorage();
  boolean start();
  String getData();
  boolean deleteData();
  boolean cacheData(String data);
};

#endif
