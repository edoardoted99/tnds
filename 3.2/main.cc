#include <iostream>
#include <fstream>
#include <cstdlib>

#include "TH1F.h"
#include "TApplication.h"
#include "TCanvas.h"


#include "functions.h"

using namespace std;


/*argc = numero di elementi che passo da terminale
argv[0]=nome del filen
argv[1]=int - numero di elementi del file da leggere
argv[2]=char - file da legere
*/
int main (int argc, char** argv){

     if(argc<3){
          cout<<"Uso del programm : "<<argv[0]<<"<n_data><filename> "<<endl;
          return -1;
     }
     


     TApplication app("app",0,0);

     vector<double> v= Read<double>(atoi(argv[1]),argv[2]);
    

     
     TH1F histo ("histo", "histo", 100, -10, 100);
     histo.StatOverflows(kTRUE);

     //fill histogram

     for(int k=0; k<v.size(); k++) histo.Fill(v[k]);
     
     //log in stat info

     cout<<"Mean of uploaded values = "<<histo.GetMean()<<endl;

     //

     TCanvas mycanvas ("Histo", "Histo");
     histo.Draw();
     histo.GetXaxis()->SetTitle("measurement");

     app.Run();

     

    return 0;

    
    
}


