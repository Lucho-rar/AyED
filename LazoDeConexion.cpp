#include "LazoDeConexion.h"


bool LazoDeConexion::vacia(){
    if(colaConectora->esvacia()) return true;
    return false;
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
        return pkg;
        }

        // Paquete* pkg =  this->colaConectora->comienzo()->get_dato();
       // cout<<"lei "<<pkg->getNumeroDePaquete();
    //this->colaConectora->desencolar();

}
