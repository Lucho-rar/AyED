#include "Administrador.h"

/*******                                    Metodos ADMINISTRADOR                           ********/


/*                                  Generador de routers                        */
/*               Crea la cantidad de routers que viene por parametrizacion del txt      */
void Administrador::generarRouters(int c){

    this->cantidadDeRouters = c;        // cantidad de routers a crear
    for (int i = 0; i < c ; i++){       // crea c routers 
        Router*r = new Router(i);
        //Router* r = new Router(rand()%10, 2);
        this->routersDisponibles->addFinal(r);//los agrega a la lista que visualiza el admin
    }
}

/*
void Administrador::imprimirListadoDeRouters(){

    cout<<"\nLos routers que tiene a cargo el administrador son: "<<endl;

    Nodo<Router*>* aux;
    aux = routersDisponibles->comienzo();
    
    for (int i =0; i<routersDisponibles->size();i++){
        cout<<"Id: "<<aux->get_dato()->getID()<<endl;
        aux= aux->get_next();
    }

}
*/

/*
void Administrador::imprimirListadosDeTerminales(){
    Nodo<Router*>* aux;
    aux = routersDisponibles->comienzo();
    for (int i =0; i < routersDisponibles->size();i++){
        aux->get_dato()->imprimirTerminales();
        aux = aux->get_next();
    }

}*/
/*
void Administrador::establecerConexiones(){
    Nodo<Router*>* auxRout;
    auxRout = routersDisponibles->comienzo();
    for (int i = 0; i< routersDisponibles->size();i++){
        for (int j = 0; j< terminalesDisponibles->size();j++){
            routersDisponibles->buscarPorIndice(i)->agregarTerminal(terminalesDisponibles->buscarPorIndice(j));
        }
    }
}*/


/*                                   Conector de terminales a routers           */
/*                          La cantidad de routers viene dado por el txt tambien        */
void Administrador::conectarTerminales(int txr){
    this->terminalesPorRouter = txr;            
    Nodo<Router*>* aux;
    aux = routersDisponibles->comienzo();
    for (int i =0;i<routersDisponibles->size();i++){            // por cada router 
        for (int j =0;j<txr;j++){                   
            int v[2]={i,j};                             // crea txr terminales y los agrega al router
            Terminal* t = new Terminal(v);
            aux->get_dato()->agregarTerminal(t);
        }

        aux = aux->get_next();

    }
}


/*                          Crea los lazos de conexion de un determinado BW entre dos nodos     */
/*                         Inserta el lazo de ida y vuelta en su respectivo nodo                    */

void Administrador::establecerLazo(int o , int d, int a){
    LazoDeConexion* lazo = new LazoDeConexion(o, d ,a );
    //cout<<"\n ida "<<ida->getTerminal1()<<" a "<< ida->getTerminal2()<<endl;
    //cout<<"vuelta "<<vuelta->getTerminal1()<<" a "<<vuelta->getTerminal2()<<endl;
    cout<<"\033[1;36mLazo directo establecido entre " <<routersDisponibles->buscarPorIndice(o)->getID()<<" y "<<
    routersDisponibles->buscarPorIndice(d)->getID()<<"\033[0m\n"<<endl;
    
    routersDisponibles->buscarPorIndice(o)->agregarLazoIda(lazo);
    routersDisponibles->buscarPorIndice(d)->agregarLazoVuelta(lazo);
    listaDeConexiones->addFinal(lazo);
    

    examinarRouterPorID(o,d);
}

/*                  Agregar a la lista de vecinos de cada router por origen y destino        */
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


}


/*
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
}*/



/*                                      Parametrizacion de la configuracion             */
void Administrador::leerFile(){
    int cantidadRouters, terminalesPorRouter;
    //system("cls");
    ifstream f;
    f.open("config1.txt",ios::in);
    string linea;
    //getline(f,linea); // obtiene routers 
    f>>cantidadRouters;
    f>>terminalesPorRouter; //obtiene terminal x router
    generarRouters(cantidadRouters);                //llama al generador de routers
    conectarTerminales(terminalesPorRouter);        //conecta txr por cada router
    int origen, destino, ancho;
    f>>origen;
    while (!f.eof()) {
        f>>destino;
        f>>ancho;
        establecerLazo(origen, destino, ancho);
        f>>origen;

    }
    f.close();

}

/*                          Creador de paginas randoms              */
void Administrador::crearPaginas(){
   
    Nodo<Router*>* aux;
    aux = routersDisponibles->comienzo();
    int NumeroRandomOR = rand() % cantidadDeRouters;        //origen de router random
    int NumeroRandomOT = rand() % terminalesPorRouter;          // origen de terminal random
   // cout<<"origen "<<NumeroRandomOR<<" "<<NumeroRandomOT<<endl;
    int ipOrigen[2]={NumeroRandomOR,NumeroRandomOT};            //ip de origen generada
    int NumeroRandomDR = rand() % cantidadDeRouters;            //destino router random
    int NumeroRandomDT = rand() % terminalesPorRouter;          //destino terminal random
  //  cout<<"destino "<<NumeroRandomDR<<" "<<NumeroRandomDT<<endl;
    int ipDestino[2]={NumeroRandomDR,NumeroRandomDT};               //ip de destino random
    int randomPag;
    randomPag = rand() % TAMPAG;                    //tamanio de pag random
   // ipDestino[0]=NumeroRandomDR;
   // ipDestino[1]=0;
  //  cout<<"destino "<<ipDestino[0]<<" "<<ipDestino[1]<<endl;
        //int origen = aux->get_dato()->getID();
    Pagina* p = new Pagina(simPag,randomPag, ipOrigen, ipDestino);
    simPag++;
    //routersDisponibles->buscarPorIndice(ipOrigen[0])->recibirPag(p);
    cout << "\033[1;31mCREE LA PAGINA "<<p->getidentificadorDePag()<<"\033[0m\n";
    //cout<<routersDisponibles->buscarPorIndice(NumeroRandomOR)->getID()<<endl;
    routersDisponibles->buscarPorIndice(NumeroRandomOR)->recibirPag(p);     // coloco las paginas en los routers que corresponde
    
}


/*                   Creador de paginas manual              */
void Administrador::crearPagManual(int a, int b){
   
    Nodo<Router*>* aux;
    aux = routersDisponibles->comienzo();
    int NumeroRandomOR = a;
    int NumeroRandomOT = a;
    int ipOrigen[2]={NumeroRandomOR,NumeroRandomOT};
    int NumeroRandomDR =b;
    int NumeroRandomDT =b;
    int ipDestino[2]={NumeroRandomDR,NumeroRandomDT};
    int randomPag;
    randomPag = rand() % TAMPAG;
    Pagina* p = new Pagina(simPag,5, ipOrigen, ipDestino);
    simPag++;
    cout << "\033[1;31mCREE LA PAGINA "<<p->getidentificadorDePag()<<"\033[0m\n";
    routersDisponibles->buscarPorIndice(NumeroRandomOR)->recibirPag(p);
    
}

/*                  Impresora de paquetes           */
void Administrador::paquetes(){
    Nodo<Router*>* aux;
    aux = routersDisponibles->comienzo();
    for (int i = 0 ; i<routersDisponibles->size();i++){
        aux->get_dato()->imprimirPaquetes();
        aux = aux->get_next();
    }
}


/*              Llamado a enviar paquetes para cada router       */
void Administrador::enviarPaquetes(){
    Nodo<Router*>* aux;
    aux = routersDisponibles -> comienzo();
    for (int i = 0 ; i < routersDisponibles->size();i++){
        aux->get_dato()->enviarPaquetes();
        aux = aux -> get_next();
    }   
}

/*             Llamado a recibir paquetes para cada router          */
void Administrador::recibirPaquetes(){
    Nodo<Router*>* aux;
    aux = routersDisponibles -> comienzo();
    for (int i = 0 ; i < routersDisponibles->size();i++){
        aux->get_dato()->recibirPaquetes();
        aux = aux -> get_next();
    }   
}


/*              Pase de algoritmo de dijsktra       (pasos previos)*/
void Administrador::paseAlg(){
    int *pdist, i, j, P[MAXNODOS],s,t;
    
    for (int i = 0 ; i < routersDisponibles->size();i++){
        this->AlgAlt(i);
    }

    this->imprimirtabla();
   
    
   // s vertice de inicio
   // t vertice final
    for(s = 0; s<MAXNODOS;s++){
         Lista<Direccion*>* etiquetas = new Lista<Direccion*>(); // lista de etiquetas para cada router
        for ( t = 0; t<MAXNODOS;t++){
    
        pdist=dijkstra(T,s,t,P);            //llamado al algoritmo
        if (pdist[t]!=INFI){
        //cout<<"\n\n distancia minima del nodo "<<s
          //  <<" al nodo "<<t<<" es= "<<pdist[t];
   
       // cout<<"\n\n CAMINO= ";
        glb = t;                //flag de destino 
        
        camino(P,s,t,etiquetas);            //camino para encontrar el nodo al quedebe dirigir cierto paquete


       
    }                
    else cout<</*"\n NO HAY CAMINO"*/"";        ///***************
    
   // cout<<endl<<endl<<endl;
    //system("PAUSE");
    }
    routersDisponibles->buscarPorIndice(s)->setTabla(etiquetas);        //setea la tabla del router

    }

}

/*                 Previo a dijkstra. Crea la tabla de pesos */

void Administrador::AlgAlt(int ini){

    int C[cantidadDeRouters];
    

    int aux = 4;
    for (int i = 0 ; i <listaDeConexiones->size();i++){
        listaDeConexiones->buscarPorIndice(i)->calcularPeso();      //calcula los pesos para cada lazo
    }
    
    for (int i = 0; i < routersDisponibles->size();i++){
        
        Router* routerAnalisis= routersDisponibles->buscarPorIndice(i);
        if(i == ini){
            C[ini]=0;               // El peso al mismo router es cero
        }else if(routersDisponibles->buscarPorIndice(ini)->esVecino(i)){            //analisis de peso para vecinos
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
            C[i]=INFI;          // no es vecino
        }
    }
    for (int i = 0 ; i < cantidadDeRouters;i++){            //creo la tabla con cada vector
        this->T[ini][i]=C[i];
    }
    /*
    for (int i =0; i<cantidadDeRouters;i++){
        cout<<C[i]<<" ";
           
    }*/

 
   // cout<<endl;
}

/*                              Impresora de tabla              */
void Administrador::imprimirtabla(){
    cout << "\033[1;33mTABLA DE ENRUTAMIENTO CON PESOS\033[0m\n";
    for (int i = 0; i < cantidadDeRouters;i++){
        for (int j = 0 ; j < cantidadDeRouters;j++){
            cout<<T[i][j]<<" ";
        }
        cout<<endl;
    }
}


/*                      Algoritmo de dijkstra               */
// C[i][j] Costo del arco de i a j
// D[i] costo del camino m�nimo conocido hasta el 
//              momento de s a i
//              inicialmente D[s]=0 y D[i]=INFI
// S[i] conjunto de nodos cuya distancia minima a s es conocida
//         y permanente, inicialmente S[] solo contiene a s
//         S[i]=1 si i pertenece, 0 si i no pertenece
// Pre[i] contiene el vertice que precede a i en el camino 
//            minimo encontrado hasta el momento
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

/*                  Puede imprimir el camino pero su funcion principal es obtener el primer nodo al que debe dirigirse */
void Administrador::camino(int P[], int s, int t , Lista<Direccion*>* etiquetas)
{  
   if (t==s){
        cout<< /*s*/" ";

   } 
   else{
        if(P[t]==s){
           Direccion* d = new Direccion(glb,t);
           etiquetas->addFinal(d);
        }else{
            camino(P,s,P[t],etiquetas);
        }
   }
}

/*
void Administrador::mostrarTablas(){
    Nodo<Router*>* aux;
    aux = routersDisponibles->comienzo();
    for (int i = 0 ; i < routersDisponibles->size();i++){
        aux->get_dato()->imprimirTabla();
        aux = aux->get_next();
    }
}*/

/*                                      Simuladores             */
void Administrador::simularEscenarioPrincipal(){
    //signal(SIGINT, SIG_DFL);

    this->leerFile();                   //lectura de parametrizacion
    
    int x =0;
    int prb;
    while(prb!=0){

        cantSimulaciones++;
        this->paseAlg();                        //algoritmo de dijsktra
        system("read -p 'Press Enter to continue...' var");
        cout<<endl<<endl;
        cout << "\033[1;31mCREACION DE PAGINAS\033[0m\n"<<endl;
        if(x==0){
           // this->crearPagManual(2,2);
            
            this->crearPaginas();
            this->crearPaginas();
            this->crearPaginas();               // creacion de paginas
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


        this->paquetes();                       //muestra de paquetes 
        //this->imprimirLazos();
        cout<<endl<<endl;
       // this->imprimirLazos();
        cout << "\033[1;32mENVÍO DE PAQUETES\033[0m\n"<<endl;               //envio
        this->enviarPaquetes();
        cout << "\033[1;42mRECIBO DE PAQUETES\033[0m\n"<<endl;              //recibo
        this->recibirPaquetes();
       // this->mostrarTablas();
        cout<<"\nMenu de opciones: "<<endl;
        cout<<"0: Detener simulacion."<<endl;
        cout<<"1: Continuar simulacion. "<<endl;
        cout<<"2: Crear paginas nuevas y continuar. "<<endl;
        cin>>prb;

    }  

}

void Administrador::simularSegundoEscenario(){
    //signal(SIGINT, SIG_DFL);
    this->leerFile();
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
           this->crearPagManual(0,7);
           this->crearPagManual(1,7);
           this->crearPagManual(1,7);
            
            
            
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



