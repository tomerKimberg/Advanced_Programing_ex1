
#ifndef TARGIL1_SOCKETEXTRACTOR_H
#define TARGIL1_SOCKETEXTRACTOR_H
#include "DataExtractor.h"

class SocketExtractor : public DataExtractor{
private:
    int socket;
    bool failed;
public:
    SocketExtractor(int clientSocket);
    int getFileDescriptor;
    bool hasNext();
    std::string getData();
    bool fail();


};


#endif //TARGIL1_SOCKETEXTRACTOR_H
