LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

es8.0: main.o Integral.o
	g++ main.o Integral.o -o es8.0 ${LIBS} ${INCS}

Integral.o: Integral.cc Integral.h
	g++ -c Integral.cc -o Integral.o ${INCS} ${LIBS}

main.o: main.cc Funzioni.h Integral.h
	g++ -c main.cc -o main.o ${INCS} ${LIBS}

esegui:
	./es8.0 10

clean:
	rm *.o
cleanall: clean
	rm es8.0
	rm es8.0.png
