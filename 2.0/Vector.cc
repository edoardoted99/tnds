#include "Vector.h"
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <assert.h>
#include "functions.h"


Vector::Vector(){
    cout<<"Calling deafult constructor"<<endl;
    m_N=0;
    m_v=NULL;
}
Vector::Vector(unsigned int N){
    cout<<"Calling defaul constructor dim = "<<N<<endl;
    m_N=N;
    m_v=new double [N];

    for(int i=0; i <N; i++){
        m_v[i]=0;
    };    
}

Vector::~Vector(){
    cout<<"calling destructor"<<endl;
    delete [] m_v;
};

void Vector::SetComponent(unsigned int N, double a){
   m_v[N]=a;
}

double Vector::GetComponent(unsigned int N) const {
    return m_v[N];
}

void Vector::Swap(unsigned int m, unsigned int n){
    double temp = GetComponent(m);
    SetComponent(m,GetComponent(n));
    SetComponent(n, temp);
}

Vector::Vector(const Vector& v){
    m_N= v.GetN();
    m_v =new double[m_N];
    for (int i=0; i<m_N; i++){
        m_v[i]=v.GetComponent(i);
    }
};
Vector& Vector::operator=(const Vector& v){
    m_N=v.GetN();
    if(m_v) delete [] m_v;
    m_v =new double [m_N];
    for(int i=0; i<m_N; i++){
        m_v[i]=v.GetComponent(i);
    } return *this;
};
double& Vector::operator[](unsigned int i){
    if(i<m_N){
        return m_v[i];
    }else{
        cerr<<"Error: index to big "<< i << ", dimension "<<m_N <<endl;
        exit(-1);
    }
}