#ifndef LISTA_H
#define LISTA_H
#include <assert.h>
#include <iostream>
#include "Nodo.h"


template <class T> class Lista {
private: Nodo<T>* czo; Nodo<T>* final; int cantidaddenodos;
     
public:
    Lista() { czo = new Nodo<T>(); final = new Nodo<T>(); cantidaddenodos=0;};
    Lista(Nodo<T>* n,Nodo<T>* f) {czo = n ; final =f;cantidaddenodos=0;};
    //~Lista(void);
    void add(T d); //sumar nodos a la lista
    void addFinal(T d);
    bool esvacia(void);
    T cabeza(void); //retorna el dato del primer nodo
    T ultimo(void);
    Lista* resto(void); //retorna el puntero al "resto" de la lista
    Nodo<T>* comienzo(){return czo;};
    string toPrint(string p);
    T suma(T i);
    int size();
    void borrar(void); //borra la cabeza
    void borrar_last();//borra el ultimo
    void concat(Lista<T>* l1);// le transfiere los datos de l1 a this
    Lista<T>* copy(void);// hace una copia de la lista
    void tomar(int n);//deja "vivos" los n primeros nodos y borra el resto
    T buscarPorIndice(int);
   
};


template <class T>
void Lista<T>::add(T d) //100
{
    Nodo<T>* nuevo = new Nodo<T>(d);
    if(this->esvacia()){
        czo = nuevo; final = nuevo;
    }else{
        nuevo->set_next(czo);
        czo = nuevo;
    }
    cantidaddenodos++;

}

template <class T>
void Lista<T>::addFinal(T d){
    Nodo<T>* nuevo = new Nodo<T>(d);
    if (this->esvacia()){
        czo = nuevo;
        final = nuevo;
    }else{
        final->set_next(nuevo);
    }
    final = nuevo;
    cantidaddenodos++;

}
template <class T>
bool Lista<T>::esvacia(void)
{
    return cantidaddenodos==0;
}
template <class T>
T Lista<T>::cabeza(void)
{
    if (this->esvacia()) {
        cout << " Error, Cabeza de lista vacia";
       
    }
    return czo->get_dato();
}
template <class T>
T Lista<T>::ultimo(void){
    if (this->esvacia()){
        cout<<"error lista vacia";
    }
    return final->get_dato();
}


template <class T>
Lista<T>* Lista<T>::resto(void)
{
    Lista* l = new Lista(czo->get_next(),final);
    return (l);
}

template <class T>
string Lista<T>::toPrint(string p)
{
    if (this->esvacia()) {
        return p;
    }
    else {
        //std::ostringstream stm;
        ostringstream stm;
        stm << this->cabeza() << "-" << this->resto()->toPrint(p) << endl;
        //cout<<endl<<" stm.str()= "<<stm.str()<<endl;
        return stm.str();
    }
}

template <class T>
T Lista<T>::suma(T i)
{    //cout<<" i al entrar= "<<i<<endl;
    if (this->esvacia()) {
        return i;
    }
    else {

        //cout<<"this->cabeza()= "<<this->cabeza()<<endl;   
        return this->resto()->suma(i + this->cabeza());
    }
}


/*
void addOrdenado(T d)// suma nodos ordenados de menor a mayor
bool esta(T d); //retorna true cuando d est� en la lista
void borrarDato(T d)// borra el nodo que contiene a d
*/

template <class T> int Lista<T>::size()
{
    return cantidaddenodos;
}



template <class T> void Lista<T>::borrar(void)
{ //borra el nodo cabeza
    if (!this->esvacia()) {
        Nodo<T>* tmp = czo;
        czo = czo->get_next();
        delete tmp;
    }
}

template <class T> void Lista<T>::borrar_last()
{ // borra el ultimo nodo
    if (!this->esvacia()) {
        if ((czo->get_next())->get_next() == NULL) {
            delete czo->get_next();
            czo->set_next(NULL);
        }
        else this->resto()->borrar_last();
    }
}

template <class T> void Lista<T>::concat(Lista<T>* l1)
{// le transfiere los datos de l1 a this
    if (!(l1->esvacia())) {
        this->concat(l1->resto());
        this->add(l1->cabeza());
    }
}

template <class T> Lista<T>* Lista<T>::copy(void)
{
    Lista<T>* aux = new Lista();
    aux->concat(this);
    return aux;
}

template <class T> void Lista<T>::tomar(int n)
{ //deja "vivos" los n primeros nodos y borra el resto
    if (this->size() > n) {
        this->borrar_last();
        this->tomar(n);
    }
}

template <class T> T Lista<T> :: buscarPorIndice(int indice){
    if(czo==NULL){
        cout<<"Lista vacia"<<endl;
    }else if(indice>cantidaddenodos){
        cout<<"no existe el nodo"<<endl;
    }
    Nodo<T>* aux = czo;
    int pos=0;

    while(pos!=indice){
        aux = aux->get_next();
        pos++;
    }

    return aux->get_dato();
}

#endif