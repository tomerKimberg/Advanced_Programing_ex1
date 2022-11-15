#include "distance_algorithms.h"
/**
 * calculates distance between two non empty and same length vectors by the Canberra distance algorithm.
 * @param v1 vector<double>
 * @param v2 vector<double>
 * @return double- distance
 */
double Canberra_distane(const std::vector<double> v1, const std::vector<double> v2){
    std::vector<double> numerator_vector = vectorAbs(vectorSubtraction(v1, v2));
    std::vector<double> denominator_vector = vectorAddition(vectorAbs(v1), vectorAbs(v2));
    return vectorSum(vectorDivision(numerator_vector,denominator_vector));
    }
/**
 * calculates distance between two non empty and same length vectors by the Manhattean distance algorithm.
 * @param v1 vector<double>
 * @param v2 vector<double>
 * @return double- distance
 */
double Manhattan_distane(const std::vector<double> v1, const std::vector<double> v2){
    return vectorSum(vectorAbs(vectorSubtraction(v1,v2)));
}