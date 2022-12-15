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

#define NUMBER_OF_VECTORS 1
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
    
    std::string line = "";
    std::vector<double> inputVectors[NUMBER_OF_VECTORS];
    bool valid_input = true;
    for(int i = 0; i < NUMBER_OF_VECTORS; i++){
        std::getline(std::cin, line);
        inputVectors[i] = vectorFromString(line, valid_input);
    }
    if(!valid_input){
        std::cout << BAD_INPUT_MESSAGE << std::endl;
        return 1;
    }

    KNN knn(neighbors, metric, neighborsNum);
    std::string classofocation = knn.getClassification(inputVectors[0]);
    std::cout << classofocation << std::endl;
    std::vector<std::vector<double>> kNearsNeighbors = knn.getKNearestNeighbors(inputVectors[0]);
    for(std::vector<double> v : kNearsNeighbors){
        printVector<double>(v);
    }
    return 0;
}