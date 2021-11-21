#include "address.h"


std::string address::getAddress(){
    if(d1 == 255 && d2 == 255 && d3 == 255 && d4 > 255)
    {
        d1 = 0; d2 = 0; d3 = 0; d4 = -1;
    }

    if(d4 < 255)
    {
        ++d4;
    }
    else if(d3 < 255)
    {
        d4 = 0;
        ++d3;
    }
    else if(d2 < 255)
    {
        d3 = 0;
        ++d2;
    }
    else if(d1 < 255)
    {
        d2 = 0;
        ++d1;
    }

    return std::to_string(d1) + "." + std::to_string(d2) + "." + std::to_string(d3) + "." + std::to_string(d4);
}

void address::setAddress(int d1, int d2, int d3, int d4){
  this->d1 = d1; this->d2 = d2; this->d3 = d3; this->d4 = d4;
}

void split(std::string s, std::string delimiter){
    s = "scott>=tiger>=mushroom";
    delimiter = ">=";

size_t pos = 0;
std::string token;
while ((pos = s.find(delimiter)) != std::string::npos) {
    token = s.substr(0, pos);
    std::cout << token << std::endl;
    s.erase(0, pos + delimiter.length());
}
std::cout << s << std::endl;
}

address::address(/* args */)
{
}

address::~address()
{
}