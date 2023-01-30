#include "SistemaEmpaquetado.h"


void SistemaEmpaquetado::addPaquete(Paquete *p){
    f.add(p);
    //paquetes->addFinal(p);
  //  cout<<"Paquete "<<p->getNumeroDePaquete()<< "agregado"<<endl;
}