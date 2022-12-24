# *****************************************************
# Variables to control Makefile operation

CC = g++
CFLAGS = -std=c++11

# ****************************************************
# Targets needed to bring the executable up to date
all:
	$(MAKE) -C src/Extractors
	$(MAKE) -C src/DistanceCalculator
	$(MAKE) -C src/KNN
	$(MAKE) -C src/SocketConnection
	$(MAKE) -C src/ValidationFuncs

	$(CC) -c $(CFLAGS) main.cpp
	mv	main.o obj
	$(MAKE) -C obj

server:
	$(MAKE) -C src/Extractors
	$(MAKE) -C src/DistanceCalculator
	$(MAKE) -C src/KNN
	$(MAKE) -C src/SocketConnection
	$(MAKE) -C src/ValidationFuncs
	$(MAKE) -C src/Server
	$(MAKE) -C obj



clean:
	rm a.out
	cd obj
	rm *.o
	cd ../
