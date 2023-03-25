#include "syscall.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_ADDR "127.0.0.1"
#define SERVER_PORT 8080
#define NUM_SOCKETS 4

int main(){
    int sockets[NUM_SOCKETS];
    for(int i=0;i<NUM_SOCKETS;i++){
        sockets[i]= SocketTCP();
         if (sockets[i] < 0) {
            printf("socket creation failed");
            return -1;
        }
    }
    // memset(&server_address, 0, sizeof(server_address));
    // server_address.sin_family = AF_INET;
    // server_address.sin_port = htons(SERVER_PORT);
    // server_address.sin_addr.s_addr = inet_addr(SERVER_ADDR);
    return 0;
    for (int i = 0; i < NUM_SOCKETS; i++) {
        if (Connect(sockets[i],  inet_addr(SERVER_ADDR), SERVER_PORT) < 0) {
            printf("socket connection failed");
            return -1;
        }
    printf("Socket %d connected to server\n", i);
    }
    char message[] = "Hello from socket ";
    for (int i = 0; i < NUM_SOCKETS; i++) {
    char buffer[1024];
    sprintf(buffer, "%s%d\n", message, i);
        if (Send(sockets[i], buffer, strlen(buffer)) < 0) {
            printf("socket connection failed");
        }
        // CloseSocketTCP(sockets[i]);
        // printf("Socket %d closed\n", i);
    }
    for (int =0; i< NUM_SOCKETS; i++){
        char reply[1024];
        if (Receive(sockets[i], reply, 1024, 0) < 0) {
        printf("recv faied");
        return -1;
    }
        printf("Capitalized message: %s", reply);
        if (CloseSocketTCP(sockets[i]) <0 )
        printf("Socket %d closed\n", i);
    }
    return 0;
}
