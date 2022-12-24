#include <cstring>
#include <csignal>
#include "SocketConnection.h"

SocketConnection::SocketConnection(const int portNum, unsigned long ip, int domain, int type){
    this->sock = socket(domain, type, 0);
    if(this->sock < 0 ){
        perror("error creating socket");
    }
    else{

        memset(&this->sin, 0, sizeof(this->sin));
        this->sin.sin_family = domain;
        this->sin.sin_addr.s_addr = ip;
        this->sin.sin_port = htons(portNum);
        this->socketExtractor = SocketExtractor(this->sock);
    }
}


SocketConnection::SocketConnection(std::pair<int, sockaddr_in> sockEssential) {
    this->sock = sockEssential.first;
    if(this->sock < 0 ){
        perror("error creating socket");
    }
    this->sin = sockEssential.second;
    this->socketExtractor = SocketExtractor(this->sock);
}

int SocketConnection::bind() {
    if(::bind(this->sock,(struct sockaddr *) &this->sin, sizeof (this->sin))<0){
        perror("error binding socket");
    }
}

int SocketConnection::listen() {
    int error = ::listen(this->sock, NUM_CONNECTIONS);

    if(error < 0) {
        perror("error listening to a socket");
    }
}

std::pair<int, sockaddr_in> SocketConnection::accept() {
    sockaddr_in client_in;
    unsigned int addr_len = sizeof(client_in);
    int client_sock = ::accept(this->sock, (struct sockaddr *) &client_in, &addr_len);
    if(client_sock < 0){
        perror("error accepting client");
    }
    return std::pair<int, sockaddr_in>(client_sock, client_in);
}

int SocketConnection::connect(){
    int connection = ::connect(this->sock, (struct sockaddr *) &this->sin, sizeof(this->sin));
    if(  connection < 0){
        perror("error connecting to socket");
    }
}

std::string SocketConnection::receive() {
    return this->socketExtractor.getData();
}

int SocketConnection::send(const std::string& message) {
    //create an array of bytes from the message to send
    unsigned int size = message.length();
    char data_addr[size + 1];
    memset(data_addr, 0 ,size + 1);
    strcpy(data_addr, message.c_str());
    int send_bytes =  ::send(this->sock, data_addr, size+1, 0);
    if(send_bytes < 0){
        perror("error sending message");
    }
    return send_bytes;
}

int SocketConnection::close() {
    return ::close(this->sock);
}

bool SocketConnection::receiveNotFail(){
    return this->socketExtractor.fail();
}

int SocketConnection::getSock() {
    return this->sock;
}

