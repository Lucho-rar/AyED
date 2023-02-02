#include "LazoDeConexion.h"


bool LazoDeConexion::vacia(){
    if(colaConectora->esvacia()){
        cout<<"estoy vacia"<<endl;
        return true;
    }else{
        cout<<"segui"<<endl;
        return false;
    }
}



void LazoDeConexion::cargarPkg(Paquete* p ){
    colaConectora->addFinal(p);

}

Paquete* LazoDeConexion::leerPkg(){
    if (colaConectora->esvacia()){
        cout<<"No tengo paquetes en cola"<<endl;
        return NULL;

    }else{
        Paquete* pkg = colaConectora->comienzo()->get_dato();
        this->colaConectora->borrar();
        cout<<colaConectora->comienzo()->get_dato()->getNumeroDePaquete()<<" com "<<endl;
        return pkg;
        }

        // Paquete* pkg =  this->colaConectora->comienzo()->get_dato();
       // cout<<"lei "<<pkg->getNumeroDePaquete();
    //this->colaConectora->desencolar();

}

