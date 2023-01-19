//
// Created by tomer on 17/01/2023.
//

#include "Context.h"

Context::Context(){
    this->k = new int;
    *(this->k) = 5;
    //this->metric = "AUC";
    this->metric = "AUC";
    this->gn = nullptr;
    this->knn = nullptr;
    this->result = nullptr;
}
Context::~Context() {
    delete this->k;
    delete this->gn;
    delete this->knn;


}

int *Context::getK() const {
    return k;
}

KNN *Context::getKnn() const {
    return knn;
}

GetNeighbors *Context::getGn() const {
    return gn;
}

const std::string &Context::getMetric() const {
    return metric;
}

std::vector<int, std::string> *Context::getResult() const {
    return result;
}

void Context::setK(int k) {
    *(Context::k) = k;
}

void Context::setKnn() {
    if(this->knn){
        delete this->knn;
        this->knn = new KNN(this->gn->getNeighborsInMap(), this->metric, *this->k);
    }
    else{
        this->knn = new KNN(this->gn->getNeighborsInMap(), this->metric, *this->k);
    }
}

void Context::setGn(DataExtractor& extractor) {
    if(this->gn){
        delete this->gn;
        this->gn = new GetNeighbors(&extractor);
    }
    else{
        this->gn = new GetNeighbors(&extractor);
    }
}

void Context::setMetric(const std::string &metric) {
    Context::metric = metric;
}

void Context::setResult(std::vector<int, std::string> *result) {
    Context::result = result;
}
