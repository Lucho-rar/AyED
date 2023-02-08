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

void Terminal::recibirPagina(Pagina *p){
    cout << "\033[1;46mSE COMPLETO EL ENVIO DE UNA PAGINA\033[0m\n"<<endl;
    cout<<"Soy el terminal "<<getIP()[1]<<" conectado al router "<<getIP()[0]<<" y recibi una pagina completa de numero "<<p->getidentificadorDePag()<<"."<<endl<<endl;
    
}