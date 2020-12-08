
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <cmath>

#include "Position.h"
#include "Particle.h"
#include "MaterialPoint.h"
#include "VectorField.h"

using namespace std;

//costruttori
MaterialPoint::MaterialPoint(double massa, double carica, const Position& r) : Particle (massa, carica), Position (r) { }

MaterialPoint::MaterialPoint(double massa, double carica, double x, double y, double z) : Particle (massa, carica), Position (x, y, z) { }

//
VectorField MaterialPoint::CampoElettrico (const Position& b) const {
	const double eps = 8.8544E-12;
	double E = m_charge / ( 4*M_PI*eps* pow(Distance(b), 2));

	double dx = b.getX() - getX();
	double dy = b.getY() - getY();
	double dz = b.getZ() - getZ();

	double alfa = atan(dy/dx);
	double gamma = atan(dz/sqrt(dx*dx + dy*dy));

	double FZ = E * sin(gamma);
	double FY = E * cos(gamma)*sin(alfa);
	double FX = E * cos(gamma)*cos(alfa);
	
	VectorField risultato(b, FX, FY, FZ);
	return risultato;
}