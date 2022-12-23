#include <sys/ioctl.h>
#include "SocketExtractor.h"

#define SOCKET_EXTRACTOR_DEBUG 0

bool SocketExtractor::hasNext(){
    int bytesLeft = 0;
    ioctl(this->fileDescriptor, FIONREAD, &bytesLeft);
    if(SOCKET_EXTRACTOR_DEBUG){
        std::cout << "bytes left: " << bytesLeft;
    }
    return bytesLeft > 0;
}
