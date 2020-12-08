#ifndef __Vector_h__
#define __Vector_h__

#include <iostream>

using namespace std;

class Vector{
public:
    Vector();
    Vector(unsigned int);
    ~Vector();

    unsigned int GetN() const {return m_N;}
    void SetComponent(unsigned int, double);
    double GetComponent(unsigned int) const;

    void Swap(unsigned int, unsigned int);
    Vector(const Vector&);
    Vector& operator=(const Vector&);
    double& operator[] (unsigned int);
private:
    unsigned int m_N;
    double * m_v;
};

#endif //__Vector_h__