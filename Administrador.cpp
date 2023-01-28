#include "Administrador.h"

/*******                                    Metodos ADMINISTRADOR                           ********/


void Administrador::generarRouters(int c){

    for (int i = 0; i < c ; i++){
        Router*r = new Router(i);
        //Router* r = new Router(rand()%10, 2);
        this->routersDisponibles->addFinal(r);
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

void Administrador::pruebaIndice(){

    Lista<int>* l = new Lista<int>();
    l->add(3);
    
    l->add(5);
    l->addFinal(9);
    Nodo<int>* aux ;
    aux = l->comienzo();
    cout<<l->buscarPorIndice(2)<<endl;
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
            routersDisponibles->buscarPorIndice(i)->agregarTerminal(terminalesDisponibles->buscarPorIndice(j));
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
    //LazoDeConexion* vuelta = new LazoDeConexion(d, o ,a );
    //cout<<"\n ida "<<ida->getTerminal1()<<" a "<< ida->getTerminal2()<<endl;
    //cout<<"vuelta "<<vuelta->getTerminal1()<<" a "<<vuelta->getTerminal2()<<endl;
    cout<<"Estoy estableciendo lazo" <<routersDisponibles->buscarPorIndice(o)->getID()<<"y "<<
    routersDisponibles->buscarPorIndice(d)->getID()<<endl;
    
    routersDisponibles->buscarPorIndice(o)->agregarLazoIda(lazo);
    routersDisponibles->buscarPorIndice(d)->agregarLazoVuelta(lazo);
    listaDeConexiones->addFinal(lazo);
    //listaDeConexiones->addFinal(vuelta);
   // routersDisponibles->buscarPorIndice(o+size()-1);

    examinarRouterPorID(o,d);
}

void Administrador::examinarRouterPorID(int o, int d){
    Nodo<Router*>* aux;
    aux = routersDisponibles->comienzo();

    for (int i =0 ; i<routersDisponibles->size();i++){
        if(aux->get_dato()->getID() == o){
            aux->get_dato()->agregarVecino(d);
            
        }else if(aux->get_dato()->getID() ==d){
            aux->get_dato()->agregarVecino(o); 
        }
        aux = aux->get_next();
    }

    aux = routersDisponibles->comienzo();
    /*
    for (int j = 0; j<routersDisponibles->size();j++){
        aux->get_dato()->imprimirVecinos();
        aux= aux->get_next();
    }*/

}

void Administrador::matchDeLazos(){

}


void Administrador::imprex(){
    Nodo<Router*>* aux;
    aux = routersDisponibles->comienzo();
    for (int i =0 ; i<routersDisponibles->size();i++){
        aux->get_dato()->imprimirVecinos();
        aux = aux ->get_next();    }
}

void Administrador::imprimirLazos(){
    Nodo<LazoDeConexion*>* aux;
    aux = listaDeConexiones->comienzo();
    for (int i =0; i < listaDeConexiones->size();i++){
        cout<<"Conexion entre "<<aux->get_dato()->getTerminal1()<<" y "<<aux->get_dato()->getTerminal2()
        <<" con un ancho de banda "<<aux->get_dato()->getBW()<<endl;
        aux= aux->get_next();
    }
    Nodo<Router*>* s;
    s = routersDisponibles->comienzo();

    for( int i = 0; i <routersDisponibles->size();i++){
        s->get_dato()->imprimirLazosConectados();
        s = s -> get_next();
    }
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
        //LazoDeConexion* ida = new LazoDeConexion(origen, destino ,ancho );
        //LazoDeConexion* vuelta = new LazoDeConexion(destino,origen,ancho);
       // cout<<routersDisponibles->buscarPorIndice(origen)->get_dato()->getID()<<"ssss"<<endl;
        establecerLazo(origen, destino, ancho);
        
        
        f>>origen;

    }
    f.close();

}

void Administrador::crearPaginas(){
    Nodo<Router*>* aux;
    aux = routersDisponibles->comienzo();

    for (int i =0; i <routersDisponibles->size();i++){
        //int origen = aux->get_dato()->getID();
        Pagina* p = new Pagina(i,20, 0, 1);
        aux->get_dato()->agregarPagina(p);
        aux= aux->get_next();
    }
}

void Administrador::segmentarPaginas(){
    Nodo<Router*>* aux;
    aux = routersDisponibles->comienzo();

    for (int i =0;i<routersDisponibles->size();i++){
        aux->get_dato()->segmentarPag();
        aux = aux ->get_next();
    }

    aux = routersDisponibles->comienzo();

    for (int i = 0 ; i < routersDisponibles->size();i++){
        aux->get_dato()->imprimirPaginas();
        aux = aux->get_next();
    }

    aux = routersDisponibles->comienzo();

    for (int j = 0 ; j <routersDisponibles->size();j++){
        aux->get_dato()->imprimirPaquetes();
        aux= aux->get_next();
    }
}

void Administrador::insertarPaquetesEnLosLazos(){
}
