#include "postgres.h"

#include <fstream>



bool postgres::init(std::string user, std::string host, 
      std::string password, std::string dbname){

        try
        {
             pc = new  pqxx::connection (
                "user= " + user +
                " host= " + host +
                " password= " + password +
                " dbname= " + dbname);
        }
        catch(const std::exception& e)
        {
            //std::cerr << e.what() << '\n';

            return false;
        }

        IsConnect = pc->is_open();
        return IsConnect;

}

pqxx::result postgres::require(std::string sql){
    if(!IsConnect) return pqxx::result();
    
    auto _txn = new pqxx::work(*pc);
        pqxx::result res{_txn->exec(sql)};
        _txn->abort();
        return res;
}



void postgres::transag(std::string sql) {

    if(pc == nullptr || !pc->is_open()) return;

    /*

    auto  _txn = new pqxx::work(*pc);
    _txn->exec("begin;");
    _txn->exec("savepoint f_savepoint;");
    // If the statement fails, rollback to checkpoint.
    try {
        _txn->exec(sql);
    } catch (const pqxx::sql_error& e) {
        _txn->exec("rollback to savepoint f_savepoint;");
        std::cout << e.sqlstate() << " 10 " << '\n';
    }
    _txn->exec("commit;");

    */



    {
    pqxx::work l_work(*pc);
    try {
        l_work.exec(sql);
        l_work.commit();
    } catch (const pqxx::sql_error&  e) {
        l_work.abort();
        throw;
    }
    }
}

std::string postgres::GetKey(std::string path)
{
    std::string key{""};

    std::ifstream file(path);
if (file.is_open()) {
    std::string line;
    while (std::getline(file, line)) {
        // using printf() in all tests for consistency
        //printf("%s", line.c_str());
        key = line;
    }
    file.close();
}
    
      

    return key;
}

postgres::postgres(){

}

postgres::~postgres(){
    delete pc;
}