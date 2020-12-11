LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

main: main.o 
	g++ main.o -o main ${INCS} ${LIBS}

main.o: main.cc EquazioniDifferenziali.h  Algebra.h
	g++ -c main.cc -o main.o  ${INCS} ${LIBS}

clean:
	rm *.o
cleanall: clean
	rm main
