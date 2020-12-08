
#include <iostream>
#include <cmath>
#include <iomanip>

#include "TApplication.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "TLegend.h"
#include "TGraph.h"

#include "Funzioni.h"
#include "Integral.h"

using namespace std;


int main(int argc, const char ** argv){

  
  if (argc != 2) {
    cout << "Usage: ./es8.0 nstep" << endl;
    return -1;
  }

TApplication app("app", 0, 0);

  double a = 0.;
  double b = M_PI;

  int nstep = atoi(argv[1]);

  Seno* mysin = new Seno();
  Integral* integrator = new Integral(a, b, mysin);

  cout << setprecision(12) << integrator -> MidPoint(nstep) << endl;

	//tabella
  	double diff1 = 0.;
	cout << endl << "n_step:    differenza: " << endl;

	for (int i=1; i<=nstep; i++) {
		diff1 = 2. - integrator->MidPoint(i);
		cout << i << "          " << diff1 << endl;
	}

  	//root

	//TGraph myGraph;
	TGraph * myGraph = new TGraph();
	double diff = 0.;

	TCanvas * myCanvas = new TCanvas();
	myCanvas->cd();

	for (int i=1; i<=nstep; i++) {
		cout << "1" << endl;
		diff = 2. - integrator -> MidPoint(i);
		myGraph->SetPoint(i+1, i, diff);
		cout << "2" << endl;
	}

	myGraph->Draw("ALP");
	myGraph->SaveAs("es8.0.png");
	app.Run();	
	
	//delete[] myCanvas

  //return 0;

	// Build a TApplication objetc : this is used at the end of the program
  // with the myApp.Run() to force the program waiting before the return
/*
  TApplication myApp("myApp",0,0);     
  
  TGraph myGraph1;

  // Fill the TGraph with some dummy points   

  for ( int k = 1 ; k <= nstep ; k++ ) {
	diff1 = 2. - integrator->MidPoint(k);
    myGraph1.SetPoint(k+1, k, diff1);
  }

  // build a TCanvas which will hold the graphs and enter into it 

  TCanvas * myCanvas = new TCanvas();
  myCanvas->cd();
  
  // some cosmetics to the TGraphs     

  myGraph1.SetTitle("Place here the title");
  myGraph1.GetXaxis()->SetTitle("x axis []");
  myGraph1.GetYaxis()->SetTitle("y axis []");
  
  myGraph1.SetLineColor(2);
  myGraph1.SetMarkerStyle(20);

  // Draw : here draw the first graph and draw the second on top of it 
  // Options :                
  //   A => draw axes                         
  //   L => connect the dots with a line 
  //   P => use the Polymarker for each point   
  //   same => Draw on the same pad        

  myGraph1.Draw("ALP");
  
  // Create and draw the legend    
  
  TLegend *mylegend = new TLegend(0.2,0.6,0.4,0.8);
  mylegend->AddEntry(&myGraph1,"This is graph1","LP");
  mylegend->Draw();

  myApp.Run();
*/
}


/*

*/
	