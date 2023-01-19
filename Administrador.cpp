#include "Administrador.h"

/*******                                    Metodos ADMINISTRADOR                           ********/


void Administrador::generarRouters(){

    for (int i = 0; i < 10 ; i++){
    
        Router* r = new Router(rand()%10, 2);
        this->routersDisponibles->add(r);
    }
}

void Administrador::imprimirListadoDeRouters(){

    cout<<"\nLos routers que tiene a cargo el administrador son: "<<endl;

    Nodo<Router*>* aux;
    aux = routersDisponibles->comienzo();
    
    for (int i =0; i<routersDisponibles->size();i++){
        cout<<"Id: "<<aux->get_dato()->getID()<<endl;
        aux= aux->get_next();
    }

}

void Administrador::RecalcularRutas(){

}

void Administrador::informarCaminos(){
    
}