#include <sys/ioctl.h>
#include "SocketExtractor.h"

#define SOCKET_EXTRACTOR_DEBUG 0

SocketExtractor::SocketExtractor(int fileDescriptor){
    this->fileDescriptor = fileDescriptor;
    this->failed = false;
}
int SocketExtractor::getFileDescriptor(){
    return this->fileDescriptor;
}
DataExtractor* SocketExtractor::copy(){

}
bool SocketExtractor::hasNext(){
    int bytesLeft = 0;
    ioctl(this->fileDescriptor, FIONREAD, &bytesLeft);
    if(SOCKET_EXTRACTOR_DEBUG){
        std::cout << "bytes left: " << bytesLeft;
    }
    return bytesLeft > 0;
}
