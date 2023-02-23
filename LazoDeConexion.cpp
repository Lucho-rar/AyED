#include "LazoDeConexion.h"


/*                          Metodos lazo de conexion            */

/*                      bool de vacio       */

bool LazoDeConexion::vacia(){
    if(colaConectora->esvacia()) return true;
    return false;
}


/*                      Carga de paquetes desde un router al lazo       */
void LazoDeConexion::cargarPkg(Paquete* p ){
    if(rand()%10>5){                                //aleatoriedad
        colaConectora->addFinal(p);
    }else{
        colaConectora->add(p);
    }
}

/*                           Lectura de paquetes de la cola     */
Paquete* LazoDeConexion::leerPkg(){
    if (colaConectora->esvacia()){
        cout<<"No tengo paquetes en cola"<<endl;
        return NULL;

    }else{
        Paquete* pkg = colaConectora->comienzo()->get_dato();
        this->colaConectora->borrar();
        return pkg;
        }
}
