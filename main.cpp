#include <iostream>
#include <vector>
#include <sstream>
#include <regex>
#include "vector_functions.h"
#include "vector_validation.h"
#include "distance_algorithms.h"
#define NUMBER_OF_VECTORS 2
#define BAD_INPUT_MESSAGE "You entered an invalid input, please try to run the program again."
/**
 *
 * @param std::string line
 * @return std::vector<double>, creates a new vector from the string
 */
std::vector<double> vectorFromString(std::string line)
{
    std::stringstream stringStream;
    stringStream.str(line);
    double inputValue = 0;
    std::vector<double> inputVector;
    while(stringStream >> inputValue)
    {
        inputVector.push_back(inputValue);
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
 * takes two lines of input, creates vectors from them and prints the distance between the vectors in 5 different ways
 */
void run(){
    std::string line = "";
    std::vector<double> inputVectors[2];
    for(int i = 0; i < NUMBER_OF_VECTORS; i++){
        std::getline(std::cin, line);
        if (!input_valid(line)){
            std::cout << BAD_INPUT_MESSAGE << std::endl;
            return;
        }
        inputVectors[i] = vectorFromString(line);
    }
    if(!vector_validation(inputVectors[0], inputVectors[1])){
        std::cout << BAD_INPUT_MESSAGE << std::endl;
        return;
    }
    printVector(inputVectors[0]);
    printVector(inputVectors[1]);
    printVector(vectorAddition(inputVectors[0], inputVectors[1]));
    std::vector<double> test = vectorDivision(inputVectors[0], inputVectors[1]);
    std::cout << "here" << std::endl;
    std::cout << Canberra_distance(inputVectors[0], inputVectors[1]) << std::endl;
    printVector(test);
    test = vectorSubtraction(inputVectors[0], inputVectors[1]);
    printVector(test);
    test.push_back(5);
}

int main()
{
    run();
}