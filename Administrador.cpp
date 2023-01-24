#include "Administrador.h"

/*******                                    Metodos ADMINISTRADOR                           ********/


void Administrador::generarRouters(int c){

    for (int i = 0; i < c ; i++){
        Router*r = new Router(i);
        //Router* r = new Router(rand()%10, 2);
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

void Administrador::generarTerminales(){
    for (int i =0 ; i < 25;i++){
        Terminal* t = new Terminal(i);
        terminalesDisponibles->add(t);
    }
}

void Administrador::imprimirListadosDeTerminales(){
    Nodo<Router*>* aux;
    aux = routersDisponibles->comienzo();
    for (int i =0; i < routersDisponibles->size();i++){
        aux->get_dato()->imprimirTerminales();
        aux = aux->get_next();
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

void Administrador::conectarTerminales(int txr){
    Nodo<Router*>* aux;
    aux = routersDisponibles->comienzo();
    for (int i =0;i<routersDisponibles->size();i++){
        for (int j =0;j<txr;j++){
            Terminal* t = new Terminal(j);
            aux->get_dato()->agregarTerminal(t);
        }

        aux = aux->get_next();

    }
}



void Administrador::establecerLazo(int o , int d, int a){
    LazoDeConexion* lazo = new LazoDeConexion(o, d ,a );
    cout<<"\nHe establecido una conexion entre los terminales"<<lazo->getTerminal1()<<
    "y "<< lazo->getTerminal2()<<endl;

}

void Administrador::leerFile(){
    int cantidadRouters, terminalesPorRouter;
    //system("cls");
    ifstream f;
    f.open("config.txt",ios::in);
    string linea;
    //getline(f,linea); /* obtiene routers */
    f>>cantidadRouters;
    f>>terminalesPorRouter; /*obtiene terminal x router*/
    //cout <<cantidadRouters<<terminalesPorRouter<<endl;
    generarRouters(cantidadRouters);
    conectarTerminales(terminalesPorRouter);    
    int origen, destino, ancho;
    f>>origen;
    while (!f.eof()) {
        f>>destino;
        f>>ancho;
        //cout<<num<<" "<<nombre<<" "<<tipo<<" "<<rep<<" "<<endl;
        //Reloj* r = ;
        //Reloj r(num,nombre,tipo,rep);
        //Reloj r(num,nombre,tipo,rep);
        //cout<<origen <<" "<<destino<<" "<<ancho<<endl;
        establecerLazo(origen, destino, ancho);
        
        f>>origen;

    }
    f.close();

}

