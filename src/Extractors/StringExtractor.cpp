//
// Created by tomer on 19/01/2023.
//

#include "StringExtractor.h"

StringExtractor::StringExtractor(std::string data, char delim) {
    this->backup = data;
    this->size = data.size();
    this->data.str(data);
    this->delim = delim;
    this->index0 = 0;
    if(!this->data.eof()){
        this->next = true;
    }
    else{
        this->next = false;
    }
}

StringExtractor::~StringExtractor() {

}

DataExtractor *StringExtractor::copy() {
    return new StringExtractor(this->backup, this->delim);
}

std::string StringExtractor::getData() {

    std::string temp;
    std::getline(this->data,temp, this->delim);
    return temp;

}



bool StringExtractor::fail() {
    return this->next;
}

bool StringExtractor::hasNext(){
    if(!this->data.eof()){
        this->next = true;
    }
    else{
        this->next = false;
        //restore stream using backup;
        this->data.str(this->backup);
    }
    return this->fail();


}
