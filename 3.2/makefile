LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

main: functions.h main.cc 
	g++ -o main main.cc ${INCS} ${LIBS}
