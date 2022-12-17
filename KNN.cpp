

#include "KNN.h"

//private functions
bool KNN::run(std::vector<double> v1){
	//check if metric is null
	if(nullptr == this->distanceCalculatorMetric){
		std::cout << "We tried to run the KNN but couldn't determine a distance function" << std::endl;
		return false;
	}
	this->processedData.clear();
	//iterate over all neighbors in the map
	for(std::map<std::vector<double>, std::vector<std::string>>::iterator iter = this->neighbors.begin();
		iter != this->neighbors.end(); ++iter)
	if(v1.size() == iter->first.size()) {
		//check distance if vectors have the same dimensions
		std::vector<double> v2 = iter->first;
		//compute distance from v1 for every v2
		double distance = this->distanceCalculatorMetric->calculateDistance(v1, v2);
		//update the processedData
		this->updateProcessedData(distance, const_cast<std::vector<double> *>(&(iter->first)), &iter->second);
	}

	else{
		//store all vectors with mismatch to v1 dimension
		this->mismatches.push_back(
				std::pair<std::vector<double>,std::vector<std::string>>(iter->first,iter->second));
		continue;
	}

	//use select(K) algorithm to reorganize all element around the k'th smallest element in the vector
	std::nth_element(this->processedData.begin(), (this->processedData.begin() + (this->k-1)),
			this->processedData.end());
	return true;
}
std::vector<std::vector<double>> KNN::getProcessedVectorData(){
	std::vector<std::vector<double>> res;
	int k = 1;
	for(distanceAndData temp : this->processedData){
		if(k <= this->k) {
			k += 1;
			res.push_back(*temp.getData().getVectorDouble());
		}
		else{
			break;
		}
	}
	return res;
}
std::vector<std::string> KNN::getProcessedClassification(){
	std::vector<std::string> res;
	int k = 1;
	for(distanceAndData temp : this->processedData){
		for(std::string classification : *temp.getData().getVectorClassification())
		if(k <= this->k) {
			k+=1;
			res.push_back(classification);
		}
		else{
			break;
		}
	}
	return res;
}

//constructor and destructor
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
//set functions
void KNN::setK(int k) {
    this->k = k;
}
void KNN::setMetric(std::string metric) {

    delete this->distanceCalculatorMetric;
    this->distanceCalculatorMetric = this->FDC.createDistanceCalculator(metric);
}

void KNN::setNeighbors(std::map<std::vector<double>, std::vector<std::string>> neighbors) {
    this->neighbors = neighbors;
}
void KNN::updateProcessedData(double distance, std::vector<double> *vectorDouble,
                              std::vector<std::string> *classification) {
    this->processedData.emplace_back(distanceAndData(distance, vectorDouble, classification));

}

//get functions
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
    if(!this->run(v1)){
        return std::vector<std::vector<double>>();
    }
    return this->getProcessedVectorData();
}

// get classification for vector
std::string KNN::getClassification(std::vector<double> v1) {
    if(!this->run(v1)){
        return "";
    }
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


