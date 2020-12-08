
#ifndef __Solutore_h__
#define __Solutore_h__

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <cmath>

#include "FunzioneBase.h"

using namespace std;

class Solutore {
	public:
	
		virtual double CercaZeri(double xmin, double xmax, const FunzioneBase * f) = 0;
		void SetPrecision (double prec) {
			m_prec = prec;
		}
		double GetPrecisione() {
			return m_prec;
		}
	
	protected:
	
		//estremi della regione di ricerca
		double m_a, m_b;
		//precisione della soluzione
		double m_prec;
		const FunzioneBase *m_f;
};

#endif //__Solutore_h__

