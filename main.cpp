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
#include "getNeighbors.h"
#include "DataExtractor.h"
#include "FileExtractor.h"

#define NUMBER_OF_VECTORS 2
#define NUMBER_OF_ARGUMENTS 4
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
 * @param int argc, amount of the program arguments
 * @param char** argv - the arguments values
 * @return bool - wether the arguments are valid or not
*/
bool validArgs(int argc, char** argv){
    if(NUMBER_OF_ARGUMENTS != argc){
        std::cout << "wrong amount of arguments were passed to the program." << std:: endl;
        return false;
    }
    int k = std::stoi(argv[1]);
    if(k <= 0){
        std::cout << "bad K parameter, needs to be a positive integer" << std:: endl;
        return false;
    }
    std::string metric = argv[3];
    std::vector<std::string> VALID_METRICS = {"CAN","CHB","AUC","MAN","MIN"};
    auto metricInVector = std::find(VALID_METRICS.begin(), VALID_METRICS.end(), metric);
    if(metricInVector == VALID_METRICS.end()){
        std::cout << "bad metric parameter, needs to be a part of the list:" << std:: endl;
        printVector<std::string>(VALID_METRICS);
        return false;
    }

    return true;
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

int main(int argc, char** argv)
{
    if(!validArgs(argc, argv)){
        std::cout << "bad argument, exiting" << std::endl;
        return 1;
    }
    int neighborsNum = std::stoi(argv[1]);
    std::string path = argv[2];
    std::string metric = argv[3];

    //create an DataExtractor pointer using FileExtractor
    FileExtractor fileExtractor(path);
    DataExtractor* extractor = &fileExtractor;

    getNeighbors get(extractor);       
    std::map<std::vector<double>, std::vector<std::string>> neighbors = get.getNeighborsInMap();

    KNN knn(neighbors, metric, neighborsNum);
    std::string classofocation = knn.getClassification(std::vector<double>{13.88,1.89,2.59,15,101,3.25,3.56,.17,1.7,5.43,.88,3.56,1095});
    std::cout << classofocation << std::endl;
    std::vector<std::vector<double>> kNearsNeighbors = knn.getKNearestNeighbors(std::vector<double>{13.88,1.89,2.59,15,101,3.25,3.56,.17,1.7,5.43,.88,3.56,1095});
    for(std::vector<double> v : kNearsNeighbors){
        printVector<double>(v);
    }
    //run();

}