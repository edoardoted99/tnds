main: main.o Position.o Particle.o VectorField.o MaterialPoint.o
	g++ main.o Position.o Particle.o MaterialPoint.o VectorField.o -o main

Position.o: Position.cc Position.h
	g++ -c Position.cc -o Position.o

Particle.o: Particle.cc Particle.h
	g++ -c Particle.cc -o Particle.o

VectorField.o: VectorField.cc VectorField.h 
	g++ -c VectorField.cc -o VectorField.o

MaterialPoint.o: MaterialPoint.cc MaterialPoint.h 
	g++ -c MaterialPoint.cc -o MaterialPoint.o

main.o: main.cc Position.h Particle.h VectorField.h MaterialPoint.h
	g++ -c main.cc -o main.o


