#ifndef easyLStorage_h
#define easyLStorage_h

#include "Arduino.h"

class easyLStorage
{
public:
  easyLStorage();
  boolean start();
  String getData();
  boolean deleteLine();
  boolean cacheData(String data);
};

#endif
