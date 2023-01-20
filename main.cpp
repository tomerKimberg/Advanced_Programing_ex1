#include <iostream>
#include <vector>
#include <sstream>
#include <regex>
#include <cmath>
#include "src/Extractors/StringExtractor.h"
#include "src/Command/Command1.h"
#include "src/Command/standardIO.h"


#define NUMBER_OF_VECTORS 1
#define NUMBER_OF_ARGUMENTS 4
#define MINKOWSKI_P_VALUE 2
#define ARGS_VARIABLE_K 1
#define ARGS_VARIABLE_PATH 2
#define ARGS_VARIABLE_METRIC 3
#define INTEGER_REQUESTED_PRECISION 1
#define FLOAT_REQUESTED_PRECISION 16
#define INPUT_BAD_MESSAGE "You entered an invalid input, please try to run the program again."
#define ARGS_BAD_MESSAGE "Bad arguments, exiting."
#define MAIN_DEBUG 0
/*
input: vector<double>
output: none
this function prints the vector with spaces between the values
*/
#include "src/ValidationFuncs/arguments_validation.h"
#include "src/Command/Command2.h"
#include "src/Command/Command3.h"
#include "src/Command/Command4.h"
#include "src/CLI/CLI.h"


int main(int argc, char** argv)
{
    StandardIO standardIo;
    CLI cli((DefaultIO*) &standardIo);
    cli.start();



    return 0;
}