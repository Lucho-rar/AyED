#include "SistemaEmpaquetado.h"

void SistemaEmpaquetado::addPaquete(Paquete *p){
    listadepaquetes->addFinal(p);
    //paquetes->addFinal(p);
  //  cout<<"Paquete "<<p->getNumeroDePaquete()<< "agregado"<<endl;
}

void SistemaEmpaquetado::imprimir(){
    Nodo<Paquete*>* aux;
    aux = listadepaquetes->comienzo();
    for (int i = 0 ; i < listadepaquetes->size();i++){
        cout<<aux->get_dato()->getNumeroDePaquete()<<endl;
        aux = aux ->get_next();
    }
}