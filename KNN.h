//
// Created by tomer on 07/12/2022.
//

#ifndef TARGIL1_KNN_H
#define TARGIL1_KNN_H
#include "headerDistanceCalculators.h"
#include <map>
#include <set>
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
            std::vector<double> vectorDouble;
            std::vector<std::string> classification;
        public:
            neighbor(std::vector<double> vectorDouble, std::vector<std::string> classification){
                this->vectorDouble = vectorDouble;
                this->classification = classification;
            }
            std::vector<double> getVectorDouble(){
                return this->vectorDouble;
            }
            std::vector<std::string> getVectorClassification(){
                return this->classification;
            }
            bool operator== (neighbor n2)
            {
                return (this->getVectorDouble() == n2.getVectorDouble()
                && this->getVectorClassification() == n2.getVectorClassification());
            }

        };
        std::vector<neighbor> data;
    public:
        distanceAndData(double d, const std::vector<double>& vectorDouble,
                        const std::vector<std::string>& classification){
            this->distance = d;
            this->data.emplace_back(vectorDouble,classification);
        }
        double getDistance() const {
            return this->distance;
        }
        std::vector<neighbor> getData(){
            return this->data;
        }
        void addData(const std::vector<double>& vectorDouble,
                     const std::vector<std::string>& classification) {
            bool newData = true;
            neighbor temp(vectorDouble, classification);
            for(neighbor n: this->data){
                if(n == temp){
                    newData = false;
                    break;
                };
            }
            if(newData) {
                this->data.emplace_back(vectorDouble, classification);
            }
        }

        void append(std::vector<neighbor> vectorData)  {
            for(neighbor n:vectorData){
                this->addData(n.getVectorDouble(), n.getVectorClassification());
            }
        }
        bool operator< (const distanceAndData& data1) const {
            return this->getDistance() < data1.getDistance();
        }




    };
    //set of distance and data object the stores a computed distance and all dataVector associated with it
    std::set<distanceAndData> processedData;


public:
    KNN(std::map<std::vector<double>, std::vector<std::string>> neighbors,
        std::string metric, int k);
    ~KNN();

    void setNeighbors( std::map<std::vector<double>, std::vector<std::string>> neighbors);
    void setK(int k);
    //make sure to delete former distance calculator
    void setMetric(std::string metric);
    void updateProcessedData(double distance, std::vector<double> vectorDouble,
                             std::vector<std::string> classification);
    int getK();
    std::map<std::vector<double>, std::vector<std::string>> getNeighbors();

    std::string getClassification(std::vector<double>);
    //might change based on design
    std::vector<std::vector<double>> getKNearestNeighbors(std::vector<double>);

};


#endif //TARGIL1_KNN_H
