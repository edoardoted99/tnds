
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <cmath>

#include <iomanip>
#include "string.h"
#include <float.h>

#include "FunzioneBase.h"
#include "Solutore.h"
#include "AlgoZeri.h"


using namespace std;

int main (int argc, const char ** argv) {
	
	
	if (argc != 2) {
		cout << "Utilizzo del programma : ./main <prec>" << endl;
		return -1;
		}else{
		if(atof(argv[1])<10E-6){
		cout << "Precisione minima > 10E_-6" << endl;
		}
	}

	double prec = atof(argv[1]);
	double a = 0;
	double b = 0;
	double zero=0;
	
	int cifre_significative = 0;

	Funzione7_3 *f= new Funzione7_3(1,1);
	Bisezione bisettore(a, b, prec, f);


	//cout<<"x = " <<p<<endl;
	//cout<<"f(x) = "<<parabola->Eval(p)<<endl;
	

	for(int n=0; n<20; n++){
		double a=n*M_PI;
		double b=a+M_PI;
		
		bisettore.Set_a(a);
		bisettore.Set_b(b);
		zero=bisettore.CercaZeri(a, b, f);
		cifre_significative = -log10(prec);  //+ log10(zero);

		cout << fixed;
		cout << setprecision(cifre_significative) << zero << " +/- " << prec << endl;
	} 
	
	
	
	//cout<<bisettore.CercaZeri(a, b, parabola) << endl;


	//cout << fixed;
	//cout << setprecision(cifre_significative) << zero << " +/- " << prec << endl;
	
	return 0;
}


