
LIBS := `root-config --libs`
INCS := `root-config --cflags`

es8.1: es8.1.o Integrale.o
	g++ es8.1.o Integrale.o -o es8.1 ${LIBS}

Integrale.o: Integrale.cxx Integrale.h
	g++ -c Integrale.cxx -o Integrale.o ${INCS}

es8.1.o: es8.1.cxx Funzioni.h Integrale.h
	g++ -c es8.1.cxx -o es8.1.o ${INCS}

esegui:
	./es8.1 20

clean:
	rm *.o
cleanall: clean
	rm es8.1
