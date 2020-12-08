
#ifndef __FunzioneBase_h__
#define __FunzioneBase_h__

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// classe astratta per una generica funzione 
class FunzioneBase {
	public:
		virtual double Eval (double x) const = 0;
};

class Parabola : public FunzioneBase {

	public:
		//costrutore senza argomenti
		Parabola() {
			m_a = 0;
			m_b = 0;
			m_c = 0;
		};
		//costruttore
		Parabola(double a, double b, double c) {
			m_a = a;
			m_b = b;
			m_c = c;
		};
		//distruttore
		~Parabola() {};
	
		virtual double Eval(double x) const {
			return m_a*x*x + m_b*x + m_c;
		}
	
		void SetA(double a) {
			m_a = a;
		}
		void SetB(double b) {
			m_b = b;
		}
		void SetC(double c) {
			m_c = c;
		}
	
		double GetA() const {
			return m_a;
		}
		double GetB() const {
			return m_b;
		}
		double GetC() const {
			return m_c;
		}
	
	private:
	
		double m_a;
		double m_b;
		double m_c;
};

#endif //__FunzioneBase_h__

