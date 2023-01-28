#include "Terminal.h"

/*          Metodos Terminal    */

Terminal::Terminal(int d[2]){
    ip[0] = d[0];
    ip[1] = d[1];
}

void Terminal::conectarseAUnRouter(Router* conexion){
    //cout<<"Lo reconoci desde la PC"<<endl;
}

int* Terminal::getIP(){
    return ip;
}

void Terminal::enviarPagina(){

}

void Terminal::recibirPagina(){
    
}