typedef struct NodoA {
    int dato;
    struct NodoA* izq;
    struct NodoA* der;
} NodoA;
typedef NodoA* ArbolBinario;

ArbolBinario crearNodo(int dato);
void setHijoIzq(ArbolBinario padre, int dato);
void setHijoDer(ArbolBinario padre, int dato);
int getDato(ArbolBinario nodo);
void setDato(ArbolBinario nodo, int dato);
ArbolBinario getSubarbolIzq(ArbolBinario nodo);
ArbolBinario getSubarbolDer(ArbolBinario nodo);
int size(ArbolBinario arbol);
int *inorden(ArbolBinario arbol);
ArbolBinario buscar(ArbolBinario arbol, int dato);