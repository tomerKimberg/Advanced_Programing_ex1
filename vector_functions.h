//
// Created by tomer on 12/11/2022.
//

#ifndef TARGIL1_VECTOR_FUNCTIONS_H
#define TARGIL1_VECTOR_FUNCTIONS_H
#include <iostream>
#include <vector>
#include "vector_function_exeption.h"

double vectorSum(const std::vector<double> v1)throw(vector_function_exeption);
double vectorMax(const std::vector<double> v1) throw(vector_function_exeption);
std::vector<double> vectorPow(const std::vector<double> v1, double power)throw(vector_function_exeption);
std::vector<double> vectorSubtraction(const std::vector<double> v1, const std::vector<double> v2)
throw(vector_function_exeption);
std::vector<double> vectorAbs(const std::vector<double> v1)throw(vector_function_exeption);
std::vector<double> vectorAddition(const std::vector<double> v1, const std::vector<double> v2)
throw(vector_function_exeption);
std::vector<double> vectorDivision(const std::vector<double> v1, const std::vector<double> v2) throw(std::exception);


#endif //TARGIL1_VECTOR_FUNCTIONS_H
