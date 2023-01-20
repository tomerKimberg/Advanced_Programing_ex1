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
    this->toClassify = nullptr;
    this->knn = nullptr;
    this->result = nullptr;
}
Context::~Context() {
    delete this->k;
    delete this->gn;
    delete this->knn;
    delete this->result;
    delete this->toClassify;



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

std::vector<std::vector<double>> *Context::getToClassify() const {
    return toClassify;
}

const std::string &Context::getMetric() const {
    return metric;
}

std::vector<std::pair<int, std::string>> *Context::getResult() const {
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

void Context::setToClassify(std::vector<std::vector<double>> *toClassify) {
    this->toClassify = toClassify;
}

void Context::setMetric(const std::string &metric) {
    Context::metric = metric;
}
void Context::initializeResult() {
    if(this->result){
        this->result->clear();
    }
    else{
        this->result = new std::vector<std::pair<int, std::string>>;
    }
}

void Context::updateResult(int k ,const std::string& classification) {
    this->result->push_back(std::make_pair(k,classification));
}

void Context::initializeToClassify(){
    if(this->toClassify){
        toClassify->clear();
    }
    else{

        this->toClassify = new std::vector<std::vector<double>>;
    }
}

void Context::updateToClassify(std::vector<double> v){
    this->toClassify->push_back(v);
}

