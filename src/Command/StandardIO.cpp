//
// Created by tomer on 19/01/2023.
//

#include <c++/4.8/iostream>
#include "standardIO.h"

StandardIO::StandardIO() {}

std::string StandardIO::read() {
    std::string temp;
    std::cin >> temp;

    return temp;
}

void StandardIO::write(std::string string) {
    std::cout << string;

}
