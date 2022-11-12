#include <iostream>
#include <vector>
#include <sstream>

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

int main()
{
}