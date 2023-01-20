
# **Program description**

In this repository we create a client and a server which communicate between them to get classifications of vectors. We start a server with a path to source file, that will use the server in the KNN process. we start a client, and the client sends to the server a vector to classify, distance calculation metric and the number of neighbors to use in the knn. The server responds to the client with the right classification or an invalid input message, if the vector doesn't fit the server's vecotrs from the source file, or the K is bigger than the amount of records in the source file.

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

Our program will try to match the input vector with as much vectors from our backup that match the above conditions. If not all the conditions are met, including bad program arguments (more on that later), the program will exit gracefully.

### Some technical details

Our project uses an object oriented approch, all the distance functions are inheriting from the abstract class, `Distance function`. to create the database for the KNN, we used a class called `GetNeighbors`, that returns a map of vectors, for the KNN to use. we iterate on the file using a `FileExtractor` class that inherits from the `DataExtractor` class and in the future we will add a `SocketExtractor` class that will also be a `DataExtractor`, so the `GetNeighbors` object won't care about the source of our backup.
Finally, the `KNN` object will apply the KNN algorithm on our vector, and return it's classification.

# **Compilation and running instructions**

This project includes a makefile, to compile the project, run it with the make command.
```
make
```
After compilation, two new files will be created, server.out and client.out.
To run the server, we need 2 program argument:
1. path - a full or relative path to a csv source file, for the knn model to have backup
2. port - the port that the server will bind to
execution example:
```
./server.out datasets/iris/iris_classified.csv 12345
```
To run the client, we need 2 program argument:
1. ip - the ip of the computer that the server uses
2. port - the port of our server
execution example:
```
./client.out 127.0.0.1 12345
```
when the client is active, to send a request to the server, use the following fomat: VECTOR METRIC K, when:
1. VECTOR - is the vector we want to classify
2. METRIC - is one of the following five distance metrics
	- AUC - for Auclidean distance
	- MAN - for Manhattan distance
	- CHB - for Chebyshev distance
	- CAN - for Canberra distance
	- MIN - for Monkowski distance (with a constant of 2)
3. K - a positive integer to indicate how many neighbors will we consider when determining the classification
for example:
```
1.1 2.2 3.3 4.4 AUC 5
```
to close the connection from the client, type "-1", and the client will close.
