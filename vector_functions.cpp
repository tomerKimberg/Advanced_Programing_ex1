#include <iostream>
#include <vector>
#include <math.h>
#include "vector_functions.h"

/*
input: vector<double>
output: double
this function returns a sum from all of the values in the vector
*/
double vectorSum(const std::vector<double> v1)
{
    double sum = 0;
    for(double d: v1)
    {
        sum += d;
    }
    return sum;
}
