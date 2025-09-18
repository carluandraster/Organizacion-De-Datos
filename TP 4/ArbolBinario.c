#include <stdlib.h>
#include "ArbolBinario.h"

ArbolBinario crearNodo(int dato){
    NodoA *nuevoNodo = (NodoA *)malloc(sizeof(NodoA));
    nuevoNodo->dato = dato;
    nuevoNodo->izq = NULL;
    nuevoNodo->der = NULL;
    return nuevoNodo;
}

void setHijoIzq(ArbolBinario padre, int dato){
    if(padre != NULL){
        padre->izq = crearNodo(dato);
    }
}

void setHijoDer(ArbolBinario padre, int dato){
    if(padre != NULL){
        padre->der = crearNodo(dato);
    }
}

int getDato(ArbolBinario nodo){
    if(nodo != NULL){
        return nodo->dato;
    }
    return NULL; // Valor de error
}

void setDato(ArbolBinario nodo, int dato){
    if(nodo != NULL){
        nodo->dato = dato;
    }
}

ArbolBinario getSubarbolIzq(ArbolBinario nodo){
    if(nodo != NULL){
        return nodo->izq;
    }
    return NULL;
}

ArbolBinario getSubarbolDer(ArbolBinario nodo){
    if(nodo != NULL){
        return nodo->der;
    }
    return NULL;
}

int size(ArbolBinario arbol){
    if(arbol == NULL){
        return 0;
    }
    return 1 + size(arbol->izq) + size(arbol->der);
}

int *inorden(ArbolBinario arbol){
    int *resultado = (int *)malloc(size(arbol) * sizeof(int));
    int i;

    // Recorrer subárbol izquierdo
    if(arbol->izq != NULL){
        int *izq = inorden(arbol->izq);
        int izqSize = size(arbol->izq);
        for(i = 0; i < izqSize; i++){
            resultado[i] = izq[i];
        }
        free(izq);
    }

    // Visitar nodo raíz
    resultado[i] = arbol->dato;

    // Recorrer subárbol derecho
    if(arbol->der != NULL){
        int *der = inorden(arbol->der);
        int derSize = size(arbol->der);
        for(int j = 0; j < derSize; j++){
            resultado[i + 1 + j] = der[j];
        }
        free(der);
    }

    return resultado;
}

ArbolBinario buscar(ArbolBinario arbol, int dato){
    if(arbol == NULL || arbol->dato == dato)
        return arbol;
    else
        return buscar(arbol->izq, dato) || buscar(arbol->der, dato);
}