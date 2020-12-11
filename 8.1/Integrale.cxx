
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <cmath>

#include "Integrale.h"

using namespace std;

Integrale::Integrale (double a, double b, const Seno* f) {

	m_f = f;
	m_a = min(a, b);
	m_b = max(a, b);
	
	if (a > b) 
		m_sign = -1;
	else
		m_sign = 1;
}

double Integrale::MidPoint (unsigned int nstep) {

	m_h = (m_b - m_a)/nstep;
	m_sum = 0.;
	
	//(f(a) + f(b))/2 * (b - a)
	for (int i=1; i<nstep; i++)
		m_sum += m_f -> Eval((m_a + (i + 0.5)* m_h)/2.);
	
	m_integrale = m_sign * m_sum * m_h;
	
	return m_integrale;
}

double Integrale::Simpson (unsigned int nstep) {
	
	if(nstep%2 == 1)
		nstep = nstep+1;
	m_h = (m_b - m_a)/nstep;
	m_sum = 0.;
	
	for (int i=1; i<nstep; i=i+2)
		m_sum += m_h/3. * (m_f -> Eval(m_a+i*m_h) * m_f -> Eval(m_a + (i+1)*m_h) + 4 + m_f -> Eval(m_a + (i+2)*m_h));
	
	//(f(A+i*dx)+4 * f(A+(i+1)*dx)+ f(A+(i+2)*dx));
	
	//errore
	m_err = pow ((m_b - m_a), 5)/2880. * m_f -> Eval ((m_a + m_b)/2.);
		
	return m_sum;
}

double Integrale::GetError () {
	return m_err;
}