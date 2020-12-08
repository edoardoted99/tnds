#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

#include "cmath"
#include "functions.h"




using namespace std;


/*argc = numero di elementi che passo da terminale
argv[0]=nome del filen
argv[1]=numero di elementi del file da leggere
argv[2]=file da legere
*/
int main (int argc, char** argv){

     if(argc<3){
          cout<<"Uso del programm : "<<argv[0]<<"<n_data><filename> "<<endl;
          return -1;
     }
     
     int ndata = atoi(argv[1]);
     char * filename =argv[2];

     
    
     vector <double> w =ReadAll<double>(argv[2]);
     cout<<"dimensione = "<<w.size()<<endl;
;
     //vector <double> v =Read<double>(atoi(argv[1]), argv[2]);
     Print<double>(w);
     
     //cout<<v[3]<<endl;

     cout<<endl;
     

     //cout<<"Mean     = "<<Mean<double>(v)<<endl;
     //cout<<"Mediane  = "<<Mediane<double>(v)<<endl;
     //cout<<"Variance = "<<Variance<double>(v)<<endl;

     //Print<double>(w, "data_out.txt");



     

    return 0;

    
    
}


