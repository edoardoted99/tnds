main: main.o Position.o
	g++ main.o Position.o -o main
main.o: main.cc Position.h
	g++ -c main.cc -o main.o
Position.o: Position.cc
	g++ -c Position.cc -o Position.o
