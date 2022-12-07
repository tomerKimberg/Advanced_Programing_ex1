//
// Created by tomer on 07/12/2022.
//

#ifndef TARGIL1_DATAEXTRACTOR_H
#define TARGIL1_DATAEXTRACTOR_H
#include <iostream>

class DataExtractor {
public:
    virtual ~DataExtractor() = 0;
    /**
 * create a new concrete DataExtractor object from one of its derivative classes
 * on the Heap and returns it's address! must save pointer to delete later!
 * @return DataExtractor pointer
 */
    virtual DataExtractor* copy() = 0;
    virtual std::string getData() = 0;
    virtual bool hasNext() = 0;
};


#endif //TARGIL1_DATAEXTRACTOR_H
