
#ifndef TARGIL1_SOCKETEXTRACTOR_H
#define TARGIL1_SOCKETEXTRACTOR_H
#include "DataExtractor.h"

class SocketExtractor : public DataExtractor{
private:
    int fileDescriptor;
    bool failed;
public:
    SocketExtractor(int fileDescriptor);
    int getFileDescriptor();
    DataExtractor* copy() override;
    bool hasNext() override;
    std::string getData() override;
    bool fail() override;


};


#endif //TARGIL1_SOCKETEXTRACTOR_H
