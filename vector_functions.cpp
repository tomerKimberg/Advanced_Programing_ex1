//
// Created by tomer on 12/11/2022.
//

#include "vector_functions.h"
/**
 *
 * @param v1 vector given my user
 * @param v2 vector given my user
 * @return vector data, where every element in index i is the sum of those elements in vectors v1 and v2
 */
std::vector<double> vectorAddition(const std::vector<double> v1, const std::vector<double> v2){
    std::vector<double> resVector;
    if(v1.size() == v2.size()) {
        for (int index = 0; index < v1.size(); index +=1){
            resVector.push_back(v1.at(index) + v2.at(index));
        }
        return resVector;

    }
    return resVector;
}
/**
 *
 * @param v1 vector given my user
 * @param v2 vector given my user
 * @return vector data, where every element in index i is the subtraction of x[i] of v1 from y[i] of v2
 */
std::vector<double> vectorSubtraction(const std::vector<double> v1, const std::vector<double> v2){
    std::vector<double> resVector;
    if(v1.size() == v2.size()) {
        for (int index = 0; index < v1.size(); index +=1){
            resVector.push_back(v1.at(index) - v2.at(index));
        }
        return resVector;

    }
    return resVector;
}
