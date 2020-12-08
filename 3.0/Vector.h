#ifndef __Vector_h__
#define __Vector_h__

#include <iostream>
#include <assert.h>

#include <iomanip>
#include <cmath>
#include <cstdlib>

#include "functions.h"


using namespace std;

template <typename T> class Vector{
public:
    Vector(){
        cout<<"Calling deafult constructor"<<endl;
        m_N=0;
        m_v=NULL;
        };
    
    Vector(unsigned int){
        cout<<"Calling defaul constructor dim = "<<N<<endl;
        m_N=N;
        m_v=new T [N];

        for(int i=0; i <N; i++){
            m_v[i]=0;
        }; 
    };

    ~Vector(){
        //cout<<"calling destructor"<<endl;
        delete [] m_v;
    };
    

    unsigned int GetN() const {return m_N;};

    void SetComponent(unsigned int, T){
        m_v[N]=a;
    };
    T GetComponent(unsigned int) const{
        return m_v[N];
    };

    void Swap(unsigned int, unsigned int){
        T temp = GetComponent(m);
        SetComponent(m,GetComponent(n));
        SetComponent(n, temp);
    };
    Vector(const Vector&){
        m_N= v.GetN();
        m_v =new T[m_N];
        for (int i=0; i<m_N; i++)
        {
        m_v[i]=v.GetComponent(i);
        }
    };
    Vector& operator=(const Vector&){
        m_N=v.GetN();
        if(m_v) delete [] m_v;
    
        m_v =new T [m_N];
        for(int i=0; i<m_N; i++){
            m_v[i]=v.GetComponent(i);
        } return *this;
    };

    T& operator[] (unsigned int){
        if(i<m_N){
        return m_v[i];
    }else{
        cerr<<"Error: index to big "<< i << ", dimension "<<m_N <<endl;
        exit(-1);
    }
    };
private:
    unsigned int m_N;
    T * m_v;
};

#endif //__Vector_h__