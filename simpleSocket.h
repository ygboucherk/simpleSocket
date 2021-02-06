#include <string.h>
#include <stdbool.h>

#if defined (WIN32)
    #include <winsock2.h>
    typedef int socklen_t;
#elif defined (linux)
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <unistd.h>
    #define INVALID_SOCKET -1
    #define SOCKET_ERROR -1
    #define closesocket(s) close(s)
    typedef int SOCKET;
    typedef struct sockaddr_in SOCKADDR_IN;
    typedef struct sockaddr SOCKADDR;
#endif

#include <stdio.h>
#include <stdlib.h>


int newSocket(char *serverip, int PORT) {
    #if defined (WIN32)
        WSADATA WSAData;
        int erreur = WSAStartup(MAKEWORD(2,2), &WSAData);
    #else
        int erreur = 0;
    #endif

    SOCKET sock;
    SOCKADDR_IN sin;
    char buffer[] = "";

    if(!erreur)
    {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        sin.sin_addr.s_addr = inet_addr(serverip);
        sin.sin_family = AF_INET;
        sin.sin_port = htons(PORT);
        if(connect(sock, (SOCKADDR*)&sin, sizeof(sin)) != SOCKET_ERROR)
        {
            if(recv(sock, buffer, 64, 0) != SOCKET_ERROR) {
                printf("%s", buffer);
                return sock;
            }
        }
        else
        {
            printf("Server error\n");
        }
        closesocket(sock);

        #if defined (WIN32)
            WSACleanup();
        #endif
    }
}
