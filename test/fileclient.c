
#include "syscall.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <sys/socket.h>
// #include <netinet/in.h>
// #include <arpa/inet.h>
// #include <unistd.h>

// using ahaha.txt and b.txt to test 

#define SERVER_ADDR "127.0.0.1"
#define SERVER_PORT 5000
#define NUM_SOCKETS 1

int main(){

    char src[string_length], des[string_length];
    char* content;
    int id_src;
    int id_des;
    int len;
    int t;


    int sockets[NUM_SOCKETS];
    char message[] = "alqaeda";
    char* buffer= message;
    char* server_addr="127.0.0.1";
    int i=0;
    int port=5000;

    // doc ten file mo file

    Write("Input src filename: ",string_length,1);
    Read(src,string_length,0);

    if((id_src = Open(src,1))==-1){
        Write("Open src failed\n",string_length,1);
    }  
    else{
        len=Seek(-1,id_src);    // find length of file
        Seek(0,id_src);         // move cursor back to the beginning
        Read(content,len,id_src);   // read content into char* content
        
        Write("Input destination filename: ",string_length,1);
        Read(des,string_length,0);
        Create(des);
        if((id_des = Open(des,0))==-1){
            Write("Open des failed\n",string_length,1);
        }  
        else{

            // viet code ket noi socket ở đây 
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
                if (Send(sockets[i], content, len) < 0) {
                    Write("socket send failed: \n",string_length,1);
                }
                // CloseSocketTCP(sockets[i]);
                // printf("Socket %d closed\n", i);
            }            
            Write("Messages capitalized:\n",string_length,1);
            for (i=0; i< NUM_SOCKETS; i++){
                char reply[1024];
                if (Receive(sockets[i], reply, 1024) < 0) {
                Write("socket recv failed: \n",string_length,1);
                return -1;
            }

            // chua sua o day
                Write(" \n",string_length,1);
                Seek(0,id_des);
                Write(reply,string_length,1);
                Write("\n",string_length,1);

                t=Write(reply,len,id_des);
                if(t!=-1) Write("write success\n",string_length,1);
                if (CloseSocketTCP(sockets[i]) <0 )
                Write("socket closed failed: \n",string_length,1);
                else{

                    Write("\nsocket closed sucessfully: \n",string_length,1);}
            }


            // t=Write(content,len,id_des);    // write content to des
            
            Close(id_des);
        }
        Close(id_src);
    }

    // socket connection




    // Write("tem2 \n",string_length,1);
    return 0;
}