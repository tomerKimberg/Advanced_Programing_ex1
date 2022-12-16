
# **Program description**

This program classifies a given vector using the KNN algorithm, a databe from a CSV file and a distance metric.

### What is KNN?
KNN is an artificail intelligence algorithm used to classify a given vector.
KNN recieves a dataset of vectors and classfications, and an unclassified vector.
KNN finds the closes K vectors to the given vector, and returns the most common classification among those closest "neighbors".

### How is the distance measured?

Our program offers 5 different distance algorithms for the user to choose from:
1. Manhattan distance
2. Euclidean distance
3. Minkowski distance (we used 2 as the P constant)
4. Chebyshev distance
5. Canberra distance

like in the first exercise, most of those algorithms share some operations, so we calculate them using multiple vector operation functions, vectorSum, vectorMax, vectorPow, vectorSubtraction, vectorAbs, vectorAddition and vectorDivision

In order for these opertions to be well defined the following conditions must be met:
1. Operations on two vectors, compel that the vectors are the same size.
2. Vectors musn't be empty.
3. The input must be consisted of real numbers only.

Our program will try to match the input vector with as much vector from our data that match the above conditions. If not all the conditions are met, including bad program arguments (more on that later), the program will exit gracefully.

### Some technical details

Our project uses an object oriented approch, all the distance functions are inheriting from the abstract class, `Distance function`. to create the database for the KNN, we used a class called `GetNeighbors`, that returns a map of vectors, for the KNN to use. we iterate on the file using a `FileExtractor` class that inherits from the `DataExtractor` class and in the future we will add a `SocketExtractor` class that will also be a `DataExtractor`, so the `GetNeighbors` object won't care about the source of our data.
Finally, the `KNN` object will apply the KNN algorithm on our vector, and return it's classification.

# **Compilation and running instructions**

This project includes a makefile, to compile the project, run it with the make command.
```
make
```
After compilation, a new file called knn will apear, this is the execution file for our program.
To run the program, we need 3 program arguments:
1. k - a positive integer to indicate how many neighbors will we consider when determining the classification
2. path - a full or relative path to a csv source file, for the knn model to have data
3. metric - one of the following five distance metrics
	- AUC - for Auclidean distance
	- MAN - for Manhattan distance
	- CHB - for Chebyshev distance
	- CAN - for Canberra distance
	- MIN - for Monkowski distance (with a constant of 2)

execution example:
```
./knn 6 datasets/iris/iris_classified.csv AUC
```