#include <iostream>
#include <fstream>
#include <cstdlib>

#include "cmath"
#include "functions.h"
#include "Vector.h"

/*Implementare una classe che abbia come data membri (privati) 
un intero (dimensione del vettore) ed un puntatore a double 
(puntatore alla zona di memoria dove sono immagazzinati i dati).
Implementare:
Un costruttore di default, che assegni valori nulli alla 
lunghezza del vettore ed al puntatore.
Un costruttore che abbia come argomento un intero: 
questo deve creare un vettore di lunghezza uguale 
all'intero e tutte le componenti nulle 
(usando un new per allocare la memoria necessaria).
Un distruttore: deve chiaramente deallocare 
con delete[] la zona di memoria allocata con new.
Dei metodi per inserire e leggere i valori 
della componenti: questi metodi devono controllare 
che l'indice delle componenti richieste 
sia compatibile con la lunghezza del vettore.
*/

using namespace std;


/*argc = numero di elementi che passo da terminale
argv[0]=nome del filen
argv[1]=numero di elementi del file da leggere
argv[2]=file da legere
*/
int main (){

    //costructing vector without arguments

    Vector vnull;
    cout<<"Vector vnull : dimension = "<<vnull.GetN()<<endl;
    
   //constructor with integer : dim=10;
   Vector v(10);
   cout<< "Vector v : = dimension = "<<v.GetN() <<endl;
   for (int k =0; k<v.GetN(); k++){
        cout<<v.GetComponent(k)<<" ";
   }

    //changing contents of vector

    cout<<endl<<"editing v"<<endl;

    for(int k=0; k<v.GetN(); k++){
        v.SetComponent(k,k+2);
    }

    cout<< "Vector v : dimension = "<<v.GetN() <<endl;
   for (int k =0; k<v.GetN(); k++){
        cout<<v.GetComponent(k)<<" ";
   }

   cout<<"using copy constructor to build w (Vector w(v);"<<endl;

   Vector w=v;

   cout<<"Vector w : dimension = "<<w.GetN()<<endl;
   for(int k=0; k<w.GetN(); k++){
      cout<<w.GetComponent(k)<<" ";
   }
    cout<<endl;

   v.SetComponent(4,99);


    cout<< "Vector v : dimension = "<<v.GetN() <<endl;
   for (int k =0; k<v.GetN(); k++){
        cout<<v.GetComponent(k)<<" ";
   }
    cout<<endl;
   cout<<"Vector w : dimension = "<<w.GetN()<<endl;
   for(int k=0; k<w.GetN(); k++){
      cout<<w.GetComponent(k)<<" ";
   }
    cout<<endl;
    //char* outputFile = "result.dat";


    return 0;

    
    
}


