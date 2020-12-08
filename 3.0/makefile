main: main.o functions.o Vector.o
	g++ main.o functions.o Vector.o -o main -std=c++11
main.o: main.cc functions.h
	g++ -c main.cc -o main.o -std=c++11
functions.o: functions.cc functions.h Vector.h 
	g++ -c functions.cc -o functions.o -std=c++11
Vector.o: Vector.cc Vector.h
	g++ -c Vector.cc -o Vector.o
