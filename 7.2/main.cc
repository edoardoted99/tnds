
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
	
	if (argc != 4) {
		cout << "Usare: ./72 x_min x_max prec" << endl;
		return -1;
	}

	
	double a = atof(argv[1]);
	double b = atof(argv[2]);


	double prec = atof (argv[3]);
	double p=-5./(2.*3.);
	int cifre_significative = -log10(prec);

	
	Parabola * parabola = new Parabola(3, 5, -2);
	//cout<<"x = " <<p<<endl;
	//cout<<"f(x) = "<<parabola->Eval(p)<<endl;
	Bisezione bisettore(a, b, prec, parabola);

	double zero=bisettore.CercaZeri(a, b, parabola);
	cout<<zero<<endl;
	
	
	//cout<<bisettore.CercaZeri(a, b, parabola) << endl;


	cout << fixed;
	cout << setprecision(cifre_significative) << zero << " +/- " << prec << endl;
	
	return 0;
}


