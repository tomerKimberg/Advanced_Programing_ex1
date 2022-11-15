#include <iostream>
#include <vector>
#include <sstream>
#include <regex>
#include "vector_functions.h"

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
/*
input: none
output: vector<double>
this function reads a line of the following format: "1.3 2 3 4 5" and creates a vector from it
*/
std::vector<double> getVectorFromInput()
{
    std::string line = "";
    std::getline(std::cin, line);
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

int main()
{
    std::vector<double> firstVector = getVectorFromInput();
    std::vector<double> secondVector = getVectorFromInput();
    printVector(firstVector);
    printVector(secondVector);
    printVector(vectorAddition(firstVector,secondVector));
}