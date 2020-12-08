
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <cmath>

#include "MaterialPoint.h"
#include "VectorField.h"
#include "Position.h"
#include "Particle.h"

using namespace std;

int main (int argc, char** argv) {
	
	//controlla argomenti
	if (argc != 4) {
		cerr << "usage: " << argv[0] << " <x> <y> <z> " << endl;
		exit(-1);
	}
	
	//numeri dati da terminale 
	double x = atof (argv[1]);
	double y = atof (argv[2]);
	double z = atof (argv[3]);
	Position r(x, y, z);
	
	const double e = 1.60217653E-19;
	const double me = 9.1093826E-31;
	const double mp = 1.67262171E-27;
	const double d = 1.E-10;
	
	MaterialPoint elettrone (me, -e, 0., 0., d/2.);
	MaterialPoint protone (mp, e, 0., 0., -d/2.);
	
	VectorField E = elettrone.CampoElettrico(r) + protone.CampoElettrico(r);
	
	cout << "E = (" << E.getFx() << "; " << E.getFy() << "; " << E.getFz() << ")" << endl;
	
	return 0;
}