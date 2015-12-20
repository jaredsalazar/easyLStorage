#ifndef easyLStorage_h
#define easyLStorage_h

#include "Arduino.h"

class easyLStorage
{
public:
  easyLStorage();
  boolean start(String _name);
  String getData(String _name);
  boolean deleteData(String _name);
  boolean cacheData(String data, String _name);
  void data();
};

#endif
