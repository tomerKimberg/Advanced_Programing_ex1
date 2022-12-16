# *****************************************************
# Variables to control Makefile operation

CC = g++
CFLAGS = -std=c++11
NAME = -o knn

# ****************************************************
# Targets needed to bring the executable up to date

all:
	$(CC) $(CFLAGS) $(NAME) *.cpp