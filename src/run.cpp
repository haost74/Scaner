#include "run.h"

run::run(){
    addr = "0.0.0.0";
    auto key = db.GetKey("../key.txt");
    bool isConnect = static_cast<bool>(
        db.init("tkhhpiuo", "abul.db.elephantsql.com", 
                key, "tkhhpiuo"));

    if(isConnect)
    {
        auto res = db.require("select address from parameter_end where id = (select max(id) from parameter_end) limit 1;");
    
        for(auto row : res)
        {
            // table_name
        std::cout << row["address"].c_str() << '\n';

        addr = row["address"].c_str();
        }
    }

    std::cout << isConnect << '\n';         
}

run::~run(){
   db.transag("delete from parameter_end; insert into parameter_end (""address"") values ('" + addr + "')");
   //db.transag("delete from parameter_end; insert into parameter_end (""address"") values ('0.0.0.-1')");
}

void run::start(){

    address data;
    std::vector<std::string> res;
    data.split(addr, ".", res);

    auto d1 = std::stoi( res[0]);
    auto d2 = std::stoi( res[1]);
    auto d3 = std::stoi( res[2]);
    auto d4 = std::stoi( res[3]);

    data.setAddress(d1, d2, d3, d4);

    std::cout << data.getAddress() << '\n';


     try
     {
         address adr;
        //while (true)
        {
           
        }
     }
     catch(const std::exception& e)
     {
         std::cerr << e.what() << '\n';
     }
}