#include "Vector.h"

double Mean(Vector);
double Variance(Vector);
double Mediane(Vector);
Vector Read(int, const char*);
Vector Random(int , int , int );
void Print(Vector);
void Print(Vector, const char *);
void SwapByValue(double, double);
void SwapByRef(double &, double &);
void SwapByPointer(double *, double*);
void SelectionSort(double *, int);