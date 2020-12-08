#ifndef __MaterialPoint_h__
#define __MaterialPoint_h__

#include "Particle.h"
#include "Position.h"

#include "VectorField.h"

class MaterialPoint : public Particle, Position {

public:

  MaterialPoint(double mass, double charge, const Position& p);
  MaterialPoint(double mass, double charge, double x, double y, double z);
  ~MaterialPoint(){};

  VectorField CampoElettrico(const Position& p) const;


  //VectorField CampoGravitazionale(const Position&) const;

};

#endif // __MaterialPoint_h__



