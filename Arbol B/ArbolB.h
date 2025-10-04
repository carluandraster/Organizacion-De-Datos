#include "ListaOrdenada.h"

typedef TElementoLista TElementoArbol;
typedef struct NodoArbol
{
    ListaOrdenada *claves;
    struct NodoArbol **hijos; // Vector de punteros a hijos
} NodoArbol;
typedef struct
{
    NodoArbol *raiz;
    int orden; // Orden del árbol B
} ArbolB;

ArbolB *crearArbolB(int orden);
NodoArbol *_crearNodoArbol(int orden, int nuevoElemento);
void insertarArb(ArbolB *arbol, TElementoArbol clave);
void _insertar(ArbolB *arbol, TElementoArbol clave, TElementoArbol *promovida);
void eliminarArb(ArbolB *arbol, TElementoArbol clave);
TElementoArbol *recorrer(ArbolB *arbol);
int lenArb(ArbolB *arbol);