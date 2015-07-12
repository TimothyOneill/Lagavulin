// Lagavulin.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include "iostream"
#include "Lagavulin.h"
#include <string.h>
#include <WinSock2.h>

int _tmain(int argc, _TCHAR* argv[])
{
    return 0;
}

void networkHelpers()
{
    unsigned long ipAddress = inet_addr("82.27.232.137");

    struct in_addr addr;
    addr.S_un.S_addr = htonl(0x50102030);

    char ipAddressString[16];
    strcpy_s (ipAddressString, inet_ntoa(addr));

    printf("0x%08x 0x%08x %s \n:", ipAddress, addr.S_un.S_addr, ipAddressString);
}

void dnsFunctions()
{
    const char *host = "www.contoso.com";
    struct hostent *pHostEnt = gethostbyname(host);

    if (pHostEnt)
    {
        struct sockaddr_in addr;
        memcpy (&addr.sin_addr, pHostEnt->h_addr, pHostEnt->h_length);
        printf("Address of %s is 0x%08x \n", host, ntohl(addr.sin_addr.s_addr));
    }
    else
    {
        fprintf(stderr, "No Such Host");
    }
}

void creatingSockets()
{
    WORD wVersionRequested = MAKEWORD(2,2); //set to 2.2
    WSADATA wsaData;
    int err = WSAStartup(wVersionRequested, &wsaData);

    //Creating the socket
    SOCKET sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock == INVALID_SOCKET)
    {
        //handle some error!
    }

    //Settings the sock options
    int value = 1;
    setsockopt(sock, IPPROTO_TCP, TCP_NODELAY, (char*)&value, sizeof(value)); //Stops internal buffering mechanism lower bandwidth but higher output
    setsockopt(sock,  SOL_SOCKET, SO_DONTLINGER, (char*)&value, sizeof(value)); //Speeds up closing down of sockets
    setsockopt(sock,  SOL_SOCKET, SO_KEEPALIVE, (char*)&value, sizeof(value)); //sends a packet at a regular interval if no other data has been sent

    //setting the sock to blocking/non-blocking
    unsigned long val = 1; //1 = non blocking, 0 = blocking
    ioctlsocket(sock, FIONBIO, &val);

    //Socket connection
    struct sockaddr_in sa;
    sa.sin_family = AF_INET;
    //sa.sin_addr.s_addr = htonl();
    //sa.sin_port = htons(port);

    if (connect(sock, (struct sockaddr *)&sa, sizeof(sa)))
    {

    }
}

