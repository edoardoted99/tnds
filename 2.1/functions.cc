#include <iostream>
#include <fstream>
#include <cstdlib>
#include "cmath"
#include "Vector.h"


using namespace std;

double Mean(Vector v){
    
    double temp=0;
    //mean calculating
    for (int i = 0; i < v.GetN(); i++)
    {
        temp=temp+v.GetComponent(i);
    }
    double mean=temp/v.GetN();
    return mean;
};

double Variance(Vector v){
    //variance calculating

    double temp=0;
    for (int i = 0; i < v.GetN(); i++)
    {
        temp=temp+pow((v.GetComponent(i)-Mean(v)),2);
    };

    double variance = temp/(v.GetN()-1);
    return variance;
};

double Mediane(Vector v){
    //median calculating

    double median=0;

    if (v.GetN()%2==0)
    {
        median=(v.GetComponent(v.GetN()/2-1)+v.GetComponent(v.GetN()/2))/2;
    } else
    {
        median=v.GetComponent((v.GetN())/2);
    };

    return median;
};
Vector Read(int N, const char* filename){
    
    ifstream inputFile(filename);

    Vector v(N);

    //dinamical allocation in arrau
    int a=0;
    for(int i=0; i<N; i++){
        inputFile>>a;
        v.SetComponent(i,a);
    };

    inputFile.close();
    
    return v;
    
};

Vector Random(int N, int min, int max){
    Vector v(N);
    for(int i=0; i<v.GetN(); i++){
        v.SetComponent(i, rand() % max + min);
    }return v;
}



void Print(Vector v){
    for(int i=0; i < v.GetN(); i++){
        cout<<v.GetComponent(i)<<" ";
    }cout<<endl;
}


void Print(Vector v, const char * filename){

    ofstream outputFile(filename);

    for (int i=0; i<v.GetN(); i++){
        outputFile<<v.GetComponent(i)<<endl;
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