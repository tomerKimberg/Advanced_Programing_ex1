#include <iostream>
#include <vector>
#include <sstream>
#include <regex>
#include <cmath>
#include "vector_functions.h"
#include "vector_validation.h"
#include "distance_algorithms.h"
#include "headerDistanceCalculators.h"
#include "KNN.h"
#include "DataExtractor.h"
#include "FileExtractor.h"

#define NUMBER_OF_VECTORS 2
#define MINKOWSKI_P_VALUE 2
#define INTEGER_REQUESTED_PRECISION 1
#define FLOAT_REQUESTED_PRECISION 16
#define BAD_INPUT_MESSAGE "You entered an invalid input, please try to run the program again."
//TEMPORARY
#define PATH "./datasets/wine/wine_UnClassified.csv"
//TEMPOERARY

/*
input: vector<double>
output: none
this function prints the vector with spaces between the values
*/
template <class T>
void printVector(const std::vector<T> vectorToPrint)
{
    for (T d: vectorToPrint)
    {
        std::cout << d << " ";
    }
    std::cout << std::endl;
}
/**
 * create a new vector, if input is invalid set valid_input to false
 * @param std::string line
 * @param bool& valid_input
 * @return std::vector<double>, creates a new vector from the string
 */
std::vector<double> vectorFromString(std::string line, bool& valid_input)
{
    std::stringstream stringstream;
    stringstream.str(line);
    std::string number;
    std::vector<double> inputVector;
    while(stringstream >> number && valid_input)
    {
        if (checkRealNumber(number)){
            inputVector.push_back(std::stod(number));
        }
        else{
            valid_input = false;
        }
    }
    return inputVector;   
}
/**
 * print integers and floats with the requested precision
 * @param distance the distance to be printed
 */
void printDistance(double distance){
    int percision = INTEGER_REQUESTED_PRECISION;
    if(distance != floor(distance)){
        percision = FLOAT_REQUESTED_PRECISION;
    }
    std::fixed(std::cout);
    std::cout.precision(percision);
    std::cout << distance << std::endl;
}
/**
 * takes two lines of input, creates vectors from them and prints the distance between the vectors in 5 different ways
 */
void run(){

///

CanberraDistanceCalculator ca1;
MinkowskiDistanceCalculator mi1(MINKOWSKI_P_VALUE);
ManhattanDistanceCalculator ma;
EuclideanDistanceCalculator e1;
ChebyshevDistanceCalculator ch1;

////
    std::string line = "";
    std::vector<double> inputVectors[2];
    bool valid_input = true;
    for(int i = 0; i < NUMBER_OF_VECTORS; i++){
        std::getline(std::cin, line);
        inputVectors[i] = vectorFromString(line, valid_input);
    }
    if(!vector_validation(inputVectors[0], inputVectors[1]) || !valid_input){
        std::cout << BAD_INPUT_MESSAGE << std::endl;
        return;
    }
    //printDistance(Euclidean_distance(inputVectors[0], inputVectors[1]));
    printDistance(e1.calculateDistance(inputVectors[0],inputVectors[1]));
    //printDistance(Manhattan_distance(inputVectors[0], inputVectors[1]));
    printDistance(ma.calculateDistance(inputVectors[0], inputVectors[1]));
    //printDistance(Chebyshev_distance(inputVectors[0], inputVectors[1]));
    printDistance(ch1.calculateDistance(inputVectors[0], inputVectors[1]));
    //printDistance(Canberra_distance(inputVectors[0], inputVectors[1]));
    printDistance(ca1.calculateDistance(inputVectors[0], inputVectors[1]));
    //printDistance(Minkowski_distance(inputVectors[0], inputVectors[1], MINKOWSKI_P_VALUE));
    printDistance(mi1.calculateDistance(inputVectors[0],inputVectors[1]));
}

int main()
{
    //create an DataExtractor pointer using FileExtractor
    FileExtractor fileExtractor(PATH);
    DataExtractor* extractor = &fileExtractor;
    

    delete extractor;
    std::map<std::vector<double>, std::vector<std::string>> neighbors;

    std::vector<double> d1 = {1,3};//
    std::vector<double> d2 = {3,1};//
    std::vector<double> d3 = {11.5,2.4};//
    std::vector<double> d4 = {11,2};//
    std::vector<double> d5 = {1,22};//
    std::vector<double> d6 = {1,23};//
    std::vector<std::string> calsifiaction1 = {"d"};
    std::vector<std::string> calsifiaction2 = {"f"};
    neighbors.insert({d1,calsifiaction1});
    neighbors.insert({d2,calsifiaction2});
    neighbors.insert({d3,calsifiaction2});
    neighbors.insert({d4,calsifiaction1});
    neighbors.insert({d5,calsifiaction2});
    neighbors.insert({d6,calsifiaction2});


    KNN k(neighbors,"s", 3);
    std::string classofocation = k.getClassification(std::vector<double>{0});
    std::cout << classofocation << std::endl;
    std::vector<std::vector<double>> kNearsNeighbors = k.getKNearestNeighbors(std::vector<double>{0});
    for(std::vector<double> v : kNearsNeighbors){
        printVector<double>(v);
    }
    //run();

}