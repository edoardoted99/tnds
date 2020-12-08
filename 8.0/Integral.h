
#ifndef __Integral_h__
#define __Integral_h__

#include "Funzioni.h"

class Integral{

	public:
		Integral(double a, double b, const FunzioneBase* f);
		double MidPoint(unsigned int nstep);
		double Simpson(unsigned int nstep);

	private:
		double m_a, m_b;
		double m_sum;
		double m_h;
		int m_sign;
		double m_integral;
		const FunzioneBase* m_f;
};

#endif //__INTEGRAL_H__