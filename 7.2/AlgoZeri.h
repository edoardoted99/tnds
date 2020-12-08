/*
The algorithms to find zeros of a function are coded here. The base class Solutore represents a generic algorithm. Concrete algorithms ( Bisezione, Secanti and Newton ) derive from the baseclass
*/

#ifndef __AlgoZeri_h__
#define __Algozeri_h__

#include "FunzioneBase.h"
#include "Solutore.h"

using namespace std;

class Bisezione : public Solutore {
	public:
	
		Bisezione();
		Bisezione(double xmin, double xmax, double prec, FunzioneBase *f);
		~Bisezione() {};

		//metodi
		
		double CercaZeri(double xmin, double xmax, const FunzioneBase * f);
};


#endif //__AlgoZeri_h__