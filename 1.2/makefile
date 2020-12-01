main: main.o functions.o
	g++ main.o functions.o -o main
main.o: main.cc functions.h
	g++ -c main.cc -o main.o
functions.o: functions.cc functions.h
	g++ -c functions.cc -o functions.o
