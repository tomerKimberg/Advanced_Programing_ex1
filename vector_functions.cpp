#include <iostream>
#include <vector>
#include <math.h>
#include "vector_functions.h"
#include "vector_function_exeption.h"

/**
 *
 * @param v1  vector<double>
 * @return double. this function returns a sum from all of the values in the vector
 */
double vectorSum(const std::vector<double> v1) throw(vector_function_exeption){
    if(!v1.empty()) {
        double sum = 0;
        for (double d: v1) {
            sum += d;
        }
        return sum;
    }
    throw vector_function_exeption();
}

/**
 *
 * @param v1 vector<double>
 * @return double, this function returns the maximum value in the vector
 */
double vectorMax(const std::vector<double> v1) throw(vector_function_exeption){
    if(!v1.empty()) {
        double max = v1[0];
        for (double d: v1) {
            if (d > max) {
                max = d;
            }
        }
    }
    throw vector_function_exeption();
}

/**
 *
 * @param v1 vector<double>, double
 * @param power
 * @return vector<double, this function returns a new vector,
 * such that every value is a value from v1 to the power of the double passed as a function parameter
 */
std::vector<double> vectorPow(const std::vector<double> v1, double power)throw(vector_function_exeption){
    if(!v1.empty()) {
        std::vector<double> newVector;
        for (double d: v1) {
            newVector.push_back(pow(d, power));
        }
    }
    throw vector_function_exeption();
}


/**
 *
 * @param v1 vector given my user
 * @param v2 vector given my user
 * @return vector data, where every element in index i is the sum of those elements in vectors v1 and v2
 */
std::vector<double> vectorAddition(const std::vector<double> v1, const std::vector<double> v2)
throw(vector_function_exeption){
    std::vector<double> resVector;
    if(v1.size() == v2.size()) {
        for (int index = 0; index < v1.size(); index +=1){
            resVector.push_back(v1.at(index) + v2.at(index));
        }
        return resVector;

    }
    //the vectors are not the same size.
    throw vector_function_exeption();
}
/**
 *
 * @param v1 vector given my user
 * @param v2 vector given my user
 * @return vector data, where every element in index i is the subtraction of x[i] of v1 from y[i] of v2
 */
std::vector<double> vectorSubtraction(const std::vector<double> v1, const std::vector<double> v2)
throw(vector_function_exeption){
    std::vector<double> resVector;
    if(v1.size() == v2.size()) {
        for (int index = 0; index < v1.size(); index +=1){
            resVector.push_back(v1.at(index) - v2.at(index));
        }
        return resVector;

    }
    //vectors are not the same size
    throw vector_function_exeption();
}

/**
 *
 * @param v1 vector given my user
 * @param v2 vector given my user
 * @return vector data, where every element in index i is the absolute value of that element at index i in v1
 */
std::vector<double> vectorAbs(const std::vector<double> v1) throw(vector_function_exeption){
    if(!v1.empty()) {
        std::vector<double> resVector;
        for (double d: v1) {
            resVector.push_back(abs(d));
        }
        return resVector;
    }
    throw vector_function_exeption();
}
/**
 *
 * @param v1 vector given my user
 * @param v2 vector given my user
 * @return vector data, where every element in index i is the division of x[i] of v1 from y[i] of v2.
 * if the vectors are not the same length, an custom exception is thrown.
 */
std::vector<double> vectorDivision(const std::vector<double> v1, const std::vector<double> v2) throw(std::exception){
    std::vector<double> resVector;
    if(v1.size() == v2.size()) {
        for (int index = 0; index < v1.size(); index +=1){
            if(v1.at(index) == 0) {
                resVector.push_back(0);
            }
            else{
                resVector.push_back(v1.at(index) / v2.at(index));
            }
        }
        return resVector;

    }
    //the vectors are not the same size.
    throw vector_function_exeption();
}