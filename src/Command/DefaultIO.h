//
// Created by tomer on 17/01/2023.
//

#ifndef TARGIL1_DEFAULTIO_H
#define TARGIL1_DEFAULTIO_H

#include <string>

class DefaultIO {
public:
    /**
     * read from source using io
     * @return std::string
     */
    virtual std::string read() = 0;
    /**
     * write to source using io
     */
    virtual void write(std::string) = 0;
    /** ### might want to remove
     * close an IO, return a close code
     * @return int
     */
    virtual int closeIO() = 0;
};


#endif //TARGIL1_DEFAULTIO_H
