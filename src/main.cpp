#include <iostream>
#include "address.h"
#include "db/postgres.h"

#include <pqxx/pqxx>



int main()
{
    postgres db;
    bool isConnect = static_cast<bool>(db.init("tkhhpiuo", "abul.db.elephantsql.com", 
    "28-ottalQ-H-3_kLM4S3PC-qu0kct_vc", "tkhhpiuo"));
     std::cout << isConnect << '\n';


    auto res = db.require("select address from parameter_end where id = (select max(id) from parameter_end);");
    
    for(auto row : res)
    {
        // table_name
       std::cout << row["address"].c_str() << '\n';
    }

    


     db.transag("insert into ActionAddress (\"address\", \"port\") values('0.0.0.0', 80)");     
   

    
    return 0;

    address addr;
    auto adr = addr.getAddress();
    std::cout << adr << '\n';
    adr = addr.getAddress();
    std::cout << adr << '\n';
    return 0;
}