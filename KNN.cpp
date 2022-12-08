

#include "KNN.h"
KNN::KNN(std::map<std::vector<double>, std::vector<std::string>> neighbors,
         std::string metric, int k){
    this->neighbors = neighbors;
    this->distanceCalculatorMetric = this->FDC.createDistanceCalculator(metric);
    this->k = k;
    this->metric = metric;
}
KNN::~KNN() {
    if(this->distanceCalculatorMetric != nullptr){
        delete this->distanceCalculatorMetric;
    }

}

void KNN::setK(int k) {
    this->k = k;
}

void KNN::setMetric(std::string metric) {
    //delete old distance calculator
    delete this->distanceCalculatorMetric;
    this->distanceCalculatorMetric = this->FDC.createDistanceCalculator(metric);
}

void KNN::setNeighbors(std::map<std::vector<double>, std::vector<std::string>> neighbors) {
    this->neighbors = neighbors;
}

void KNN::updateProcessedData(double distance, std::vector<double>* vectorDouble,
                         std::vector<std::string>* classification){
    this->processedData2.emplace_back(distanceAndData(distance,vectorDouble,classification));

}
int KNN::getK() {
    return this->k;
}

std::map<std::vector<double>, std::vector<std::string>> KNN::getNeighbors() {
    return this->neighbors;
}

std::vector<std::vector<double>> KNN::getKNearestNeighbors(std::vector<double>) {}

std::string KNN::getClassification(std::vector<double>) {}