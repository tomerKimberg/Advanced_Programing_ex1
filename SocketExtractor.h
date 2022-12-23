
#ifndef TARGIL1_SOCKETEXTRACTOR_H
#define TARGIL1_SOCKETEXTRACTOR_H
#include "DataExtractor.h"

class SocketExtractor : public DataExtractor{
private:
    int socket;
    bool failed;
public:
    SocketExtractor(int socket);
    int getFileDescriptor;
    DataExtractor* copy() override;
    bool hasNext() override;
    std::string getData() override;
    bool fail() override;


};


#endif //TARGIL1_SOCKETEXTRACTOR_H
