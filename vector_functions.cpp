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
/*
input: vector<double>, double
output: vector<double
this function returns a new vector, such that every value is a value from v1 to the power of the double passed as a function parameter
*/
std::vector<double> vectorPow(const std::vector<double> v1, double power)
{
    std::vector<double> newVector;
    for(double d: v1)
    {
        newVector.push_back(pow(d, power));
    }
    return newVector;
}