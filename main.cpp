#include <iostream>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <signal.h>
#include "Nodo.h"
#include "Lista.h"
#include "Router.h"
#include "Terminal.h"
#include "Pagina.h"
#include "Cola.h"
#include "Paquete.h"
#include "Administrador.h"

using namespace std;
int main (int argc, char **argv){
    

    ifstream archivo("banner.txt");
    string linea;
 
    while( getline(archivo,linea)){
        cout<<linea<<endl;
    }
    
    system("read -p 'Press Enter to continue...' var"); //***************************************



    signal(SIGINT,SIG_DFL);
    

    Administrador* admin = new Administrador();        
    admin->simularEscenarioPrincipal();
  
    

}