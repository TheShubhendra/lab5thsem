#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#define MAX_REQUESTS 10
#define BUFFER_SIZE 50
#define PORT 3737

int main(){
    int sockfd;
    struct sockaddr_in address = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0))<0){
        perror("Failed to create a socket");
        exit(1);
    }

    if(bind(sockfd, &address, sizeof(address))<0){
        perror("Failed to bind the socket");
        exit(1);
    }

    if(listen(sockfd, MAX_REQUESTS)<0){
        perror("Failed to listen");
        exit(1);
    }
    printf("Listening for connections\n");

    socklen_t address_len = sizeof(address);
    int client_fd; 
    if((client_fd = accept(sockfd, (struct sockaddr*) &address, &address_len))<0){
        perror("Failed to accept connection");
        exit(1);
    }
    printf("Client connected %s\n", client_fd);

    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    while((bytes_read = recv(sockfd, buffer, sizeof(buffer), 0))){
        printf("Read %s bytes\n", bytes_read);
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;

}