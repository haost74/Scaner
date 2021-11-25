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

void run::open()
{

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

    scaner sn;
    auto str = data.getAddress();
     auto isRes = sn.non_blocking_socket("80.87.197.181", 22);
    //auto isRes = sn.non_blocking_socket("0.0.0.0", 1);
    std::cout << isRes << '\n';

     try
     {
         address adr;
         int i =0;
        while (true)
        {
            auto str = data.getAddress();
            insert(str, 0);
            break;
            if(i > 10)
            {
                i = 0;
                std::cout << str << '\n';
            }
            ++i;
            auto isRes = sn.non_blocking_socket(str, 22);
            if(isRes)
            std::cout << isRes << '\n';
            
        }
     }
     catch(const std::exception& e)
     {
         std::cerr << e.what() << '\n';
     }
}


void run::insert(std::string address, int port){    
   postgres db;

auto key = db.GetKey("../key.txt");
    bool isConnect = static_cast<bool>(db.init("tkhhpiuo", "abul.db.elephantsql.com", 
    key, "tkhhpiuo"));

   std::string isEg{"-1"};
   address = "0.0.0.0"; port = 81;

   // select * from actionaddress where address = '0.0.0.0' and port = 80;
   auto res = db.require("select count(*) as count from ActionAddress where address = '"    
                        + address + "' and port = " + std::to_string(port) + ";");


std::cout << res.size() << " <-----" << '\n';
   for(auto row : res)
    {
       isEg  = row["count"].c_str();
    }


    std::cout << address << " " << port << " " << isEg << '\n';
 
    if(isEg == "0") return;
  std::string sql = "insert into ActionAddress (\"address\", \"port\") values('" + address +"', " 
  + std::to_string(port) + ")";
   db.transag(sql);
}