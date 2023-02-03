#ifndef HASH_H
#define HASH_H
#include <iostream>
#include "Lista.h"
#include "Nodo.h"
#include "Paquete.h"
#define MAX 5
using namespace std;

class Hash{
private:
    int Max;
    Lista<Paquete> D[MAX];
public:
    Hash(){Max = MAX;};
//    void agregarPaqueteAlHash(Paquete *);
    //void impre(void);

};




#endif