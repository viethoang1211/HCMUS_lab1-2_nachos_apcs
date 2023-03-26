#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctype.h>

#define PORT 5000

int main(int argc, char *argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    char message[1024], reply[1024];

    // Create a TCP/IP socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to a specific address and port
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 1) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for a connection...\n");

    while (1) {
        // Wait for a connection
        int client_address_length = sizeof(client_address);
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t *)&client_address_length)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        printf("Connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Receive the message from the client
        if (recv(client_socket, message, 1024, 0) < 0) {
            perror("recv failed");
            exit(EXIT_FAILURE);
        }

        printf("Received message: %s\n", message);

        // Convert the message to uppercase
        int i;
        for (i = 0; i < strlen(message); i++) {
            reply[i] = toupper(message[i]);
        }
        reply[i] = '\0';

        // Send the reply back to the client
        if (send(client_socket, reply, strlen(reply), 0) < 0) {
            perror("send failed");
            exit(EXIT_FAILURE);
        }

        printf("Sent message: %s\n", reply);

        close(client_socket);
    }

    return 0;
}

