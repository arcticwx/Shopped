CC = g++
OBJ = main

all:  compile

compile:
	$(CC) -o $(OBJ) src/main.cpp