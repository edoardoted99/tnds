main: main.o Particle.o
	g++ main.o Particle.o -o main


Particle.o: Particle.cc Particle.h
	g++ -c Particle.cc -o Particle.o

main.o: main.cc Particle.h
	g++ -c main.cc -o main.o

