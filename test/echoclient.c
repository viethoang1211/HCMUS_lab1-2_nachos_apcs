#include "syscall.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <sys/socket.h>
// #include <netinet/in.h>
// #include <arpa/inet.h>
// #include <unistd.h>

#define SERVER_ADDR "127.0.0.1"
#define SERVER_PORT 5000
#define NUM_SOCKETS 1

int main(){
    int sockets[NUM_SOCKETS];
    char message[] = "Hello from socket viet";
    char* buffer= message;
    char* server_addr="127.0.0.1";
    int i=0;
    int port=5000;
    for(i=0;i<NUM_SOCKETS;i++){
        sockets[i]= SocketTCP2();
         if (sockets[i] < 0) {
            Write("socket creation failed: \n",string_length,1);
            return -1;
        }
    }
    for (i = 0; i < NUM_SOCKETS; i++) {
        if (Connect(sockets[i],  server_addr, port) < 0) {
            Write("socket connection failed: \n",string_length,1);
            return -1;
        }
    
    }
    
    for (i = 0; i < NUM_SOCKETS; i++) {
        // sprintf(buffer, "%s%d\n", message, i);
        if (Send(sockets[i], message, 255) < 0) {
            Write("socket send failed: \n",string_length,1);
        }
        // CloseSocketTCP(sockets[i]);
        // printf("Socket %d closed\n", i);
    }
    for (i=0; i< NUM_SOCKETS; i++){
        char reply[1024];
        if (Receive(sockets[i], reply, 1024) < 0) {
        Write("socket recv failed: \n",string_length,1);
        return -1;
    }
        Write("Socket capitalized: \n",30,1);
        Write(reply,string_length,1);
        if (CloseSocketTCP(sockets[i]) <0 )
        Write("socket closed: \n",string_length,1);
    }

    // Write("tem2",string_length,1);
    return 0;
}