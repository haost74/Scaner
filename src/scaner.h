#ifndef __SCANER_CPP__
#define __SCANER_CPP__


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>

#include <iostream>
#include <string>
#include <unistd.h>

#include <functional>


class  scaner
{
private:
    /* data */
public:
    int (*fcnPtr)();
     scaner(/* args */);
    ~ scaner();
    bool non_blocking_socket(std::string addr, int port);
    int scan(std::string addr, int port);
    void smart();    
};

#endif