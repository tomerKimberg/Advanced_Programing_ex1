#include <sys/ioctl.h>
#include <sys/socket.h>
#include "SocketExtractor.h"

#define RECIEVE_SIZE 1024
#define SOCKET_EXTRACTOR_DEBUG 0

SocketExtractor::SocketExtractor(int fileDescriptor){
    this->fileDescriptor = fileDescriptor;
    this->failed = false;
}
int SocketExtractor::getFileDescriptor(){
    return this->fileDescriptor;
}
DataExtractor* SocketExtractor::copy(){
    return new SocketExtractor(this->fileDescriptor);
}
bool SocketExtractor::hasNext(){
    int bytesLeft = 0;
    ioctl(this->fileDescriptor, FIONREAD, &bytesLeft);
    if(SOCKET_EXTRACTOR_DEBUG){
        std::cout << "bytes left: " << bytesLeft;
    }
    return bytesLeft > 0;
}
std::string SocketExtractor::getData(){
    char buffer[RECIEVE_SIZE] = {};
    std::string data = "";
    do{
        int read_bytes = recv(this->fileDescriptor, buffer, RECIEVE_SIZE, 0);
        if(read_bytes <= 0){
            if(SOCKET_EXTRACTOR_DEBUG){
                if(read_bytes == 0){
                    std::cout << "Connection with fd: " << this->fileDescriptor << " is closed." << std::endl;
                }else{
                    std::cout << "There was an error recieving from fd: " << this->fileDescriptor << std::endl;
                }
            }
            this->failed = true;
            return "";
        }
        this->failed = false;
        data += buffer;
    }while(this->hasNext());

    return data;
}
bool SocketExtractor::fail(){
    return this->failed;
}

