#ifndef __ADDRESS_CPP__
#define __ADDRESS_CPP__

#include <string>
#include <iostream>

class address
{
private:
    /* data */
    int d1 = 0;
    int d2 = 0;
    int d3 = 0;
    int d4 = -1;
    void split(std::string str);
public:
    address(/* args */);
    ~address();
    std::string getAddress();
    void setAddress(int d1, int d2, int d3, int d4);

};




#endif