#ifndef __EquazioniDifferenziali_h__
#define __EquazioniDifferenziali_h__

#include "Algebra.h"
#include <cmath>

using namespace std;

// ===============================================================
// Classe astratta, restituisce la derivata nel punto x al tempo t
// ===============================================================

class FunzioneVettorialeBase {

public:
  virtual vector<double> Eval(double t, const vector<double> & x) const = 0;
};

// ===============================================================
// Caso fisico concreto
// ===============================================================

class OscillatoreArmonico : public FunzioneVettorialeBase {

public:

  OscillatoreArmonico(double omega0) { m_omega0 = omega0; };

  virtual vector<double> Eval(double t, const vector<double> &x) const {

    vector<double> dxdt {x[1], - (m_omega0*m_omega0*x[0])};

    return dxdt;
    };
    double GetOmega0 () {return m_omega0;};

		void SetOmega0 (double a) { m_omega0 = a;};


   
  

private:
  double m_omega0;
};

// ===============================================================
// Classe astratta per un integratore di equazioni differenziali
// ===============================================================

class EquazioneDifferenzialeBase {
public:
   virtual vector<double> Passo(double t, const vector<double> &x, double h, FunzioneVettorialeBase *f) const = 0;
};

// ===============================================================
// Integratore concreto, metodo di Eulero
// ===============================================================

class Eulero : public EquazioneDifferenzialeBase {
public:

  vector<double> Passo(double t, const vector<double> &x, double h, FunzioneVettorialeBase *f) const {

    return x+(f->Eval(t,x))*h;

  };
};

#endif // __EquazioniDifferenziali_h__