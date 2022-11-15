#include "distance_algorithms.h"
#include "math.h"
/**
 * calculates distance between two non empty and same length vectors by the Canberra distance algorithm.
 * @param v1 vector<double>
 * @param v2 vector<double>
 * @return double- distance
 */
double Canberra_distance(const std::vector<double> v1, const std::vector<double> v2){
    std::vector<double> numerator_vector = vectorAbs(vectorSubtraction(v1, v2));
    std::vector<double> denominator_vector = vectorAddition(vectorAbs(v1), vectorAbs(v2));
    return vectorSum(vectorDivision(numerator_vector,denominator_vector));
    }
/**
 * calculates distance between two non empty and same length vectors by the Manhattan distance algorithm.
 * @param v1 vector<double>
 * @param v2 vector<double>
 * @return double- distance
 */
double Manhattan_distance(const std::vector<double> v1, const std::vector<double> v2){
    return vectorSum(vectorAbs(vectorSubtraction(v1,v2)));
}
/**
 * calculates distance between two non empty and same length vectors by the Euclidean distance algorithm.
 * @param v1 vector<double>
 * @param v2 vector<double>
 * @return double- distance
 */
double Euclidean_distance(const std::vector<double> v1, const std::vector<double> v2){
    return sqrt(vectorSum(vectorPow(vectorSubtraction(v1, v2), 2)));
}
/**
 * calculates distance between two non empty and same length vectors by the Minkowski distance algorithm.
 * @param v1 vector<double>
 * @param v2 vector<double>
 * @return double- distance
 */
double Minkowski_distance(const std::vector<double> v1, const std::vector<double> v2,double  P){
    return pow(vectorSum(vectorPow(vectorAbs(vectorSubtraction(v1, v2)), P)), (1 / P));
}
/**
 * calculates distance between two non empty and same length vectors by the Chebyshev distance algorithm.
 * @param v1 vector<double>
 * @param v2 vector<double>
 * @return double- distance
 */
double Chebyshev_distance(const std::vector<double> v1, const std::vector<double> v2){
    return  vectorMax(vectorAbs(vectorSubtraction(v1, v2)));
}