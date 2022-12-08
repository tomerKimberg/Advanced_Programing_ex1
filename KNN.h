//
// Created by tomer on 07/12/2022.
//

#ifndef TARGIL1_KNN_H
#define TARGIL1_KNN_H
#include "headerDistanceCalculators.h"
#include <map>
#include <set>
#include <algorithm>
#include "factoryDistanceCalculator.h"
class KNN {
private:
    int k;
    std::string metric;
    distanceCalculator* distanceCalculatorMetric;
    std::map<std::vector<double>, std::vector<std::string>> neighbors;
    factoryDistanceCalculator FDC;
    // add container attribute to store distances
    class distanceAndData{
    private:
        double distance;
        class neighbor{
        private:
            std::vector<double>* vectorDouble;
            std::vector<std::string>* classification;
        public:
            neighbor(){
                this->vectorDouble = nullptr;
                this->classification = nullptr;
            }
            neighbor(std::vector<double>* vectorDouble, std::vector<std::string>* classification){
                this->vectorDouble = vectorDouble;
                this->classification = classification;
            }
            //implement copy constructor

            std::vector<double>* getVectorDouble(){
                return this->vectorDouble;
            }
            std::vector<std::string>* getVectorClassification(){
                return this->classification;
            }
            bool operator== (neighbor n2)
            {
                return (*this->getVectorDouble() == *n2.getVectorDouble()
                && *this->getVectorClassification() == *n2.getVectorClassification());
            }

        };
        neighbor data;
    public:
        distanceAndData(double d,  std::vector<double>* vectorDouble,
                        std::vector<std::string>* classification){
            this->distance = d;
            this->data = neighbor(vectorDouble,classification);
        }
        double getDistance() const {
            return this->distance;
        }
        neighbor getData(){
            return this->data;
        }
        bool operator< (const distanceAndData& data1) const {
            return this->getDistance() < data1.getDistance();
        }




    };
    //vector of distance and data object that stores a computed distance and a dataVector associated with it
    std::vector<distanceAndData> processedData;

    //private functions-
    void updateProcessedData(double distance, std::vector<double>* vectorDouble,
                             std::vector<std::string>* classification);

    void run(std::vector<double> v1){
        for(std::map<std::vector<double>, std::vector<std::string>>::iterator iter = this->neighbors.begin();
            iter != this->neighbors.end(); ++iter)
        {
            std::vector<double> v2 =  iter->first;
            double distance = this->distanceCalculatorMetric->calculateDistance(v1,v2);
            this->updateProcessedData(distance, const_cast<std::vector<double> *>(&(iter->first)), &iter->second);
        }

        //use select(K) algorithm to reorganize all element around the k'th smallest element in the vector
        std::nth_element(this->processedData.begin(), (this->processedData.begin() + (this->k-1)),
                this->processedData.end());
    }
    std::vector<std::vector<double>> getProcessedVectorData(){
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
    std::vector<std::vector<std::string>> getProcessedClassification(){
        std::vector<std::vector<std::string>> res;
        int k = 1;
        for(distanceAndData temp : this->processedData){
            if(k <= this->k) {
                k+=1;
                const std::vector<std::string>& temp1 = *temp.getData().getVectorClassification();
                res.push_back(temp1);
            }
            else{
                break;
            }
        }
        return res;
    }


public:
    KNN(std::map<std::vector<double>, std::vector<std::string>> neighbors,
        std::string metric, int k);
    ~KNN();

    void setNeighbors( std::map<std::vector<double>, std::vector<std::string>> neighbors);
    void setK(int k);
    //make sure to delete former distance calculator
    void setMetric(std::string metric);

    int getK();
    std::map<std::vector<double>, std::vector<std::string>> getNeighbors();

    std::string getClassification(std::vector<double> v1);
    //might change based on design
    std::vector<std::vector<double>> getKNearestNeighbors(std::vector<double> v1);

};


#endif //TARGIL1_KNN_H
