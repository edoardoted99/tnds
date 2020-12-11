// Complete the code. Use as reference
// http://labmaster.mi.infn.it/Laboratorio2/labTNDS/lectures_1819/lezione9_1819_vector.html

#include <iostream>
#include <string>

#include "TApplication.h"
#include "TCanvas.h" 
#include "TGraph.h"
#include "TAxis.h"

#include "EquazioniDifferenziali.h"



int main(int argc, char** argv){
  
  if(argc != 2)
  {
    cerr << "Uso: " << argv[0]  << " <passo_di_integrazione (SEC)> " << endl;
    return -1;
  }

  TApplication myApp("myApp",0,0);

  Eulero myEuler;

  OscillatoreArmonico * osc = new OscillatoreArmonico (1.0);

  double tmax = 70.0;
  double h    = atof(argv[1]);
  vector<double> x {0.0, 1.0};
  double t = 0.0;
    
    TGraph *myGraph=new TGraph();
    int nstep=int(tmax/h+0.5);
    for(int step=0; step<nstep; step++){
        myGraph->SetPoint(step,t,x[0]);
        x=myEuler.Passo(t,x,h,osc);
        t=t+h;
    }
    TCanvas *c=new TCanvas();
    c->cd();
    string title ="Oscillatore armonico (Eulero h= " +std::to_string(h) +")";
    myGraph->SetTitle(title.c_str());
    myGraph->GetXaxis()->SetTitle("Tempo [s]");
    myGraph->GetYaxis()->SetTitle("Posizione x [m]");
    myGraph->Draw("AL");


   //CALCOLO ERRORE

    TGraph *myGraph2=new TGraph();

    for(int i=1; i<100; i=i+10){
    h=0.1/double(i);
    t=0.;
    x[0]=0.;
    x[1]=1.;
    nstep=int(tmax/h+0.5);
    for(int step=0; step<nstep; step++){
        
        x=myEuler.Passo(t,x,h,osc);
        t=t+h;
        
        //cout<<"x(t) = "<<x[0]-sin(osc->GetOmega0()*t)<< " t =" <<t<<endl;
        
      } myGraph2->SetPoint(i,h,fabs(x[0]-sin(osc->GetOmega0()*t)));
      
    }

    TCanvas *c2=new TCanvas();
    c2->cd();
    string title2 ="Andamento dell'errore in funzione del passo h";
    myGraph2->SetTitle(title2.c_str());
    myGraph2->GetXaxis()->SetTitle("Tempo [s]");
    myGraph2->GetYaxis()->SetTitle("Errore x a t = 70sec [m]");
    c2->SetLogy();
    c2->SetLogx();
    myGraph2->Draw("A.");
    
    
    myApp.Run();


    delete [] c2;
    delete [] c;

    delete [] myGraph2;
    delete [] myGraph;
  
  return 0;
}