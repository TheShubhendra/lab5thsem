#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>

#define PORT 8082

int main(){
    struct sockaddr_in address = {
        .sin_family = AF_INET,
        .sin_port = htons(TCP_PORT),
        .sin_addr.s_addr = INADDR_ANY
    };
    int s = socket(AF_INET, SOCK_STREAM,0);
    if(s == -1){
        perror("Failed to create socket");
        exit(1);
    }
    if(bind(s, (struct sockaddr*) &address, sizeof(address))<0){
	    perror("Bind failed");
	    exit(1);
    }
    if(listen(s, 100)<0){
        perror("Failed to listen on socket");
        exit(1);
    }

    socklen_t address_len = sizeof(address); 
    int client_fd = accept(s, (struct sockaddr*) &address, &address_len);
    char buffer[50];
    int a, b;
    while(recv(client_fd, buffer, sizeof(buffer), 0)>0){
        printf("%s", buffer);
        sscanf(buffer, "%d %d", &a, &b);
        printf("%d, %d", a, b);
        
        send(client_fd, "ACK\n", sizeof(4),0);
    }

    return 0;
}
