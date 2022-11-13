#ifndef TARGIL1_VECTOR_FUNCTION_EXEPTION_H
#define TARGIL1_VECTOR_FUNCTION_EXEPTION_H

#include <iostream>
class vector_function_exeption : public std::exception{
    public:
char * what ();

};


#endif //TARGIL1_VECTOR_FUNCTION_EXEPTION_H
