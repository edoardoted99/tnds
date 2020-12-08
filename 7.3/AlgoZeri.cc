
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <cmath>

#include "FunzioneBase.h"
#include "Solutore.h"
#include "AlgoZeri.h"

using namespace std;

int sign(double x){

 if(x<0)
   return -1;
 else 
   return 1;
}

Bisezione::Bisezione() {
	m_a=0.;
	m_b=0.;
	m_prec=0.;
	m_f=NULL;
}

Bisezione::Bisezione(double a, double b, double prec, FunzioneBase* f) {
	m_a=a;
	m_b=b;
	m_prec=prec;
	m_f=f;
}

/*
double Bisezione::CercaZeri(double xmin, double xmax, const FunzioneBase * f) {
	
	Segno sign;
	m_niter = 0;
	m_f = 0;
	
	if (xmin < xmax) {
		m_a = xmin;
		m_b = xmax;	
	} else {
		m_b = xmin;
		m_a = xmax;	
	}
	
	double fa = m_f -> Eval(m_a);
	double fb = m_f -> Eval(m_b);
	
	while ((m_b - m_a) > m_prec) {
		double c = 0.5*(m_b + m_a);
		double fc = m_f -> Eval (c);

		if (m_niter > nmax)
			break;
		m_niter++; 
		if (sign.Eval(fa)*sign.Eval(fc) <= 0) {
			m_b = c;
			fb = fc;
		} 
		else if (sign.Eval(fb)*sign.Eval(fc) <= 0) {
			m_a = c;
			fa = fc;
		}
		else return 0.;
	}
	return 0.5*(m_b + m_a);
}
*/
//segno funzione

/*
double Bisezione::CercaZeri(double xmin, double xmax, const FunzioneBase * f) {

	
	//mettere xmax>xmin
	if (xmax<xmin) {
		double temp=0.;
		temp = xmin;
		xmin = xmax;
		xmax = temp;
	}
	//midpoint
	double c = 0.;

	if((f->Eval(xmin))==0){
		c = xmin;
		return c;
	}
	else if((f->Eval(xmax))==0){
		c=xmax;
		return c;
	}

	else { 
		int i=0;
		while(abs(xmax-xmin) >= m_prec){
			c = xmin + 0.5*(xmax-xmin);
			
			if(f->Eval(c)==0) {
				cout << "no1" << endl;
				return c;
				cout << "no2" << endl;
			}
			else if ((f->Eval(xmin)) * (f->Eval(c))<0) {
				
				xmax=c;
				cout << "forse" << endl;
				
			}
			else if((f->Eval(xmax)) * (f->Eval(c))<0) {
				xmin=c;
				cout << "sì" << endl;
				
			} i++;
			if (i==1000000){
				cout<<"nessuno zero trovato"<<endl; exit(-3);
			}
		}
	}
	//continue;

	return c;
}*/

double Bisezione::CercaZeri(double xmin, double xmax, const FunzioneBase * f){
	m_f=f;
	int niterations=0;

	m_a=min(xmin,xmax);
	m_b=max(xmin,xmax);

	double fa=m_f->Eval(m_a);
	double fb=m_f->Eval(m_b);

	if(fa==0 || fb == 0){
		double t;

		if(fa==0){
			t=m_a;
		}else{
			t=m_b;
		}

		cout<< "lo zero viene assunto nell'estremo dell'intervallo assegnato, tale che f("<<t<<")=0"<<endl;
		return t;
	}

	else if (sign(fa)*sign(fb)>0){
		cout << "Questo intervallo non presenta un SINGOLO zero della funzione" << endl;
		exit( 0);
	}

	else if (sign(fa)*sign(fb)<0){
		cout<<"Inizio ricerca zero tramite metodo della Bisezione, attendere..."<<endl;

		while(m_prec<fabs((m_b-m_a)))	{					//controllo sulla precisione

			double c = (m_b+m_a)/2.;					//punto medio
			double fc = m_f-> Eval (c);
			
			niterations++;
			//cout<<niterations<<endl;

			if (niterations==1000) 	{ 					//non converge

				cout << "ERROR Nell'intervallo non sono stati trovati zeri!"<<endl;
				cout << "Il numero di iterazioni effettuate è stato di "<< niterations<<" Abbassare il livello di precisione"<<endl;
				exit(-15);

			}
			
			else if (fc == 0)	{					//caso in cui il punto medio sia uno zero

				cout << "Lo zero viene assunto dalla funzione in x= ";
				return c;

			}

			else if (sign(fa)*sign(fc)<0) {					//ricerca intervallo sinistro
				
				m_b=c; 
				fb=fc;

			}
			
			else if (sign(fb)*sign(fc)<0) {					//ricerca intervallo destro
				
				m_a=c; 
				fa=fc;

			}
			
	
		}
		
		cout<<"Zero trovato in x=";
		return 0.5*(m_b+m_a);
	}
		

}

