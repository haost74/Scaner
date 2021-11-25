#ifndef __RUN_CPP__
#define __RUN_CPP__

#include <string>

#include "scaner.h"
#include "address.h"
#include "db/postgres.h"


class run{
private:
std::string addr{""};
postgres db;
public:
  void start();
  void open();
  void insert(std::string address, int port);
  run();
  ~run();

};
#endif