//
// Created by tomer on 19/01/2023.
//
#include <stdio.h>
#include <c++/11/iostream>
#include "standardIO.h"

StandardIO::StandardIO() {}

std::string StandardIO::read() {
    char* temp;
    std::cin.getline(temp,std::string::npos);
    std::string result = temp;

    return result;
}

void StandardIO::write(std::string string) {
    std::cout << string;

}
