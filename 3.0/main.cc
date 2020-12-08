#include <iostream>
#include <fstream>
#include <cstdlib>

#include "cmath"
#include "functions.h"
#include "Vector.h"
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

     Vector v =Read(ndata, filename);
     //Vector v=Random(100,0,10);
     cout<<v[3]<<endl;

     Vector <double> v =Read<double>(ndata, filename);
     Print (v);

     
     
     cout<<endl;
     
     Print(v);

     cout<<"Mean     = "<<Mean(v)<<endl;
     cout<<"Mediane  = "<<Mediane(v)<<endl;
     cout<<"Variance = "<<Variance(v)<<endl;

     Print(v, "data_out.txt");



     

    return 0;

    
    
}


