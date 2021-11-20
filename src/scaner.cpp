

#include "scaner.h"
// https://stackoverflow.com/questions/2597608/c-socket-connection-timeout

 scaner:: scaner(/* args */)
{
}

 scaner::~ scaner()
{
}


int scaner::scan(std::string addr, int port) {

    struct sockaddr_in address;  /* the libc network address data structure */
    short int sock = -1;         /* file descriptor for the network socket */
    fd_set fdset;
    struct timeval tv;


    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(addr.c_str()); //inet_addr(addr); /* assign the address */
    address.sin_port = htons(port);            /* translate int2port num */

    sock = socket(AF_INET, SOCK_STREAM, 0);
    fcntl(sock, F_SETFL, O_NONBLOCK);

    int isConn = connect(sock, (struct sockaddr *)&address, sizeof(address));

    std::cout << isConn << '\n';

    FD_ZERO(&fdset);
    FD_SET(sock, &fdset);
    tv.tv_sec = 10;             /* 10 second timeout */
    tv.tv_usec = 0;

    if (select(sock + 1, NULL, &fdset, NULL, &tv) == 1)
    {
        int so_error;
        socklen_t len = sizeof so_error;

        getsockopt(sock, SOL_SOCKET, SO_ERROR, &so_error, &len);

        if (so_error == 0) {
            //printf("%s:%d is open\n", addr, port);
            std::cout << "open " << addr << " " << port << '\n';
        }
    }

    close(sock);
    return 0;
}

void scaner::non_blocking_socket(char* addr, int port)
{
	int sockfd;
	struct addrinfo hints, *res;

    // address.sin_addr.s_addr = inet_addr(addr); /* ass

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

    fd_set fdset;
    struct timeval tv;

	getaddrinfo(addr, std::to_string(port).c_str(), &hints, &res);

	// make a socket:

	sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
	//fcntl(sockfd, F_SETFL, O_NONBLOCK);

	 fcntl(sockfd, F_SETFL, O_NONBLOCK);

	// connect!
	auto idCon = connect(sockfd, res->ai_addr, res->ai_addrlen);


    std::cout << idCon << '\n';


	 FD_ZERO(&fdset);
	 FD_SET(sockfd, &fdset);
		tv.tv_sec = 7;             /* 10 second timeout */
		tv.tv_usec = 0;

		if (select(sockfd + 1, NULL, &fdset, NULL, &tv) == 1)
		{
			int so_error;
			socklen_t len = sizeof so_error;
			 getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &so_error, &len);
			 if (so_error == 0) {
				printf("%s:%d is open\n", addr, port);
			}
		}

	std::cout << idCon << '\n';

	close(sockfd);
	close(idCon);
	freeaddrinfo(res); // free the linked list
}