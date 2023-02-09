#include "Router.h"
#include "hash.h"
/*          Metodos Router      */

void Router::enviarPaquete(){

}

void Router::recibirPag(Pagina* p){

    //cout<<p->getDestino()[0]<<"////"<<endl;
    //this->listaDePaginas->addFinal(p);
    for (int i = 0 ; i < p->getTamanioDePag();i++){
        Paquete* pkg = new Paquete (i,p,p->getOrigen(),p->getDestino(), p->getTamanioDePag());
      //  cout<<"\n Paquete"<<endl;
     //   cout<<i << p->getidentificadorDePag()<<" "<<p->getOrigen()[0]<<"=>"<<p->getDestino()[0]<<endl;
        //this->addPaquete(pkg);
        this->paquetes->addFinal(pkg);
    }

    // empaque -> imprimir();
    //this->empaquetador = empaque;

}


void Router::agregarPagina(Pagina* p){
    this->listaDePaginas->addFinal(p);
}


void Router::segmentarPag(){
    Nodo<Pagina*>* aux;
    aux = listaDePaginas->comienzo();
    int identificador;
    for (int i = 0 ; i < listaDePaginas->size();i++){
        int tamanioDePaquetes = (10 * aux->get_dato()->getTamanioDePag())/100;
        int cantidadDePaquetes = aux->get_dato()->getTamanioDePag()/tamanioDePaquetes;    
        for (int j = 0 ; j < cantidadDePaquetes;j++){
            
          //  Paquete* paq = new Paquete(j,aux->get_dato(), aux->get_dato()->getOrigen(),aux->get_dato()->getDestino(),tamanioDePaquetes );
               
          //  colaDeEnvio->addFinal(paq);    
            
        }
        aux = aux->get_next();
    }
}

void Router::agregarTerminal(Terminal* t){
   // cout<<"Reconocido desde el router"<<endl;
    t->conectarseAUnRouter(this);
    terminalesConectados->addFinal(t);
}

void Router::agregarVecino(int id) {
    Router* r = new Router(id);
    //cout<<"Tengo un vecino nuevo y es el router de id "<<id<<endl;
    listaDeVecinos->addFinal(r);
}

void Router::imprimirTerminales(){
    Nodo<Terminal*>* aux;
    aux= terminalesConectados->comienzo();
    cout<<"\nSOY EL ROUTER "<<id<<" y estos son los terminales que tengo conectados: "<<endl;

    for (int i =0; i< terminalesConectados->size() ; i++){
        cout<< aux->get_dato()->getIP()<<endl;
        aux = aux->get_next();
    }
}

void Router::imprimirVecinos(){
    Nodo<Router*>* aux;
    aux = listaDeVecinos->comienzo();
    cout<<"\nSoy el router "<<id<<" y estos son mis vecinos: "<<endl;
    for (int i =0;i <listaDeVecinos->size();i++){
        cout<<aux->get_dato()->getID()<<endl;
        aux = aux->get_next();
    }

}

void Router::imprimirPaginas(){
    Nodo<Pagina*>* aux;
    aux = listaDePaginas->comienzo();

    for(int i = 0; i < listaDePaginas->size(); i++)
    {
        cout<<"\nDatos de pagina: "<<endl;
        cout<<"identificador: "<<aux->get_dato()->getidentificadorDePag()<<endl;
        cout<<"tamanio: "<<aux->get_dato()->getTamanioDePag()<<endl;
        cout<<"origen: "<<aux->get_dato()->getOrigen()[1]<<endl;
        cout<<"destino: "<<aux->get_dato()->getDestino()[1]<<endl;
    }
    
}

void Router::imprimirPaquetes(){
   // empaquetador = new SistemaEmpaquetado();
    //cout<<"\nSoy el router "<<this->getID()<<endl;
    //cout<<"Paquetes que tengo :"<<endl;
    cout<<endl;
    cout << "\033[1;31mPaquetes del router "<<this->getID()<<" \033[0m\n"<<endl;
    cout<<"Numero de paquete | Origen | Destino | IdPaginaMadre"<<endl;
    Nodo<Paquete*>* aux;
    aux = paquetes->comienzo();
    for (int i = 0 ; i < paquetes->size();i++){
        //cout<<aux->get_dato()->getNumeroDePaquete()<<" paquete de " <<aux->get_dato()->getPaginaMadre()->getOrigen()[0]<<
        //aux->get_dato()->getDestino()[0]<<aux->get_dato()->getEstado()<<endl;
        cout<<aux->get_dato()->getNumeroDePaquete()<<"                     "<<aux->get_dato()->getOrigen()[0]<<":"<<aux->get_dato()->getOrigen()[1]
        <<"       "<<aux->get_dato()->getDestino()[0]<<":"<<aux->get_dato()->getDestino()[1]<<"        "<<aux->get_dato()->getPaginaMadre()->getidentificadorDePag()<<"         "<<aux->get_dato()->getEstado()<<endl;

        aux = aux ->get_next();
    }
   // this->empaquetador.imprimir();
}

void Router::imprimirLazosConectados(){
    Nodo<LazoDeConexion*>* aux;
    aux = this->ida->comienzo();
    cout<<"\nSoy el router "<<this->getID()<<" y estos son los lazos:"<<endl;
    cout<<"de ida: "<<endl;
    for (int i =0;i<ida->size();i++){
        cout<<aux->get_dato()->getTerminal1()<<" ----> "<<aux->get_dato()->getTerminal2()<<endl;
        aux = aux->get_next();
    }
    aux = this->vuelta->comienzo();
    cout<<"de veulta"<<endl;
    for (int i =0;i<vuelta->size();i++){
        cout<<aux->get_dato()->getTerminal1()<<" ----> "<<aux->get_dato()->getTerminal2()<<endl;
        aux=aux->get_next();
    }

}

int Router::comprobarDestino(int dir){
    
    for (int i = 0 ; i < ida ->size() ; i ++){
        //cout<<f;
        if ( ida->buscarPorIndice(i)->getTerminal2() == dir){
           return i;
        }
    }
    return 9999;

}


void Router::sacarPkg(Paquete * r){
    /*
    Nodo<Paquete*>* aux;
    aux = paquetes->comienzo();

    for (int i = 0 ; i < paquetes->size();i++){
        if (aux->get_dato() == r){
            paquetes->borrarNodo(i);
        }
        aux = aux->get_next();
    }*/

}




void Router::enviarPaquetes(){
    bool bw=0;
    bool aux;
    int x ;
    if (paquetes->esvacia()){
         cout<<"[R"<<this->id<<"] No hay paquetes para este router. "<<endl;
    }else{
        
        for(int i = 0 ; i < paquetes->size() ; i ++){
           
            int x =comprobarDestino(paquetes->buscarPorIndice(i)->getDestino()[0]);
            
            if (x!=9999){
                int l = paquetes->buscarPorIndice(i)->getNumeroDePaquete();
                //cout<<x<<"}}}}}}}}}}"<<endl;
                
                int indice = buscarlazo(l);
                //cout<< ida->buscarPorIndice(x)->getTerminal2()<<"}}}}}}}}}"<<endl;
                cout<<"[R"<<this->id<<"] Envio directo a R"<<paquetes->buscarPorIndice(i)->getDestino()[0]<<" porque es vecino. "<< /* paquetes->buscarPorIndice(i)->getDestino()[0]<<x<*/endl;
                ida->buscarPorIndice(x)->cargarPkg(paquetes->buscarPorIndice(i));
                //this->buscarlazo(x)->cargarPkg(paquetes->buscarPorIndice(i));
                paquetes->buscarPorIndice(i)->setEstado();
               // sacarPkg(paquetes->buscarPorIndice(i));
               // paquetes->borrar();
               // cout<<"borre "<<l<<endl;
            

            }else if(buscarEnTabla(paquetes->buscarPorIndice(i)->getDestino()[0])!=9999){
                int y = buscarEnTabla(paquetes->buscarPorIndice(i)->getDestino()[0]);
                //cout<<y<<"***********************"<<endl;
                int l = paquetes->buscarPorIndice(i)->getNumeroDePaquete();
                int indice = buscarlazo(y);
                cout<<"[R"<<this->id<<"] No tengo camino directo a R"<<paquetes->buscarPorIndice(i)->getDestino()[0]<<" pero lo puedo enrutaren  "<<endl;
                cout<<ida->buscarPorIndice(indice)->getTerminal1()<<"->"<<ida->buscarPorIndice(indice)->getTerminal2()<<endl;
                
                ida->buscarPorIndice(indice)->cargarPkg(paquetes->buscarPorIndice(i));
                //this->buscarlazo(y)->cargarPkg(paquetes->buscarPorIndice(i));
                paquetes->buscarPorIndice(i)->setEstado(); 
                //paquetes->borrar();
               // sacarPkg(paquetes->buscarPorIndice(i));
                //paquetes->borrar();
               
            }else{
                cout<<"[R"<<this->id<<"] No hay ruta para este paquete. "<<endl;
            }
            
        }

        Nodo<Paquete*>* aux;
        if(paquetes->comienzo()!=NULL){
            aux = paquetes->comienzo();
        }
        int tope = paquetes->size(); 
        ///int tope =2;
        for (int i = 0 ; i < tope;i++){
            if (aux->get_dato()->getEstado()==true) paquetes->borrarUltimo();
        }
    }

}



void Router::recibirPaquetes(){

   // cout<<this->id<<endl;
    if (!vuelta->esvacia()){
       // cout<<this->id<<" puedo recibir"<<endl;
        for (int i =0 ; i < vuelta->size();i++){
            if(vuelta->buscarPorIndice(i)->vacia()==true){
              //  cout<<"Vacia"<< this->id<<endl;
            }else{
                int cont =vuelta->buscarPorIndice(i)->getBW();
                //int cont = vuelta->buscarPorIndice(i)->getcolaconectora()->size()-1;
                while(cont>=0/*vuelta->buscarPorIndice(i)->vacia()!=true*/){
                    Paquete* pkg0 = vuelta->buscarPorIndice(i)->leerPkg();
                    
                    if (pkg0!=NULL){
                        this->vincularConKey(pkg0);
                        //this->hash->agregarH(pkg0);
                        //cout<<"R[ "<<this->id<<"y lei"<<pkg0->getNumeroDePaquete()<<" "<<pkg0->getPaginaMadre()->getidentificadorDePag()<<endl;
                        cont--;
                    }         
                    cont --;
                }
            }
        }
    }
}

void Router::limpiarCache(){
    for (int i = 0; i<paquetes->size();i++){
        cout<<paquetes->buscarPorIndice(i)->getDestino()[0]<<endl;
    }
 
}


void Router::vincularConKey(Paquete* x){
    Paquete* p = new Paquete();
    p=x;

    if(p->getDestino()[0]!=this->id){
        cout<<"[R"<<this->id<<"] recibi el paquete "<<p->getNumeroDePaquete()<<"|"<<p->getPaginaMadre()->getidentificadorDePag()<<
        " pero el paquete paquete no es para mi, debo enrutarlo."<<endl;
        //p->setEstado1();
        paquetes->addFinal(p);
        
    }else{
        int i = p->getPaginaMadre()->getidentificadorDePag();
        cout<<"[R"<<this->id<<"] recibi el paquete "<<p->getNumeroDePaquete()<<"|"<<p->getPaginaMadre()->getidentificadorDePag()<<endl;
        D[i].addFinal(p);
        if(D[i].size()==10){
            cout<<"R["<<this->id<<"] se ha completado la pagina con destino al terminal "<<p->getTerm()<<"."<<endl;
            Pagina * n = new Pagina(p->getPaginaMadre()->getidentificadorDePag(),p->getPaginaMadre()->getTamanioDePag(),p->getPaginaMadre()->getOrigen(),p->getPaginaMadre()->getDestino());
            this->enviarPag(n);
        }

    }
    

}


bool Router::esVecino(int id){
    bool respuesta = false;
    Nodo<Router*>* aux;
    aux = listaDeVecinos->comienzo();
    for (int i =0 ; i < listaDeVecinos->size();i++){
        if(aux->get_dato()->getID()==id){
            respuesta= true;
            return respuesta;
        }
        aux = aux->get_next();

    }
    return respuesta;

}


void Router::setTabla(Lista<Direccion*>* nuevaTabla){
    this->tabla = nuevaTabla;

}

void Router::imprimirTabla(){
    Nodo<Direccion*>* aux;
    aux = tabla->comienzo();
    cout<<"Soy "<<this->id<<" y esta es mi tabla para los que no conozco: "<<endl;
    for (int i = 0 ; i < tabla->size();i++){
        cout<<"["<<aux->get_dato()->getDestino_D()<<"] enrutar a ->"<<aux->get_dato()->getCamino_D()<<endl;
        aux = aux->get_next();
    }
}

int Router::buscarEnTabla(int destinoDePkgABuscar){
    int r =9999;
    //cout<<tabla->size()<<endl;
    for (int i = 0 ; i< tabla->size() ; i++){
        if(tabla->buscarPorIndice(i)->getDestino_D() == destinoDePkgABuscar){   //tengo en la ruta
           // cout<<"paquete de "<<tabla->buscarPorIndice(i)->getDestino_D()<<" tiene que tomar la ruta de "<<tabla->buscarPorIndice(i)->getCamino_D()<<endl;
            r= tabla->buscarPorIndice(i)->getCamino_D();
           //r=i;
        }
    }
    return r;


}

void Router::enviarPag(Pagina * p){
   //cout<<p->getDestino()[1];
   for (int i = 0; i <terminalesConectados->size();i++){
   //  cout<<"***************"<<terminalesConectados->buscarPorIndice(i)->getIP()[1]<<" ";
        if(p->getDestino()[1]== terminalesConectados->buscarPorIndice(i)->getIP()[1]){
            terminalesConectados->buscarPorIndice(i)->recibirPagina(p);
        }
   }
  
}

int Router::buscarlazo(int y){

    for (int i = 0 ; i <ida->size();i++){
        if(ida->buscarPorIndice(i)->getTerminal2()==y){
            return i;
        }
    }
}