# simple makefile for banshee

CC = g++

all : main.o traffic.o activity.o analysis.o alert.o
	$(CC) -o Traffic main.o traffic.o activity.o analysis.o alert.o

main.o : traffic.h main.cpp
	$(CC) -c main.cpp

traffic.o : traffic.h traffic.cpp
	$(CC) -c traffic.cpp

activity.o : activity.cpp
	$(CC) -c activity.cpp

analysis.o : analysis.cpp
	$(CC) -c analysis.cpp

alert.o : alert.cpp
	$(CC) -c alert.cpp

clean:
	rm Traffic *.o
