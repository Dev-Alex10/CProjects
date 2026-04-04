#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

//Create a Socket for server communication
short socket_create(void);


//try to connect with server
int socket_connect(int hSocket);


//receive the data from the server
int socket_receive(int hSocket,char* response,short bytes_received);


//main driver program
int main(int argc, char *argv[])  {
    int hSocket = 0, read_size = 0;

    char server_reply[200] = {0};

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
    //Received the data from the server
    read_size = socket_receive(hSocket, server_reply, 200);
    printf("Server Response : %s: read_size %d\n\n",server_reply, read_size);
    close(hSocket);
    return 0;
}

short socket_create(void) {
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

int socket_receive(int hSocket,char* response,short bytes_received) {
    int shortRetval = -1;
    struct timeval tv;
    tv.tv_sec = 20;  /* 20 Secs Timeout */
    tv.tv_usec = 0;

    if(setsockopt(hSocket, SOL_SOCKET, SO_RCVTIMEO,(char *)&tv,sizeof(tv)) < 0)    {
        printf("Time Out\n");
        return -1;
    }
    shortRetval = recv(hSocket, response, bytes_received, 0);
    printf("Response %s\n",response);
    return shortRetval;
}
