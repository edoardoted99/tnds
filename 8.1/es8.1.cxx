
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <cmath>

#include "Funzioni.h"
#include "Integrale.h"

using namespace std;

int main (int argc, const char ** argv) {
	
	if (argc != 2) {
		cout << "USARE: ./es8.1 nstep" << endl;
		return -1;
	}
	
	double a = 0.;
	double b = M_PI;
	
	int nstep = atoi (argv[1]);
	
	Seno *sen = new Seno();
	Integrale *integratore = new Integrale (a, b, sen);
	
	cout << setprecision(12) << integratore -> Simpson(nstep) << endl;
	cout << "Errore: " << integratore -> GetError() << endl << endl;

	double diff = 0.;
	cout << "n_step:     differenza: " << endl;

	for (int i=0; i<nstep; i++) {
		diff = integratore->Simpson(nstep) - integratore->Simpson(i);
		cout << i << "           " << diff << endl;
	}

	return 0;
}

