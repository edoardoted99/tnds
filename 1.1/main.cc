#include <iostream>
#include <fstream>
#include <cstdlib>
#include "cmath"

/*Vogliamo ora riorganizzare il codice precedente 
per renderlo più modulare e facilmente riutilizzabile. 
Per capirci meglio: il calcolo della media e' una operazione generale 
che può essere immaginata come un blocco di codice che accetta in 
input un array di dati e una dimensione e restituisce un valore 
( la media appunto ).
Se in uno stesso codice principale dobbiamo calcolare più volte 
la media di array di dati diversi non vogliamo ripetere più volte 
il frammento di codice relativo. Lo stesso vale per la lettura di
un set di dati da un file o per il calcolo della mediana. 
Il codice dovrebbe avere quindi una struttura del tipo
*/

using namespace std;

double Mean(double*, int);
double Variance(double*, int);
double Mediane(double[], int);
double * ReadDataFromFile(const char*, int);
void PrintOnFile(const char *, double *, int);
void SwapByValue(double, double);
void SwapByRef(double &, double &);
void SwapByPointer(double *, double*);
void SelectionSort(double *, int);



/*argc = numero di elementi che passo da terminale
argv[0]=nome del filen
argv[1]=numero di elementi del file da leggere
argv[2]=file da legere
*/
int main (int argc, char** argv){
    if(argc < 3){
        cout<<"Uso del programma : "<< argv[0] << "<n_data><filename>" <<endl;
        return -1;
    };

    ifstream inputFile(argv[2]);
    //check opening file
    if(!inputFile){
    cout <<"Errore apertura" <<endl;
    return -1; 
    };

    char* filename =argv[2];
    int ndata = atoi(argv[1]);
    double* data = ReadDataFromFile(filename, ndata);

    //print data

    for (int i = 0; i < ndata; i++)
    {
        cout<<data[i]<<endl;
    }
    

    cout<<"mean = "<<Mean(data,ndata)<<endl;
    cout<<"median = "<<Mediane(data,ndata)<<endl;
    cout<<"variance = "<<Variance(data,ndata)<<endl;

    //char* outputFile = "result.dat";

    PrintOnFile("result.dat", data, ndata);
    delete[] data;
    return 0;
    
}


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



void PrintOnFile (const char * filename, double * array, int N){

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