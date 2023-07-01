// Roll Number 22112004 (MCA) 

// Name Ruchita Ganurkar

// I attempted Q.1 which I found familiar to the assignment we have done in classroom

// Description I implemented client-server architecture to establish communication between two systems. This program is for client side. Use of port 5000 is done, user can manually change it. Message length can't be infinite hence for now 1024 bytes are defined in array form. To detect other system machine address is used. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 5000

int main(int argc, char const *argv[])
{
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *hello = "Hello from client";
    char buffer[1024] = {0};
    
    
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);


    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }
    
    
    send(sock, hello, strlen(hello), 0);
    printf("Hello message sent\n");
    
    
    valread = read(sock, buffer, 1024);
    printf("%s\n", buffer);
    return 0;
}

