

#include "KNN.h"

KNN::KNN(std::map<std::vector<double>, std::vector<std::string>> neighbors,
         std::string metric, int k) {
    this->neighbors = neighbors;
    this->distanceCalculatorMetric = this->FDC.createDistanceCalculator(metric);
    if(k >= 0) {
        this->k = k;
    }
    else{
        this->k = 0;
    }
    this->metric = metric;
}

KNN::~KNN() {
    if (this->distanceCalculatorMetric != nullptr) {
        delete this->distanceCalculatorMetric;
    }

}

void KNN::setK(int k) {
    this->k = k;
}

void KNN::setMetric(std::string metric) {

    //delete this->distanceCalculatorMetric;
    this->distanceCalculatorMetric = this->FDC.createDistanceCalculator(metric);
}

void KNN::setNeighbors(std::map<std::vector<double>, std::vector<std::string>> neighbors) {
    this->neighbors = neighbors;
}

void KNN::updateProcessedData(double distance, std::vector<double> *vectorDouble,
                              std::vector<std::string> *classification) {
    this->processedData.emplace_back(distanceAndData(distance, vectorDouble, classification));

}


int KNN::getK() {
    return this->k;
}

std::map<std::vector<double>, std::vector<std::string>> KNN::getNeighbors() {
    return this->neighbors;
}

std::vector<std::pair<std::vector<double>, std::vector<std::string>>> KNN::getMismaches() {
    return std::vector<std::pair<std::vector<double>, std::vector<std::string>>>();
}


std::vector<std::vector<double>> KNN::getKNearestNeighbors(std::vector<double> v1) {
    this->run(v1);
    return this->getProcessedVectorData();
}

std::string KNN::getClassification(std::vector<double> v1) {
    this->run(v1);
    std::vector<std::string> KNearestClassifications = this->getProcessedClassification();
    if(KNearestClassifications.empty()){
        return "no classification found,\nnon of the neighbors vectors dimensions match given input vector";
    };
    std::map<std::string, int> classifications;
        for (std::string classification: KNearestClassifications) {
            std::map<std::string, int>::iterator it = classifications.find(classification);
            if (it != classifications.end()) {
                it->second += 1;
            } else {
                classifications.insert({classification, 1});
            }
        }

    int max = 0;
    std::string classification;
    for (std::map<std::string, int>::iterator iter = classifications.begin(); iter != classifications.end(); ++iter) {
        if(max < iter->second){
            max = iter->second;
            classification = iter->first;
        }
    }
    return classification;
}


