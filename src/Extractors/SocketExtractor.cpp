#include <sys/ioctl.h>
#include <sys/socket.h>
#include <cstring>
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
        std::cout << "bytes left: " << bytesLeft << std::endl;
    }
    return bytesLeft > 0;
}
std::string SocketExtractor::getData(){
    if(SOCKET_EXTRACTOR_DEBUG){
        std::cout << "In getData function" << std::endl;
    }
    char buffer[RECIEVE_SIZE] = {};
    std::string data = "";
    do{
        memset(buffer, 0 ,RECIEVE_SIZE);
        if(SOCKET_EXTRACTOR_DEBUG){
            std::cout << "before recv call, data size is: " + std::to_string(data.size()) << std::endl;
        }
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
        if(SOCKET_EXTRACTOR_DEBUG){
            std::cout << "last char of buffer is: " + std::to_string(buffer[RECIEVE_SIZE - 1]) << std::endl;
            std::cout << "after recv call, data size is: " + std::to_string(data.size()) << std::endl;
        }
    }while(buffer[RECIEVE_SIZE - 1] != 0);
    if(SOCKET_EXTRACTOR_DEBUG){
        //std::cout << "after loop, data returned is: " + data << std::endl;
    }
    return data;
}
bool SocketExtractor::fail(){
    return this->failed;
}

