#ifndef __POSTRGRES_CPP__
#define __POSTRGRES_CPP__

#include <string>
#include <pqxx/pqxx>

#include <iostream>

class postgres{

    private:
      std::string user = "";
      std::string host = "";
      std::string password = "";
      std::string dbname = "";
      pqxx::connection *pc = nullptr;
      bool IsConnect = false;
 
    public:
      
      bool init(std::string user, std::string host, 
      std::string password, std::string dbname);
      pqxx::result require(std::string sql);
      void transag(std::string sql);
      postgres();
      ~postgres();
};

#endif