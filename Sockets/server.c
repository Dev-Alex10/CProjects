#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>


short socket_create();
int bind_create_socket(int socket_file_descriptor);

int main(){
    int socket_file_descriptor = 0, socket = 0, client_length = 0;
    struct sockaddr_in client;
    char client_message[200] = {0};
    char message[100] = {0};

    socket_file_descriptor = socket_create();

    if (socket_file_descriptor == -1) {
        puts("Could not create socket");
        return 1;
    }

    puts("Socket created");

    if (bind_create_socket(socket_file_descriptor) < 0) {
        perror("bind failed");
        return 1;
    }

    puts("Bind done");

    listen(socket_file_descriptor, 5);

    puts("Waiting for incoming connections...");

    client_length = sizeof(struct sockaddr_in);

    socket = accept(socket_file_descriptor, (struct sockaddr *) &client, (socklen_t *) &client);

    if (socket < 0) {
        perror("Accept failed");
        return 1;
    }

    puts("Connection accepted");

    memset(client_message, '\0', sizeof(client_message));
    memset(message, '\0', sizeof(message));

    if (recv(socket, client_message, 200, 0) < 0) {
        puts("Recv failed");
    }

    printf("Received from client: %s\n", client_message);

    int i = atoi(client_message);
    i--;
    sprintf(message, "%d", i);

    close(socket);

    puts("Waiting for incoming connections...");

    socket = accept(socket_file_descriptor, (struct sockaddr *) &client, (socklen_t *) &client);

    if (socket < 0) {
        perror("Accept failed");
        return 1;
    }

    puts("Connection accepted");

    if (send(socket, message, strlen(message), 0) < 0) {
        puts("Send failed");
        return 1;
    }

    return 0;
}

short socket_create(){
    short socket_file_descriptor;

    puts("Created the socket \n");
    socket_file_descriptor = socket(AF_INET, SOCK_STREAM, 0);

    return socket_file_descriptor;
}

int bind_create_socket(int socket_file_descriptor){
    int return_value = -1;
    int client_port = 8080;

    struct sockaddr_in remote ={0};

    remote.sin_family = AF_INET;
    remote.sin_addr.s_addr = htonl(INADDR_ANY);
    remote.sin_port = htons(client_port);

    return_value = bind(socket_file_descriptor, (struct sockaddr *) &remote, sizeof(remote));

    return return_value;
}
