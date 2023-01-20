//
// Created by tomer on 19/01/2023.
//

#include <sstream>
#include <iostream>
#include "standardIO.h"

StandardIO::StandardIO() {}

std::string StandardIO::read() {
    std::string temp;
    std::getline(std::cin, temp, '\n');
    return temp;
}

void StandardIO::write(std::string string) {
    std::cout << string;

}
