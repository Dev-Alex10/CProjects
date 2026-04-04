#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

//Create a Socket for server communication
short socket_create(); 

//try to connect with server
int socket_connect(int hSocket);

// Send the data to the server and set the timeout of 20 seconds
int socket_send(int hSocket,char* request,short bytes_to_send);

//main driver program
int main(int argc, char *argv[])  {
    int hSocket = 0;

    char send_to_server[100] = {0};

    //Create socket
    hSocket = socket_create();

    if(hSocket == -1)   {
        printf("Could not create socket\n");
        return 1;
    }

    printf("Socket is created\n");

    //Connect to remote server
    if (socket_connect(hSocket) < 0) {
        perror("connect failed.\n");
        return 1;
    }

    printf("Sucessfully conected with server\n");
    printf("Enter the Message: ");
    fgets(send_to_server, 100, stdin);

    //Send data to the server
    socket_send(hSocket, send_to_server, strlen(send_to_server));

    close(hSocket);
    return 0;
}
short socket_create(){
    short hSocket;
    printf("Create the socket\n");
    hSocket = socket(AF_INET, SOCK_STREAM, 0);
    return hSocket;
}

int socket_connect(int hSocket) {
    int return_value=-1;
    int server_port = 8080;
    struct sockaddr_in remote= {0};
    remote.sin_addr.s_addr = inet_addr("127.0.0.1"); //Local Host
    remote.sin_family = AF_INET;
    remote.sin_port = htons(server_port);
    return_value = connect(hSocket,(struct sockaddr *)&remote,sizeof(struct sockaddr_in));
    return return_value;
}

int socket_send(int hSocket,char* request,short bytes_to_send) {
    int return_value = -1;
    struct timeval tv;
    tv.tv_sec = 20;  /* 20 Secs Timeout */
    tv.tv_usec = 0;

    if(setsockopt(hSocket,SOL_SOCKET,SO_SNDTIMEO,(char *)&tv,sizeof(tv)) < 0) {
        printf("Time Out\n");
        return -1;
    }
    return_value = send(hSocket, request, bytes_to_send, 0);
    return return_value;
}
