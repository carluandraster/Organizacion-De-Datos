#include <cstddef>

typedef int TElementoLista;
typedef struct Nodo
{
    TElementoLista dato;
    struct Nodo *siguiente;
} Nodo;
typedef Nodo *ListaOrdenada;

void inicializarLista(ListaOrdenada *l);
Nodo *crearNodo(TElementoLista e);
void insertar(ListaOrdenada *l, TElementoLista e);
TElementoLista getElemento(ListaOrdenada l, int indice);
TElementoLista eliminar(ListaOrdenada *l, int indice);
TElementoLista *dividir(ListaOrdenada *l, int indice);
int len(ListaOrdenada l);