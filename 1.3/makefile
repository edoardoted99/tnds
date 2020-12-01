main: main.o functions.o
	g++ main.o functions.o -o main -std=c++11
main.o: main.cc functions.h
	g++ -c main.cc -o main.o -std=c++11
functions.o: functions.cc functions.h
	g++ -c functions.cc -o functions.o -std=c++11
