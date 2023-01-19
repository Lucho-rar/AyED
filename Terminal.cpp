#include "Terminal.h"

/*          Metodos Terminal    */

Terminal::Terminal(int direccion){
    this->ip = direccion;
}

void Terminal::conectarseAUnRouter(Router* conexion){
    cout<<"Lo reconoci desde la PC"<<endl;
}

int Terminal::getIP(){
    return this->ip;
}

void Terminal::enviarPagina(){

}

void Terminal::recibirPagina(){
    
}