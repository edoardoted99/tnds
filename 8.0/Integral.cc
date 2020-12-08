/*
#include "Integral.h"
#include <algorithm>

using namespace std;

Integral::Integral(double a, double b, const FunzioneBase* f){

   m_f = f;
   m_a = min(a,b);
   m_b = max(a,b);
   if ( a > b) m_sign = -1;
   else m_sign = 1;   
}

double Integral::Midpoint(unsigned int nstep){

   m_h = (m_b - m_a)/double(nstep);
   m_sum = 0.;

   for (unsigned int i=1; i<nstep; i++){
     m_sum += m_f->Eval( m_a + (i+0.5)*m_h );
   }	

   m_integral = m_sign*m_sum;

   return m_integral;
}
*/



#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <cmath>

#include "Integral.h"

using namespace std;

Integral::Integral (double a, double b, const FunzioneBase* f) {

	m_f = f;
	m_a = min(a, b);
	m_b = max(a, b);
	
	if (a > b) 
		m_sign = -1;
	else
		m_sign = 1;
}

double Integral::MidPoint (unsigned int nstep) {

	m_h = (m_b - m_a)/nstep;
	m_sum = 0.;
	
	for (int i=1; i<=nstep; i++)
		m_sum += m_f -> Eval((m_a + (i + 0.5)* m_h)/2.);
	
	m_integral = m_sign * m_sum * m_h;
	
	return m_integral;
}