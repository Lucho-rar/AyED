#include "Administrador.h"

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
    cout<<"\033[1;36mLazo directo establecido entre " <<routersDisponibles->buscarPorIndice(o)->getID()<<" y "<<
    routersDisponibles->buscarPorIndice(d)->getID()<<"\033[0m\n"<<endl;
    
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
    f.open("config1.txt",ios::in);
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
   // cout<<"origen "<<NumeroRandomOR<<" "<<NumeroRandomOT<<endl;
    int ipOrigen[2]={NumeroRandomOR,NumeroRandomOT};
    int NumeroRandomDR = rand() % cantidadDeRouters;
    int NumeroRandomDT = rand() % terminalesPorRouter;
  //  cout<<"destino "<<NumeroRandomDR<<" "<<NumeroRandomDT<<endl;
    int ipDestino[2]={NumeroRandomDR,NumeroRandomDT};
    int randomPag;
    randomPag = rand() % TAMPAG;
   // ipDestino[0]=NumeroRandomDR;
   // ipDestino[1]=0;
  //  cout<<"destino "<<ipDestino[0]<<" "<<ipDestino[1]<<endl;
        //int origen = aux->get_dato()->getID();
    Pagina* p = new Pagina(simPag,randomPag, ipOrigen, ipDestino);
    simPag++;
    //routersDisponibles->buscarPorIndice(ipOrigen[0])->recibirPag(p);
    cout << "\033[1;31mCREE LA PAGINA "<<p->getidentificadorDePag()<<"\033[0m\n";
    //cout<<routersDisponibles->buscarPorIndice(NumeroRandomOR)->getID()<<endl;
    routersDisponibles->buscarPorIndice(NumeroRandomOR)->recibirPag(p);
    
}

void Administrador::crearPagManual(int a, int b){
   
    Nodo<Router*>* aux;
    aux = routersDisponibles->comienzo();
    int NumeroRandomOR = a;
    int NumeroRandomOT = a;
   // cout<<"origen "<<NumeroRandomOR<<" "<<NumeroRandomOT<<endl;
    int ipOrigen[2]={NumeroRandomOR,NumeroRandomOT};
    int NumeroRandomDR =b;
    int NumeroRandomDT =b;
  //  cout<<"destino "<<NumeroRandomDR<<" "<<NumeroRandomDT<<endl;
    int ipDestino[2]={NumeroRandomDR,NumeroRandomDT};
    int randomPag;
    randomPag = rand() % TAMPAG;
   // ipDestino[0]=NumeroRandomDR;
   // ipDestino[1]=0;
  //  cout<<"destino "<<ipDestino[0]<<" "<<ipDestino[1]<<endl;
        //int origen = aux->get_dato()->getID();
    Pagina* p = new Pagina(simPag,randomPag, ipOrigen, ipDestino);
    simPag++;
    //routersDisponibles->buscarPorIndice(ipOrigen[0])->recibirPag(p);
    cout << "\033[1;31mCREE LA PAGINA "<<p->getidentificadorDePag()<<"\033[0m\n";
    //cout<<routersDisponibles->buscarPorIndice(NumeroRandomOR)->getID()<<endl;
    routersDisponibles->buscarPorIndice(NumeroRandomOR)->recibirPag(p);
    
}


void Administrador::paquetes(){
    Nodo<Router*>* aux;
    aux = routersDisponibles->comienzo();
    for (int i = 0 ; i<routersDisponibles->size();i++){
        aux->get_dato()->imprimirPaquetes();
        aux = aux->get_next();
    }
}
/*
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
}*/
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


        /* voy a declarar dijsktra en base a lo de clase para abrir ideas y en base
        a ello redefinir metodos que tengo */


void Administrador::paseAlg(){
    int *pdist, i, j, P[MAXNODOS],s,t;
    
    for (int i = 0 ; i < routersDisponibles->size();i++){
        this->AlgAlt(i);
    }

    this->imprimirtabla();
   
    
   // s=0;  // vertice de inicio
   // t=1;  // vertice final
    for(s = 0; s<MAXNODOS;s++){
         Lista<Direccion*>* etiquetas = new Lista<Direccion*>();
        for ( t = 0; t<MAXNODOS;t++){
    
    pdist=dijkstra(T,s,t,P);
    if (pdist[t]!=INFI){
        //cout<<"\n\n distancia minima del nodo "<<s
          //  <<" al nodo "<<t<<" es= "<<pdist[t];
   
       // cout<<"\n\n CAMINO= ";
        glb = t;
        
        camino(P,s,t,etiquetas);

       // cout<<"\n rr "<<glb<<endl;
       // cout<<glb<<endl;
      //  this->flek();
       
    }                
    else cout<</*"\n NO HAY CAMINO"*/"";        ///***************
    
   // cout<<endl<<endl<<endl;
    //system("PAUSE");
    }
    routersDisponibles->buscarPorIndice(s)->setTabla(etiquetas);
 //   delete etiquetas;
    }

}


void Administrador::AlgAlt(int ini){
    Lista<int> Q;
    int C[cantidadDeRouters];
    
    
    int aux = 4;
    for (int i = 0 ; i <listaDeConexiones->size();i++){
        ///cout<<listaDeConexiones->buscarPorIndice(i)->getTerminal1()<<"|"<<listaDeConexiones->buscarPorIndice(i)->getTerminal2()<<"|";
        ///cout<<listaDeConexiones->buscarPorIndice(i)->getcolaconectora()->size()<<endl;
        listaDeConexiones->buscarPorIndice(i)->calcularPeso();
    }
    
    for (int i = 0; i < routersDisponibles->size();i++){
        
        Router* routerAnalisis= routersDisponibles->buscarPorIndice(i);
        if(i == ini){
            C[ini]=0;
        }else if(routersDisponibles->buscarPorIndice(ini)->esVecino(i)){
           // cout<<"lo contiene"<<endl;
            
            for(int j = 0 ; j < listaDeConexiones->size(); j ++){
                if((listaDeConexiones->buscarPorIndice(j)->getTerminal1()==ini && listaDeConexiones->buscarPorIndice(j)->getTerminal2()==i)){
               //     cout<<ini<<" "<<i<<endl;
                    aux = listaDeConexiones->buscarPorIndice(j)->getPeso();
                }else if(listaDeConexiones->buscarPorIndice(j)->getTerminal1()==i && listaDeConexiones->buscarPorIndice(j)->getTerminal2()==ini){
                    aux = INFI;
                }
            }
            C[i]=aux;
        }else{
            C[i]=INFI;
        }
    }
    for (int i = 0 ; i < cantidadDeRouters;i++){
        this->T[ini][i]=C[i];
    }
    /*
    for (int i =0; i<cantidadDeRouters;i++){
        cout<<C[i]<<" ";
           
    }*/

 
   // cout<<endl;
}
void Administrador::imprimirtabla(){
    cout << "\033[1;33mTABLA DE ENRUTAMIENTO CON PESOS\033[0m\n";
    for (int i = 0; i < cantidadDeRouters;i++){
        for (int j = 0 ; j < cantidadDeRouters;j++){
            cout<<T[i][j]<<" ";
        }
        cout<<endl;
    }
}

int * Administrador::dijkstra(int C[][MAXNODOS],int s, int t, int Pre[]){
 static int D[MAXNODOS];
 int S[MAXNODOS];
 int actual, i, k, b;
 int menordist, nuevadist;
// inicializaci�n
 for(i=0;i<MAXNODOS;i++){
                         S[i]=NO_MIEMBRO;
                         D[i]=INFI;
                         Pre[i]= -1;
 }//fin for
 S[s]=MIEMBRO; D[s]=0; actual=s; b=1; k=0;
 while((actual!=t)&&(b==1)){
                  b=0;
                  menordist=INFI;
                  //printf("\n\n   D[%i]=%3i ",actual,D[actual]);
                  for(i=0;i<MAXNODOS;i++){
                          //cout<<"\n  i= "<<i;                
                          if(S[i]==NO_MIEMBRO){
                                 nuevadist=D[actual]+C[actual][i];
                                 //printf("\n nuevadist=%3i D[%2i]=%3i ",nuevadist,i,D[i]);
                                 if(nuevadist<D[i]){
                                        D[i]=nuevadist;//actual es menor que la anterior
                                        //cout<<actual<<"22222"<<endl;
                                        Pre[i]=actual; b=1;
                                 }//fin if
                                 //printf("\n menordist=%3i D[%2i]=%3i ",menordist,i,D[i]);
                                 if(D[i]<menordist){
                                        menordist=D[i];
                                        k=i;  b=1;//guardo el nodo de la menor distancia
                                 }//fin if
                          }//fin if
                  }//fin for

                  actual=k; // actual se ubica en el nodo de menor distancia
                  S[actual]=MIEMBRO;
                //  printf("\n\n         D     S     Pre");
                //  for(i=0;i<MAXNODOS;i++){           
                //    printf("\n[%2i] %5i %5i %5i     ",i,D[i], S[i],Pre[i]);
                //   } 
      
                //  printf("\n\n   D[%i]=%3i ",actual,D[actual]);
                  
                  
                   //system("PAUSE");
 }//fin while

return D;

}


void Administrador::camino(int P[], int s, int t , Lista<Direccion*>* etiquetas)
{  

   if (t==s){
        cout<< /*s*/" ";

   } 
   else{
        
        //camino(P,s,P[t],etiquetas);
        //camino(P,s,P[t],etiquetas);
        if(P[t]==s){
            //this->flek(x);
            //cout<<t<<endl;
           // flek(t,glb);
           Direccion* d = new Direccion(glb,t);
           etiquetas->addFinal(d);
          //  cout<<glb<<"xxxxxxxxxx"<<endl;
        }else{
            camino(P,s,P[t],etiquetas);
            //camino(P,s,P[t],etiquetas);
           // x=P[t];
           // D[t]=P[t];
            //p->addFinal(P[t]);
           // cout<<"etiqueta"<<t<<P[t]<<endl;

          //  cout<<P[t]<<"  ";

        }

    
         
   }
}

void Administrador::flek(int x, int y){

}
   

  // Nodo<Direccion*>* aux;
  
    //aux=etiquetas->comienzo();
    //for (int i =0;i<etiquetas->size();i++){
    //cout << aux->get_dato()->getDestino_D()<<"'"<<aux->get_dato()->getCamino_D()<<endl;
   // aux = aux->get_next();
  // }
     


void Administrador::mostrarTablas(){
    Nodo<Router*>* aux;
    aux = routersDisponibles->comienzo();
    for (int i = 0 ; i < routersDisponibles->size();i++){
        aux->get_dato()->imprimirTabla();
        aux = aux->get_next();
    }
}

void Administrador::handlerC(int s){
  //printf("-------- Recibi la senial  --> ###### %d ###### \n",s);
    signal(SIGINT,SIG_DFL);
}
/*
void Administrador::cleaner(){
    Nodo<Router*>* aux;
    aux = routersDisponibles->comienzo();
    for (int i = 0 ; i < routersDisponibles->size();i++){
        aux->get_dato()->limpiarCache();
        aux = aux->get_next();
    }
}*/


void Administrador::simularEscenarioPrincipal(){
    //signal(SIGINT, SIG_DFL);
    this->leerFile();
    cout<<"---------------Simulacion numero "<<cantSimulaciones<<endl;
    int x =0;
    int prb;
    while(prb!=0){
        

        
        cantSimulaciones++;
        this->paseAlg();
        system("read -p 'Press Enter to continue...' var");
        cout<<endl<<endl;
        cout << "\033[1;31mCREACION DE PAGINAS\033[0m\n"<<endl;
        if(x==0){
           // this->crearPagManual(2,2);
            
            this->crearPaginas();
            this->crearPaginas();
            this->crearPaginas();
            this->crearPaginas();
            this->crearPaginas();
            this->crearPaginas();
            this->crearPaginas();
            this->crearPaginas();
            this->crearPaginas();
            this->crearPaginas();
            this->crearPaginas();
            this->crearPaginas();
            this->crearPaginas();
            this->crearPaginas();
            this->crearPaginas();
            this->crearPaginas();
            this->crearPaginas();
            this->crearPaginas();
            this->crearPaginas();
            this->crearPaginas();
            
            x =1;
        }

      //  this->crearPagManual();
     //   this->crearPaginas();
      //  this->crearPaginas();
     //   this->crearPaginas();
        this->paquetes();
        //this->imprimirLazos();
        cout<<endl<<endl;
       // this->imprimirLazos();
        cout << "\033[1;32mENVÍO DE PAQUETES\033[0m\n"<<endl;
        this->enviarPaquetes();
       // this->cleaner();
        cout << "\033[1;42mRECIBO DE PAQUETES\033[0m\n"<<endl;
        this->recibirPaquetes();
       // this->mostrarTablas();
        cout<<"\nMenu de opciones: "<<endl;
        cout<<"0: Detener simulacion."<<endl;
        cout<<"1: Continuar simulacion. "<<endl;
        cout<<"2: Crear paginas nuevas y continuar. "<<endl;
      //  this->paquetes();
    
        cin>>prb;

    }  

}

void Administrador::simularSegundoEscenario(){
    //signal(SIGINT, SIG_DFL);
    this->leerFile();
    cout<<"---------------Simulacion numero "<<cantSimulaciones<<endl;
    int x =0;
    int prb;
    while(prb!=0){
        

        
        cantSimulaciones++;
        this->paseAlg();
        system("read -p 'Press Enter to continue...' var");
        cout<<endl<<endl;
        cout << "\033[1;31mCREACION DE PAGINAS\033[0m\n"<<endl;
        if(x==0){
           // this->crearPagManual(2,2);
            
            this->crearPagManual(1,7);
            this->crearPagManual(1,7);
            this->crearPagManual(1,7);
            this->crearPagManual(1,7);
            this->crearPagManual(11,7);
            this->crearPagManual(11,7);
            this->crearPagManual(11,7);
            this->crearPagManual(11,7);
            this->crearPagManual(11,7);
            this->crearPagManual(11,7);

            
            x =1;
        }

      //  this->crearPagManual();
     //   this->crearPaginas();
      //  this->crearPaginas();
     //   this->crearPaginas();
        this->paquetes();
        //this->imprimirLazos();
        cout<<endl<<endl;
       // this->imprimirLazos();
        cout << "\033[1;32mENVÍO DE PAQUETES\033[0m\n"<<endl;
        this->enviarPaquetes();
       // this->cleaner();
        cout << "\033[1;42mRECIBO DE PAQUETES\033[0m\n"<<endl;
        this->recibirPaquetes();
       // this->mostrarTablas();
        cout<<"\nMenu de opciones: "<<endl;
        cout<<"0: Detener simulacion."<<endl;
        cout<<"1: Continuar simulacion. "<<endl;
        cout<<"2: Crear paginas nuevas y continuar. "<<endl;
      //  this->paquetes();
    
        cin>>prb;

    }  

}

void Administrador::simularTercerEscenario(){
    //signal(SIGINT, SIG_DFL);
    this->leerFile();
    cout<<"---------------Simulacion numero "<<cantSimulaciones<<endl;
    int x =0;
    int prb;
    while(prb!=0){
        

        
        cantSimulaciones++;
        this->paseAlg();
        system("read -p 'Press Enter to continue...' var");
        cout<<endl<<endl;
        cout << "\033[1;31mCREACION DE PAGINAS\033[0m\n"<<endl;
        if(x==0){
           // this->crearPagManual(2,2);
            
            this->crearPaginas();
            this->crearPaginas();
            this->crearPaginas();
            this->crearPaginas();
            this->crearPaginas();
            this->crearPaginas();
            this->crearPaginas();
            this->crearPaginas();
            this->crearPaginas();
            this->crearPaginas();
            this->crearPaginas();
            this->crearPaginas();
            this->crearPaginas();
            this->crearPaginas();
            this->crearPaginas();
            this->crearPaginas();
            this->crearPaginas();
            this->crearPaginas();
            this->crearPaginas();
            this->crearPaginas();
            
            x =1;
        }

      //  this->crearPagManual();
     //   this->crearPaginas();
      //  this->crearPaginas();
     //   this->crearPaginas();
        this->paquetes();
        //this->imprimirLazos();
        cout<<endl<<endl;
       // this->imprimirLazos();
        cout << "\033[1;32mENVÍO DE PAQUETES\033[0m\n"<<endl;
        this->enviarPaquetes();
       // this->cleaner();
        cout << "\033[1;42mRECIBO DE PAQUETES\033[0m\n"<<endl;
        this->recibirPaquetes();
       // this->mostrarTablas();
        cout<<"\nMenu de opciones: "<<endl;
        cout<<"0: Detener simulacion."<<endl;
        cout<<"1: Continuar simulacion. "<<endl;
        cout<<"2: Crear paginas nuevas y continuar. "<<endl;
      //  this->paquetes();
    
        cin>>prb;

    }  

}



