#include <iostream>
#include "Particle.h"

using namespace std;

int main(){
    Particle *a=new Particle(1.,2.);
    Electron *e=new Electron();
    Particle *b=new Electron();

    a->Print();
    b->Print();
    b->Print();

    delete a;
    delete b;
    delete e;

    return 0;
};