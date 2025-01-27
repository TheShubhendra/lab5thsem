#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/wait.h>
#define MAX_REQUESTS 10
#define BUFFER_SIZE 5000
#define TCP_PORT 3741
#define MAX_CLIENTS 20

int clients[MAX_CLIENTS];

void brodcast_message(const char* message){
    for(int i=0; i<MAX_CLIENTS; i++){
        if(clients[i]>0){
            if(send(clients[i], message, sizeof(message), 0)<0){
                perror("Failed to send message");
            }
        }
    }
}

void handle_client(int client_fd){
    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    while((bytes_read = recv(client_fd, buffer, sizeof(buffer)-1, 0))>0){
        buffer[bytes_read] = '\0';
        printf("Read %ld bytes\n", bytes_read);
        printf("%s", buffer);
        buffer[bytes_read] = '\0';
        if(send(client_fd, buffer, bytes_read + 1, 0)<0){
            perror("Failed to send response");
        }
    }
    if (bytes_read < 0) {
        perror("Failed to receive data");
    }
    close(client_fd);
    printf("Client connection closed in child process: %d\n", getpid());
    exit(EXIT_SUCCESS);
}

int main(){
    int server_fd;
    struct sockaddr_in address = {
        .sin_family = AF_INET,
        .sin_port = htons(TCP_PORT),
        .sin_addr.s_addr = INADDR_ANY
    };
    if((server_fd = socket(AF_INET, SOCK_STREAM, 0))<0){
        perror("Failed to create a socket");
        exit(1);
    }

    if(bind(server_fd, (struct sockaddr*)&address, sizeof(address))<0){
        perror("Failed to bind the socket");
        exit(1);
    }

    if(listen(server_fd, MAX_REQUESTS)<0){
        perror("Failed to listen");
        exit(1);
    }
    pid_t main_pid = getpid();
    printf("Listening for connections on process: %d\n", main_pid);

    socklen_t address_len = sizeof(address);
    int client_fd; 
    while(1){
        client_fd = accept(server_fd, (struct sockaddr*) &address, &address_len);
        if (client_fd < 0){
            perror("Failed to accept connection");
            continue;
        }

        printf("Client connected %d\n", client_fd);
        pid_t pid = fork();
        if (pid==0){
            close(server_fd);
            handle_client(client_fd);

        }else{
            printf("Handling new connection in process: %d\n", pid);
            close(client_fd);
        }
    waitpid(-1, NULL, 0);

    return 0;

    }
    


    close(server_fd);
    return 0;

}