#include <iostream>
#include <vector>
#include <sstream>
#include <regex>
#include <cmath>
#include "vector_functions.h"
#include "vector_validation.h"
#include "distance_algorithms.h"
#define NUMBER_OF_VECTORS 2
#define MINKOWSKI_P_VALUE 2
#define INTEGER_REQUESTED_PRECISION 1
#define FLOAT_REQUESTED_PRECISION 16
#define BAD_INPUT_MESSAGE "You entered an invalid input, please try to run the program again."

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
/*
input: vector<double>
output: none
this function prints the vector with spaces between the values
*/
void printVector(const std::vector<double> vectorToPrint)
{
    for (double d: vectorToPrint)
    {
        std::cout << d << " ";
    }
    std::cout << std::endl;
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
    printDistance(Euclidean_distance(inputVectors[0], inputVectors[1]));
    printDistance(Manhattan_distance(inputVectors[0], inputVectors[1]));
    printDistance(Chebyshev_distance(inputVectors[0], inputVectors[1]));
    printDistance(Canberra_distance(inputVectors[0], inputVectors[1]));
    printDistance(Minkowski_distance(inputVectors[0], inputVectors[1], MINKOWSKI_P_VALUE));
}

int main()
{
    run();
}