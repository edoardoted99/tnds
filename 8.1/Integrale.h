
#ifndef __Integrale_h__
#define __Integrale_h__

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <cmath>

#include "Funzioni.h"

using namespace std;

class Integrale {

	public:
	
		Integrale (double a, double b, const Seno *f);
		double MidPoint (unsigned int nstep);
		double Simpson (unsigned int nstep);
		double GetError();
	
	private:
	
		double m_a;
		double m_b;
		double m_sum;
		double m_h;
		double m_prec;
		double m_err;
		int m_sign;
		double m_integrale;
		const FunzioneBase* m_f;
};

#endif //__Integrale_h__
