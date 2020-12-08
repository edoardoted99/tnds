#include "Position.h"
#include "cmath"

Position::Position(){
    m_x=0;
    m_y=0;
    m_z=0;
};

Position::Position(double x, double y, double z){
    m_x=x;
    m_y=y;
    m_z=z;
}
Position::~Position(){
    
};

double Position::getX() const{
    return m_x;
};
double Position::getY() const{
    return m_y;
}; 
double Position::getZ() const{
    return m_z;
}; 
double Position::getR() const{
    return sqrt(m_x*m_x+m_y*m_y+m_z*m_z);
}
double Position::getPhi() const {
    return atan2(m_y, m_x);
}

double Position::getTheta() const {
    return acos(m_z/getR());
}

double Position::getRho() const{
    return sqrt(m_x*m_x+m_y*m_y);
}

double Position::Distanza(const Position& b) const {
    return sqrt(pow(getX()-b.getX(),2)+pow(getY()-b.getY(),2)+pow(b.getZ()-b.getZ(),2));
}



