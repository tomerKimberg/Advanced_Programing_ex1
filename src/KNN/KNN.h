//
// Created by tomer on 07/12/2022.
//

#ifndef TARGIL1_KNN_H
#define TARGIL1_KNN_H
#include "../DistanceCalculator/headerDistanceCalculators.h"
#include <map>
#include <set>
#include <algorithm>
#include "../DistanceCalculator/FactoryDistanceCalculator.h"
class KNN {
private:
    int k;
    std::string metric;
    DistanceCalculator* distanceCalculatorMetric;
    std::map<std::vector<double>, std::vector<std::string>> neighbors;
    FactoryDistanceCalculator FDC;
    /**
     * inner class used to store a distance and the associated data with it
     */
    class DistanceAndData{
    private:
        double distance;
        /**
         * inner class to store the vector<double> and vector<string> together
         */
        class neighbor{
        private:
            std::vector<double>* vectorDouble;
            std::vector<std::string>* classification;
        public:
            /**
             * constructor
             */
            neighbor(){
                this->vectorDouble = nullptr;
                this->classification = nullptr;
            }
            /**
             * constructor
             * @param vectorDouble pointer to vector<double>
             * @param classification pointer to vector<vector<string>>
             */
            neighbor(std::vector<double>* vectorDouble, std::vector<std::string>* classification){
                this->vectorDouble = vectorDouble;
                this->classification = classification;
            }
            //implement copy constructor
            /**
             * getter
             * @return pointer to vector<double>
             */
            std::vector<double>* getVectorDouble(){
                return this->vectorDouble;
            }
            /**
             * getter
             * @return pointer to vector<vector<string>>
             */
            std::vector<std::string>* getVectorClassification(){
                return this->classification;
            }
            /**
             * prameter overloading for comparison of neighbor class
             * @param n2 anoth neighbor object
             * @return true if objects are equal, else false.
             */
            bool operator== (neighbor n2)
            {
                return (*this->getVectorDouble() == *n2.getVectorDouble()
                && *this->getVectorClassification() == *n2.getVectorClassification());
            }

        };
        neighbor data;

    public:
        /**
         * constructor
         * @param d  calculated distance value
         * @param vectorDouble the vector<double> that the distance was calculated to
         * @param classification it's classification
         */
        DistanceAndData(double d,  std::vector<double>* vectorDouble,
                        std::vector<std::string>* classification){
            this->distance = d;
            this->data = neighbor(vectorDouble,classification);
        }
        /**
         * getter, a const function, doesn't change objects values
         * @return  double, the distance
         */
        double getDistance() const {
            return this->distance;
        }
        /**
         * return the neighbor object that stores pointers to both vector<double> and vector<vector<string>>
         * @return
         */
        neighbor getData(){
            return this->data;
        }
        bool operator< (const DistanceAndData& data1) const {
            return this->getDistance() < data1.getDistance();
        }




    };

    //vector of distance and data object that stores a computed distance and a dataVector associated with it
    std::vector<DistanceAndData> processedData;
    //store all vectors and classifications for vectors that don't match the given vectors dimension
    std::vector<std::pair<std::vector<double>, std::vector<std::string>>> mismatches;

    //private functions-
    /**
     * update the processedData with new information
     * @param distance double
     * @param vectorDouble
     * @param classification
     */
    void updateProcessedData(double distance, std::vector<double>* vectorDouble,
                             std::vector<std::string>* classification);
    /**
     * for all the data inside the neighbors map, calculate distance and update the processedData accordingly
     * @param v1 the vector to get its k-nearest neighbors
     * @return wether run was succesful or not
     */
    bool run(std::vector<double> v1);
    /**
     * get k nearest vectors<double>
     * @return vector of vector<double -> vector<vector<double>>
     */
    std::vector<std::vector<double>> getProcessedVectorData();
    /**
     * get k nearest Classifications
     * @return vector<string>
     */
    std::vector<std::string> getProcessedClassification();

public:
    /**
     * constructor KNN
     * @param neighbors map<key=vector<double>, value=vector<string>>
     * @param metric string that represents a metric method for the algorithm to use
     * @param k int, number of closest neighbors to look for
     */
    KNN(std::map<std::vector<double>, std::vector<std::string>> neighbors,
        std::string metric, int k);
    //implement, first decide on factory implementation
    ~KNN();
    /**
     * set new neighbor map
     * @param neighbors map<key=vector<double>, value=vector<string>>
     */
    void setNeighbors( std::map<std::vector<double>, std::vector<std::string>> neighbors);
    /**
     * set new k nearest neighbors
     * @param k
     */
    void setK(int k);
    //make sure to delete former distance calculator if needed (depends on factory implementation)
    /**
     * set a new metric function
     * @param metric  string name of metric method
     */
    void setMetric(std::string metric);
    /**
     * getter
     * @return int k
     */
    int getK();
    std::map<std::vector<double>, std::vector<std::string>> getNeighbors();
    /**
     * get the vectors that there dimension doesn't match input vector dimension
     * @return vector of a pair, that stores the vector<double> and its classifications
     */
    std::vector<std::pair<std::vector<double>, std::vector<std::string>>> getMismaches();
    /**
     * get the classification cording to the k nearest neighbors
     * @param v1 vector to get classification for
     * @return string name of classification, "" if an error occurred
     */
    std::string getClassification(std::vector<double> v1);
    /**
     * get the k nearest neighbors
     * @param v1 vector to get its k nearest neighbors
     * @return vector<vector<double>>, empty if an error occurred
     */
    std::vector<std::vector<double>> getKNearestNeighbors(std::vector<double> v1);

};


#endif //TARGIL1_KNN_H