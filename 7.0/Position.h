


#ifndef __Position_h__
#define __Position_h__

class Position {

public:

  // costruttori
  Position();
  Position(double x, double y, double z); 
  // distruttore
  ~Position();
  // metodi
  double getX() const;       // Coordinate cartesiane
  double getY() const;
  double getZ() const;
  double getR() const;       // Coordinate sferiche
  double getPhi() const;
  double getTheta() const;
  double getRho() const;     // raggio delle coordinate cilindriche
  double Distance(const Position&) const; // distanza da un altro punto

private:

  double m_x, m_y, m_z;  

};

#endif // __position_h__




