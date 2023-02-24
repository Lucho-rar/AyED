#include "Router.h"
/*          Metodos Router      */



/*                     Recibir pagina y parsear paquetes           */
void Router::recibirPag(Pagina* p){


    for (int i = 0 ; i < p->getTamanioDePag();i++){
        Paquete* pkg = new Paquete (i,p,p->getOrigen(),p->getDestino(), p->getTamanioDePag());
        this->paquetes->addFinal(pkg);
    }
}


/*                           Conexion de terminal                       */
void Router::agregarTerminal(Terminal* t){
   // cout<<"Reconocido desde el router"<<endl;
    t->conectarseAUnRouter(this);
    terminalesConectados->addFinal(t);
}

/*                          Agregado a la lista de vecinos              */
void Router::agregarVecino(int id) {
    Router* r = new Router(id);
    //cout<<"Tengo un vecino nuevo y es el router de id "<<id<<endl;
    listaDeVecinos->addFinal(r);
}

/*
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
    
}*/


/*                      Impresion de paquetes               */
void Router::imprimirPaquetes(){

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

}
/*
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

}*/

/*              Comprobacion de si existe un lazo de ida a cierto destino       */
int Router::comprobarDestino(int dir){
    
    for (int i = 0 ; i < ida ->size() ; i ++){
        //cout<<f;
        if ( ida->buscarPorIndice(i)->getTerminal2() == dir){
           return i;
        }
    }

    return 9999;

}


/*                          Envio de paquetes                           */
void Router::enviarPaquetes(){
    bool bw=0;
    bool aux=1;
    bool entro =false;
    int x ;
    int flag;
    if (!paquetes->esvacia()){
        for(int i = 0 ; i <4; i ++){            //paso de paquetes
            if (paquetes->size()==0){
                break;
            }

           x =comprobarDestino(paquetes->buscarPorIndice(0)->getDestino()[0]);  //buscar el lazo de ida si es que existe
           
          

          if (x!=9999){         //es directo
                
                
                flag = i;
                i=0;
                
                int l = paquetes->buscarPorIndice(i)->getNumeroDePaquete(); 
                int indice = buscarlazo(l);
                cout<<"[R"<<this->id<<"] Envio directo a R"<<paquetes->buscarPorIndice(i)->getDestino()[0]<<" porque es vecino. "<< /* paquetes->buscarPorIndice(i)->getDestino()[0]<<x<*/endl;
                ida->buscarPorIndice(x)->cargarPkg(paquetes->buscarPorIndice(i));   //cargo el paquete a la cola
                cout<<"voy a borrar "<<paquetes->buscarPorIndice(i)->getNumeroDePaquete()<<endl;
                paquetes->borrarNodo(i);        //elimino el paquete del router

                i= flag;
                entro = false;


            }else if(x==9999){          //se enruta o no existe camino

                flag = i;
                i=0;
                if(buscarEnTabla(paquetes->buscarPorIndice(i)->getDestino()[0])==9999){
                    cout<<"[R"<<this->id<<"] No hay ruta para este paquete. "<<endl;
                    paquetes->borrarNodo(i);
                    i = flag;
                }else{
                    int y = buscarEnTabla(paquetes->buscarPorIndice(i)->getDestino()[0]);
                    int l = paquetes->buscarPorIndice(i)->getNumeroDePaquete();
                    int indice = buscarlazo(y);

                    cout<<"[R"<<this->id<<"] No tengo camino directo a R"<<paquetes->buscarPorIndice(i)->getDestino()[0]<<" pero lo puedo enrutaren  "<<endl;
                    cout<<ida->buscarPorIndice(indice)->getTerminal1()<<"->"<<ida->buscarPorIndice(indice)->getTerminal2()<<endl;
                    ida->buscarPorIndice(indice)->cargarPkg(paquetes->buscarPorIndice(i));

                    paquetes->borrarNodo(i);

                    i = flag;
                    entro = false;
                }         
            }
            
        }
/*
        Nodo<Paquete*>* aux;
        if(paquetes->comienzo()!=NULL){
            aux = paquetes->comienzo();
        }
        //int tope = paquetes->size(); 
        //int tope =2;
       // for (int i = 0 ; i < tope;i++){
         //   if (aux->get_dato()->getEstado()==true) paquetes->borrarUltimo();
        //}*/
    }else{
       cout<<"[R"<<this->id<<"] No hay paquetes para este router. "<<endl;

        
    }

}






/*                               Recibo de paquetes                     */
void Router::recibirPaquetes(){
    if (!vuelta->esvacia()){
       // cout<<this->id<<" puedo recibir"<<endl;
        for (int i =0 ; i < vuelta->size();i++){
            if(vuelta->buscarPorIndice(i)->vacia()==true){
              //  cout<<"Vacia"<< this->id<<endl;
            }else{
                
                int cont =vuelta->buscarPorIndice(i)->getBW();      //flag de BW
                //cout<<"cont"<<cont<<endl;
                while(cont>0/*vuelta->buscarPorIndice(i)->vacia()!=true*/){
                    Paquete* pkg0 = vuelta->buscarPorIndice(i)->leerPkg();
                    
                    if (pkg0!=NULL){
                        this->vincularConKey(pkg0);     //decision de que hacer con el paquete
                        //cont--;
                    }         
                    cont --;
                }
            }
        }
    }
}


/*                      Decision de destino de paquete */
void Router::vincularConKey(Paquete* x){
    Paquete* p = new Paquete();
    p=x;
    

    if(p->getDestino()[0]!=this->id){       // si el router no es para el lo reencola en su router 
        cout<<"[R"<<this->id<<"] recibi el paquete "<<p->getNumeroDePaquete()<<"|"<<p->getPaginaMadre()->getidentificadorDePag()<<
        " pero el paquete paquete no es para mi, debo enrutarlo."<<endl;
        //p->setEstado1();
        paquetes->addFinal(p);
        
    }else{      // si es para el usa una estructura HASH para almacenar los paqueteshasta completar la pagina
        int i = p->getPaginaMadre()->getidentificadorDePag();
        cout<<"[R"<<this->id<<"] recibi el paquete "<<p->getNumeroDePaquete()<<"|"<<p->getPaginaMadre()->getidentificadorDePag()<<endl;
        D[i].addFinal(p);
        if(D[i].size()==p->getPaginaMadre()->getTamanioDePag()){        //si la pagina se completo se la envia al terminal 
            cout<<"R["<<this->id<<"] se ha completado la pagina con destino al terminal "<<p->getTerm()<<"."<<endl;
            Pagina * n = new Pagina(p->getPaginaMadre()->getidentificadorDePag(),p->getPaginaMadre()->getTamanioDePag(),p->getPaginaMadre()->getOrigen(),p->getPaginaMadre()->getDestino());
            this->enviarPag(n);
        }

    }
    

}


/*                              Bool de vecino              */

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

/*                          Setter de la tabla de enrutamiento          */
void Router::setTabla(Lista<Direccion*>* nuevaTabla){
    this->tabla = nuevaTabla;

}
/*
void Router::imprimirTabla(){
    Nodo<Direccion*>* aux;
    aux = tabla->comienzo();
    cout<<"Soy "<<this->id<<" y esta es mi tabla para los que no conozco: "<<endl;
    for (int i = 0 ; i < tabla->size();i++){
        cout<<"["<<aux->get_dato()->getDestino_D()<<"] enrutar a ->"<<aux->get_dato()->getCamino_D()<<endl;
        aux = aux->get_next();
    }
}*/

/*                      Comrpueba el destino en la tabla de enrutamiento        */
int Router::buscarEnTabla(int destinoDePkgABuscar){
    int r =9999;

    for (int i = 0 ; i< tabla->size() ; i++){
     
        if(tabla->buscarPorIndice(i)->getDestino_D() == destinoDePkgABuscar){   //tengo en la ruta
          
            r= tabla->buscarPorIndice(i)->getCamino_D();

        }
    }
    return r;


}

/*                              Enviar pagina a terminal correcto           */
void Router::enviarPag(Pagina * p){
  
   for (int i = 0; i <terminalesConectados->size();i++){

        if(p->getDestino()[1]== terminalesConectados->buscarPorIndice(i)->getIP()[1]){
            terminalesConectados->buscarPorIndice(i)->recibirPagina(p);
        }
   }
  
}

/*                                     Busqueda de lazo de ida                    */
int Router::buscarlazo(int y){

    for (int i = 0 ; i <ida->size();i++){
        if(ida->buscarPorIndice(i)->getTerminal2()==y){
            return i;
        }
    }
    return 9999;
}