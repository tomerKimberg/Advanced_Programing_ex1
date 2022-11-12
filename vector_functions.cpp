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
/*
input: vector<double>
output: double
this function returns the maximum value in the vector
*/
double vectorMax(const std::vector<double> v1)
{
    double max = v1[0];
    for(double d: v1)
    {
        if (d > max)
        {
            max = d;
        }
    }
    return max;
}
