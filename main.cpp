#include <iostream>
#include <vector>
#include <sstream>
#include <regex>
#include "vector_functions.h"
#define number_of_vectors 2
#define BAD_INPUT_MESSAGE "You entered an invalid input, please try to run the program again."

/**
 *
 * @param std::string line
 * @return bool, true if the string is a valid vector string or false if it's not.
 */
bool input_valid(std::string line)
{
    const std::regex input_regex("^(?:\\s|\\d|(?:\\d\\.\\d)|(?:\\-\\d)|(?:\\-\\d.\\d))+$");
    return std::regex_match(line, input_regex);
}
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
void measureDistance(){
    std::string line = "";
    std::vector<double> inputVectors[2];
    for(int i = 0; i < number_of_vectors; i++){
        std::getline(std::cin, line);
        if (!input_valid(line)){
            std::cout << BAD_INPUT_MESSAGE << std::endl;
            return;
        }
        inputVectors[i] = vectorFromString(line);
    }
    printVector(inputVectors[0]);
    printVector(inputVectors[1]);
    printVector(vectorAddition(inputVectors[0], inputVectors[1]));
}

int main()
{
    measureDistance();
}