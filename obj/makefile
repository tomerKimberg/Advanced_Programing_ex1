# *****************************************************
# Variables to control Makefile operation

CC = g++
CFLAGS = -std=c++11

# ****************************************************
# Targets needed to bring the executable up to date
all:
	$(CC) $(CFLAGS) *.o
	mv *.out ../

server:
	$(CC) $(CFLAGS) *.o -o server.out
	mv server.out ../

client:
	$(CC) $(CFLAGS) *.o -o client.out
	mv client.out ../
clean:
	rm *.o