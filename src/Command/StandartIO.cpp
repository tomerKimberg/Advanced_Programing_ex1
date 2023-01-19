//
// Created by tomer on 19/01/2023.
//

#include <c++/4.8/iostream>
#include "StandartIO.h"

StandartIO::StandartIO() {}

std::string StandartIO::read() {
    std::string temp;
    std::cin >> temp;
    return temp;
}

void StandartIO::write(std::string string) {
    std::cout << string;

}
