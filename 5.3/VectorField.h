
#ifndef __VectorField_h__
#define __VectorField_h__

#include "Position.h"
#include "cmath"

class VectorField : public Position {

public:

  VectorField(const Position& p){

      m_Fx=0;
      m_Fy=0;
      m_Fz=0;

  };
  VectorField(const Position& p, double Fx, double Fy, double Fz){
      
      m_Fx=Fx;
      m_Fy=Fy;
      m_Fz=Fz;
      

  };
  VectorField(double x, double y, double z, double Fx, double Fy, double Fz){
      m_Fx=Fx;
      m_Fy=Fy;
      m_Fz=Fz;

  };
  ~VectorField(){};

  VectorField operator+( const VectorField & v) const {

      VectorField sum(v);

      sum.m_Fx += getFx();
      sum.m_Fy += getFy();
      sum.m_Fz += getFz();

      return sum;
  } ;
  VectorField & operator+=( const VectorField & v) {
      return (*this) = (*this) +v;
  };
  
  double getFx() const {return m_Fx;}
  double getFy() const {return m_Fy;}
  double getFz() const {return m_Fz;}

  double Modulo(){
      return sqrt(m_Fx*m_Fx+m_Fy*m_Fy+m_Fz*m_Fz);
  };

private:

  double m_Fx, m_Fy, m_Fz;

};

#endif // __VectorField_h__ 

