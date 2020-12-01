#include <iostream>
#include <fstream>
#include <cstdlib>
#include "cmath"


using namespace std;

double Mean(double* array, int N){
    
    double temp=0;
    //mean calculating
    for (int i = 0; i < N; i++)
    {
        temp=temp+array[i];
    }
    double mean=temp/N;
    return mean;
};

double Variance(double* array, int N){
    //variance calculating

    double temp=0;
    for (int i = 0; i < N; i++)
    {
        temp=temp+pow((array[i]-Mean(array,N)),2);
    };

    double variance = temp/(N-1);
    return variance;
};

double Mediane(double* array, int N){
    //median calculating

    double median=0;

    if (N%2==0)
    {
        median=(array[N/2-1]+array[N/2])/2;
    } else
    {
        median=array[(N)/2];
    }

    return median;
};
double * ReadDataFromFile(const char* filename, int N){
    
    ifstream inputFile(filename);

    double * array = new double[N];

    //dinamical allocation in arrau
    for(int i=0; i<N; i++){
        inputFile>>array[i];
    };

    inputFile.close();
    
    return array;
    
};

void Print(double * array, int N){
    cout<<"mean = "<<Mean(array,N)<<endl;
    cout<<"median = "<<Mediane(array,N)<<endl;
    cout<<"variance = "<<Variance(array,N)<<endl;
};


void Print(const char * filename, double * array, int N){

    ofstream outputFile(filename);

    for (int i=0; i<N; i++){
        outputFile<<array[i]<<endl;
    }

    outputFile.close();
};



void SwapByValue(double a, double b){
    double temp=a;
    a=b;
    b=temp;
};

void SwapByRef(double &a, double &b){
    double temp=a;
	a=b;
	b=temp;
};

void SwapByPointer(double *a, double *b){
    double temp=*a;
    *a=*b;
    *b=temp;
};
void SelectionSort(double * array, int N){
    //file sorting (selection sort)

    for (int i = 0; i < N-1; i++)
    {
        for (int k = i+1; k < N; k++)
        {
            if(array[k]<array[i]){
                SwapByRef(array[k], array[i]);
            }
        }
        
    }
};