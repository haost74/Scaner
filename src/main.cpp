#include <iostream>
#include "address.h"
#include "db/postgres.h"
#include "scaner.h"
#include "run.h"

#include <pqxx/pqxx>
#include <thread>



int main()
{
    run r;
r.open();
    
    std::thread th1 ([&]()
    {
        r.start();
    });
    th1.detach();

    std::thread th2 ([&]()
    {
        r.start();
    });
    th2.detach();

    std::thread th3 ([&]()
    {
        r.start();
    });
    th3.detach();

    std::thread th4 ([&]()
    {
        r.start();
    });
    th4.detach();



    std::string h {""};
    while (h != "h")
    {
        std::cin >> h;
    }
    

   
    return 0;

    scaner sn;
    //sn.non_blocking_socket("80.87.197.181", 22);
    sn.non_blocking_socket("0.0.0.1", 1);
    //sn.smart();
    return 0;
    postgres db;

    auto key = db.GetKey("../key.txt");
    bool isConnect = static_cast<bool>(db.init("tkhhpiuo", "abul.db.elephantsql.com", 
    key, "tkhhpiuo"));
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