
main: main.o Solutore.o AlgoZeri.o
	g++ main.o Solutore.o AlgoZeri.o -o main 

Solutore.o: Solutore.h Solutore.h
	g++ -c Solutore.h -o Solutore.o 

AlgoZeri.o: AlgoZeri.cc AlgoZeri.h
	g++ -c AlgoZeri.cc -o AlgoZeri.o 

main.o: main.cc FunzioneBase.h Solutore.h AlgoZeri.h
	g++ -c main.cc -o main.o  

clean:
	rm *.o
cleanall: clean
	rm main
