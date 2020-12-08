#include <iostream>
#include <fstream>
#include <cstdlib>
#include "cmath"
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;

template <typename T> double Mean(vector <T> v){
    
    double temp=0;
    //mean calculating
    for (int i = 0; i < v.size(); i++)
    {
        temp=temp+v[i];
    }
    double mean=double(temp)/v.size();
    return mean;
};

template <typename T> double Variance(vector<T> v){
    //variance calculating

    double temp=0;
    for (int i = 0; i < v.size(); i++)
    {
        temp=temp+pow((v[i]-Mean(v)),2);
    };

    double variance = temp/(v.size()-1);
    return variance;
};

template <typename T> double Mediane(vector<T> v){
    //median calculating

    double median=0;

    if (v.size()%2==0)
    {
        median = (v[v.size()/2-1]+v[v.size()/2])/2;

        
    } else
    {
        median=v[v.size()]/2;
    };

    return median;
};
template <typename T> vector<T> Read(int N, const char* filename){
    
    ifstream inputFile(filename);

    vector <T> v(N);

    //dinamical allocation in arrau
    T a=0;
    for(int i=0; i<N; i++){
        inputFile>>a;
        v[i]=a;
    };

    inputFile.close();
    
    return v;
    
};

template <typename T> vector<T> Random(int N, int min, int max){
    vector <T> v(N);
    for(int i=0; i<v.size(); i++){
        v[i]= (rand() % max + min);
    }return v;
}



template <typename T> void Print(vector<T> v){
    for(int i=0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }cout<<endl;
}


template <typename T> void Print(vector<T> v, const char * filename){

    ofstream outputFile(filename);

    for (int i=0; i<v.size(); i++){
        outputFile<<v[i]<<endl;
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