#include "Administrador.h"
#include "SistemaEmpaquetado.h"
/*******                                    Metodos ADMINISTRADOR                           ********/


void Administrador::generarRouters(int c){

    this->cantidadDeRouters = c;
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
    this->terminalesPorRouter = txr;
    Nodo<Router*>* aux;
    aux = routersDisponibles->comienzo();
    for (int i =0;i<routersDisponibles->size();i++){
        for (int j =0;j<txr;j++){
            int v[2]={i,j};
            Terminal* t = new Terminal(v);
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
       // Peso* p = new Peso(origen,destino,0);
       // pesos->addFinal(p);
        f>>origen;

    }
    f.close();

}

void Administrador::crearPaginas(){
    Nodo<Router*>* aux;
    aux = routersDisponibles->comienzo();
    int NumeroRandomOR = rand() % cantidadDeRouters;
    int NumeroRandomOT = rand() % terminalesPorRouter;
    cout<<"origen "<<NumeroRandomOR<<" "<<NumeroRandomOT<<endl;
    int ipOrigen[2]={NumeroRandomOR,NumeroRandomOT};
    int NumeroRandomDR = rand() % cantidadDeRouters;
    int NumeroRandomDT = rand() % terminalesPorRouter;
    cout<<"destino "<<NumeroRandomDR<<" "<<NumeroRandomDT<<endl;
    int ipDestino[2]={NumeroRandomDR,NumeroRandomDT};
        //int origen = aux->get_dato()->getID();
    Pagina* p = new Pagina(simPag,10, ipOrigen, ipDestino);
    simPag++;
    //routersDisponibles->buscarPorIndice(ipOrigen[0])->recibirPag(p);
    cout << "\033[1;31mCREE LA PAGINA "<<p->getidentificadorDePag()<<"\033[0m\n";
    //cout<<routersDisponibles->buscarPorIndice(NumeroRandomOR)->getID()<<endl;
    routersDisponibles->buscarPorIndice(NumeroRandomOR)->recibirPag(p);
    
}

void Administrador::imprimirPaginasPorRouter(){
    Nodo<Router*>* aux;
    aux = routersDisponibles->comienzo();
    for ( int i = 0 ; i < routersDisponibles->size(); i++){
        aux->get_dato()->imprimirPaginas();
        aux = aux -> get_next();
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

}

void Administrador::insertarPaquetesEnLosLazos(){
}

void Administrador::paquetes(){
    Nodo<Router*>* aux;
    aux = routersDisponibles->comienzo();
    for (int i = 0 ; i<routersDisponibles->size();i++){
        aux->get_dato()->imprimirPaquetes();
        aux = aux->get_next();
    }
}

void Administrador::calcularTablaDeEnrutamiento(){
    Nodo<Router*>* aux;
    aux = routersDisponibles->comienzo();
    for (int i = 0 ; i < routersDisponibles->size();i++){
        Nodo<LazoDeConexion*>* aux1;
        aux1=aux->get_dato()->getIda()->comienzo();
        cout<<"Soy el router "<<aux->get_dato()->getID()<<
        " y puedo enviar datos a "<<endl;
        for (int j =0; j < aux->get_dato()->getIda()->size();j++){
            cout<<aux1->get_dato()->getTerminal2()<<endl;
            aux1= aux1->get_next();
        }

        aux = aux->get_next();
    }
}
void Administrador::enviarPaquetes(){
    Nodo<Router*>* aux;
    aux = routersDisponibles -> comienzo();
    for (int i = 0 ; i < routersDisponibles->size();i++){
        aux->get_dato()->enviarPaquetes();
        aux = aux -> get_next();
    }   
}
void Administrador::recibirPaquetes(){
    Nodo<Router*>* aux;
    aux = routersDisponibles -> comienzo();
    for (int i = 0 ; i < routersDisponibles->size();i++){
        aux->get_dato()->recibirPaquetes();
        aux = aux -> get_next();
    }   
}

void Administrador::simular(){
    
}
        /* voy a declarar dijsktra en base a lo de clase para abrir ideas y en base
        a ello redefinir metodos que tengo */

void Administrador::AlgDis(int ini){
    Lista<int> Q;
    Lista<Direccion*>* direcciones = new Lista<Direccion*>();
    Lista<int> conocidos;
    int pre[cantidadDeRouters];
    for (int i = 0 ; i < listaDeConexiones->size() ;i++){
        listaDeConexiones->buscarPorIndice(i)->calcularPeso();
    }

    for (int i = 0; i<routersDisponibles->size();i++){
        if(i == ini){
            Direccion* direccion = new Direccion(i,0,0);
            direcciones->addFinal(direccion);
            pre[i]=ini;
        }else{
            Direccion* direccion = new Direccion(i,-1,INFI);
            direcciones->addFinal(direccion);
            pre[i]=-1;
        }
        Q.addFinal(i);
    }
    


    

}

void Administrador::paseAlg(){

    for (int i = 0 ; i < routersDisponibles->size();i++){
        this->AlgAlt(i);
    }
}

void Administrador::AlgAlt(int ini){
    Lista<int> Q;
    int C[cantidadDeRouters];
    
    for (int i = 0 ; i <listaDeConexiones->size();i++){
       // cout<<listaDeConexiones->buscarPorIndice(i)->getTerminal1()<<"|"<<listaDeConexiones->buscarPorIndice(i)->getTerminal2()<<"|";
        //cout<<listaDeConexiones->buscarPorIndice(i)->getcolaconectora()->size()<<endl;
        listaDeConexiones->buscarPorIndice(i)->calcularPeso();
    }
    
    for (int i = 0; i < routersDisponibles->size();i++){
        Router* routerAnalisis= routersDisponibles->buscarPorIndice(i);
        if(i == ini){
            C[ini]=0;
        }else if(routersDisponibles->buscarPorIndice(ini)->esVecino(i)){
           // cout<<"lo contiene"<<endl;
            int aux = 0;
            for(int j = 0 ; j < listaDeConexiones->size(); j ++){
                if((listaDeConexiones->buscarPorIndice(j)->getTerminal1()==ini && listaDeConexiones->buscarPorIndice(j)->getTerminal2()==i)
                || (listaDeConexiones->buscarPorIndice(j)->getTerminal1()==i && listaDeConexiones->buscarPorIndice(j)->getTerminal2()==ini)){
                    aux = listaDeConexiones->buscarPorIndice(j)->getPeso();
                }
            }
            C[i]=aux;
        }else{
            C[i]=INFI;
        }
    }
    for (int i =0; i<cantidadDeRouters;i++){
        cout<<C[i]<<" ";
    }
    cout<<endl;
}