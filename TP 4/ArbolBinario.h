typedef struct NodoA {
    int dato;
    struct NodoA* izq;
    struct NodoA* der;
} NodoA;
typedef NodoA* ArbolBinario;

ArbolBinario crearNodo(int dato);
void setHijoIzq(ArbolBinario padre, ArbolBinario hijo);
void setHijoDer(ArbolBinario padre, ArbolBinario hijo);
int getDato(ArbolBinario nodo);
void setDato(ArbolBinario nodo, int dato);
ArbolBinario getSubarbolIzq(ArbolBinario nodo);
ArbolBinario getSubarbolDer(ArbolBinario nodo);
int *inorden(ArbolBinario arbol);
ArbolBinario buscar(ArbolBinario arbol, int dato);