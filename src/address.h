#ifndef __ADDRESS_CPP__
#define __ADDRESS_CPP__

#include <string>
#include <iostream>
#include <vector>
#include <mutex> 

class address
{
private:
    /* data */
    int d1 = 0;
    int d2 = 0;
    int d3 = 0;
    int d4 = -1;
    void split(std::string str);
    std::mutex mtx;
public:
    address(/* args */);
    ~address();
    std::string getAddress();
    void setAddress(int d1, int d2, int d3, int d4);
    void getAddress(std::string &address);
    void split(std::string s, std::string delimiter, std::vector<std::string>& res);
};




#endif