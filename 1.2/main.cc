#include <iostream>
#include <fstream>
#include <cstdlib>

#include "cmath"
#include "functions.h"

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


