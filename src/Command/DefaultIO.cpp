//
// Created by tomer on 17/01/2023.
//

#include "DefaultIO.h"
DefaultIO::DefaultIO() {
    this->extractor = nullptr;
}

DataExtractor* DefaultIO::getDataExtractor() {
    return this->extractor;
}

