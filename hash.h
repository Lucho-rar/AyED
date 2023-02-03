#ifndef HASH_H
#define HASH_H
#include <iostream>
#include "Lista.h"
#include "Nodo.h"

#define MAX 5
using namespace std;

class Hash{
private:
    int Max;
    Lista<int> D[MAX];
public:
    Hash(){Max = MAX;};
    void agregar(int);
    void impre(void);

};

void Hash::agregar(int s){
    int i = s;
    cout<<s<<" i =" <<i<<endl;
    D[i].addFinal(s);
}

void Hash::impre(){
    for (int i =0; i<Max; i++){
        cout<<i<<"    :"<<D[i].buscarPorIndice(i)<<endl;
    }
}

#endif