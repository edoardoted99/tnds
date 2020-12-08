
#ifndef __Particle_h__
#define __Particle_h__

#include <iostream>
#include <string>
#include "Position.h"
#include "cmath"

using namespace std;



/***********************************************************
 * Classe astratta per una generica Particle
 * definisce i metodi che ogni Particle 
 * deve implementare e delle funzioni di utilizzo generale.
 ***********************************************************/

class Particle {

public:

  // costruttori
  Particle(){
    m_mass=0;
    m_charge=0;
  } ;
  Particle(double mass, double charge){
    m_mass=mass;
    m_charge=charge;
  };

  // distruttore
  ~Particle(){};

  // metodi
  double GetMass() const  {return m_mass;}
  double GetCharge() const {return m_charge;}
  void Print() const {
    cout<<"Particle Mass   = "<<m_mass<<endl;
    cout<<"Particle Charge = "<<m_charge<<endl;
  };

 protected:

  double m_mass;
  double m_charge;

};

/*********************************************************
 * Implementazione concreta di una Particle elementare
 * in questo caso tutte le propriet� della Particle 
 * sono costanti, definite nel costruttore di default.
 ***********************************************************/

class Electron : public Particle {
public:
  // costruttore
  Electron(){
    m_mass=9.1093826*pow(10,-31);
    m_charge=-1.6021766324*pow(10,-19);
  };
  // distruttore
  ~Electron();
  // 
  void Print() const{
    cout<<"Electron Mass   = "<<m_mass<<endl;
    cout<<"Electron Charge = "<<m_charge<<endl;
  };
};

/************************************************************
 * Implementazione concreta di una generica corpo celeste
 * in cui vogliamo poter variare arbitrariamente mass, radius
 * e che vogliamo identificare tramite un name.
 ***********************************************************/


class CorpoCeleste : public Particle {
public:

  CorpoCeleste(std::string name, double mass, double radius){
    m_name=name;
    m_radius=radius;
  };

  ~CorpoCeleste();

  void SetName(std::string name)     {m_name=name;}
  void SetMass(double mass)   {m_mass=mass;}
  void SetRadius(double radius) {m_radius=radius;}
  std::string GetName() const {return m_name;}
  double GetRadius() const {return m_radius;}
  virtual void Print() const;
  void SetPosition(const Position& r) {m_r=r;}
  Position GetPosition() const {return m_r;}

  double PotGrav(const Position& r) const{
    return(-Ggrav*m_mass/r.Distance(GetPosition()));
  };

protected:

  std::string m_name;
  double m_radius;
  Position m_r;

public:
  const double Ggrav=6.67428E-11;

};

#endif // __Particle_h__
