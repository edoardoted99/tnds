
#ifndef __Funzioni_h__
#define __Funzioni_h__

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


class Seno : public FunzioneBase {
	public:
		
	//costrutore senza argomenti
	Seno() {m_a = 0; m_b = 0; m_c = 0;};
	//costruttore
	Seno(double a, double b, double c) {m_a = a; m_b = b; m_c = c;};
	//distruttore
	~Seno() {};
	
	virtual double Eval(double x) const {return sin(x);}
	
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

#endif //__Funzioni_h__
