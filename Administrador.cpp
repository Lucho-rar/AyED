#include "Administrador.h"

/*******                                    Metodos ADMINISTRADOR                           ********/


void Administrador::generarRouters(){

    for (int i = 0; i < 10 ; i++){
        Router*r = new Router(i,1+rand()%2);
        //Router* r = new Router(rand()%10, 2);
        this->routersDisponibles->add(r);
    }
}


void Administrador::imprimirListadoDeRouters(){

    cout<<"\nLos routers que tiene a cargo el administrador son: "<<endl;

    Nodo<Router*>* aux;
    aux = routersDisponibles->comienzo();
    
    for (int i =0; i<routersDisponibles->size();i++){
        cout<<"Id: "<<aux->get_dato()->getID()<<"  BW: "<<aux->get_dato()->getBW()<<endl;
        aux= aux->get_next();
    }

}

void Administrador::generarTerminales(){
    for (int i =0 ; i < 25;i++){
        Terminal* t = new Terminal(i);
        terminalesDisponibles->add(t);
    }
}

void Administrador::imprimirListadosDeTerminales(){
    Nodo<Terminal*>* aux;
    aux = terminalesDisponibles->comienzo();
    cout<<"\nLista de terminales disponibles para conectar: "<<endl;
    for(int i = 0 ; i < terminalesDisponibles->size();i++){
        cout<<"IP: "<<aux->get_dato()->getIP()<<endl;
        aux= aux->get_next();
    }

}

void Administrador::establecerConexiones(){
    Nodo<Router*>* auxRout;
    auxRout = routersDisponibles->comienzo();
    for (int i = 0; i< routersDisponibles->size();i++){
        for (int j = 0; j< terminalesDisponibles->size();j++){
            routersDisponibles->buscarPorIndice(i)->get_dato()->agregarTerminal(terminalesDisponibles->buscarPorIndice(j)->get_dato());
        }
    }
}

void Administrador::imprimirConexiones(){
    Nodo<Router*>* aux;
    aux = routersDisponibles->comienzo();
    cout<<"\nTerminales por routers: "<<endl;
    for (int i =0; i<routersDisponibles->size() ; i++){
        if(aux!=NULL){
            aux->get_dato()->imprimirTerminales();
        }
        aux = aux -> get_next();
    }
}



void Administrador::RecalcularRutas(){

}

void Administrador::informarCaminos(){
    
}