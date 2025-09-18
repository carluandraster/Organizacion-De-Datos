#include "ArbolBinario.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int redondear(double x){
    double parteFraccionaria = x-round(x);
    if(parteFraccionaria < 0.5)
        return round(x);
    else
        return round(x+1);
}

int booleanoAleatorio(){
    return redondear((double) rand()/RAND_MAX);
}

void insertarRandom(ArbolBinario* arbol){
    int dato = rand();
    if(arbol == NULL)
        *arbol = crearNodo(dato);
    else{
        int izquierda = booleanoAleatorio();
    }
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
