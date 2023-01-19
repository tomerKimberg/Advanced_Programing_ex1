//
// Created by tomer on 19/01/2023.
//

#include "StringExtractor.h"

StringExtractor::StringExtractor(std::string data) {
    this->data = data;
    this->size = data.size();
    this->index0 = 0;
    if(this->data.find_first_of("/r") != std::string::npos){
        this->next = true;
    }
    else{
        this->next = false;
    }
}

StringExtractor::~StringExtractor() {

}

DataExtractor *StringExtractor::copy() {
    return new StringExtractor(this->data);
}

std::string StringExtractor::getData() {
    size_t indexTemp = this->data.find_first_of("/r");
    std::string temp = this->data.substr(0, indexTemp);
    this->data.erase(0,indexTemp+2);
    return temp;

}


bool StringExtractor::fail() {
    return this->next;
}

bool StringExtractor::hasNext(){
    if(this->data.find_first_of("/r") != std::string::npos){
        this->next = true;
    }
    else{
        this->next = false;
    }
    return this->fail();


}
