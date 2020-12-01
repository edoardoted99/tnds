#include <iostream>
#include <fstream>
#include <cstdlib>
#include "cmath"

/*Proviamo a scrivere un unico codice che legga dati da file,
li immagazzini in un array dinamico, 
calcoli la media, 
la varianza e la mediana dei dati raccolti. 
Scriviamo su un file di output i dati 
riordinati in ordine crescente. 
Il numero di elementi da caricare 
e il nome del file in cui trovare 
i dati sono passati da tastiera nel momento
in cui il programma viene eseguito. 
Cerchiamo di costruire il codice passo passo.*/

using namespace std;

/*void populateFile(BinarySearchTree b) {
    int random_integer;
    srand( time( NULL ) );
    std::ofstream myfile;
    string line;
    myfile.open ("output.txt");
    myfile << "Writing this to a file: ";
    for(int index=0; index<1000; index++)
    {
        random_integer = (rand()%1000)+1;
        cout << random_integer << endl;
        myfile << random_integer;
    }
    myfile.close();

    int value;
    ifstream file ("output.txt");
    if (file.is_open())
    {
        while ( getline (file,line) )
        {
            value = std::stoi(line);
            b.insert(value);
        }
        myfile.close();
    }

    else cout << "Unable to open file";

} */

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

    char* filename =argv[2];
    ifstream inputFile(filename);

    //controllo apertura file
    if(!inputFile){
    cout <<"Errore apertura" <<endl;
    return -1; 
    };

    int ndata = atoi(argv[1]);
    double* data = new double[ndata];

   
    //allocazione dati in array
    for(int i=0; i<ndata; i++){
        
        inputFile>>data[i];
        cout<<data[i]<<endl;
    };
    
    double temp=0;
    //calcolo media, var, med

    for (int i = 0; i < ndata; i++)
    {
        temp=temp+data[i];
    }
    double mean=temp/ndata;
    
    //variance calculating

    temp=0;
    for (int i = 0; i < ndata; i++)
    {
        temp=temp+pow((data[i]-mean),2);
    }

    double variance = temp/(ndata-1);

    double median;

    if (ndata%2==0)
    {
        median=(data[ndata/2-1]+data[ndata/2])/2;
    } else
    {
        median=data[(ndata)/2];
    }

    cout<<"mean = "<<mean<<endl;
    cout<<"median = "<<median<<endl;
    cout<<"variance = "<<variance<<endl;
    
    

    inputFile.close();
    return 0;
    
}