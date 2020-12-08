
#include "Particle.h"
#include <iostream> 

using namespace std;

int main() {

  Particle *a   = new Particle(1.,1.6E-19);
  Electron *e    = new Electron();
  
  // Metodi della classe base
  cout << "Particle " << a->GetMass() << "," << a->GetCharge() << endl;
  a->Print(); 

  // Metods of Daughetr class
  cout << "Electron " << e->GetMass() << "," << e->GetCharge() << endl;
  e->Print(); 

  Particle b(*a) ;  // making a new Particle starting by an existing Particle

    cout<<"Printing b"<<endl;
    b.Print();
    

  Particle d(*e);   // making a nes Particle starting by an  Electron

    cout<<"Printing d"<<endl;
    d.Print();

  //Electron f(d);   //it doesn't have sense !!! -> electron is a DAUGHTER CLASS class of particle. 

  return 0;

}


