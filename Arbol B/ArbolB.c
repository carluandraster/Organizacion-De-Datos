#include "ArbolB.h"

/**
 * Crea un nuevo árbol B con el orden especificado.
 * @param orden Orden del árbol B (número máximo de hijos por nodo).
 * @return Puntero al nuevo árbol B creado, o NULL si no se pudo asignar memoria.
 */
ArbolB *crearArbolB(int orden)
{
    ArbolB *nuevoArbol = (ArbolB *)malloc(sizeof(ArbolB));
    if (nuevoArbol != NULL)
    {
        nuevoArbol->raiz = NULL;
        nuevoArbol->orden = orden;
    }
    return nuevoArbol;
}

NodoArbol *_crearNodoArbol(int orden, int nuevoElemento)
{
    NodoArbol *nuevoNodo = (NodoArbol *)malloc(sizeof(NodoArbol));
    if (nuevoNodo != NULL)
    {
        nuevoNodo->claves = (ListaOrdenada *)malloc(sizeof(ListaOrdenada));
        inicializarLista(nuevoNodo->claves);
        nuevoNodo->hijos = (NodoArbol **)malloc(orden * sizeof(NodoArbol *));
        for (int i = 0; i < orden; i++)
            nuevoNodo->hijos[i] = NULL;
        insertar(nuevoNodo->claves, nuevoElemento);
    }
    return nuevoNodo;
}

/**
 * Inserta una clave en el árbol B.
 * @param arbol Puntero al árbol B donde se insertará la clave.
 * @param clave La clave a insertar en el árbol B.
 */
void insertar(ArbolB *arbol, TElementoArbol clave)
{
    if (arbol != NULL)
    {
        TElementoArbol promovida;
        _insertar(arbol, clave, &promovida);
    }
}

void _insertar(ArbolB *arbol, TElementoArbol clave, TElementoArbol *promovida)
{
    // Declaración de variables
    NodoArbol *nodoActual = arbol->raiz;
    NodoArbol *padre = NULL;
    int indiceHijo = -1;
    int i, N;
    char salir = 0;
    ListaOrdenada *nuevaLista;
    TElementoArbol clavePromovida;

    if (arbol->raiz == NULL)
    {
        arbol->raiz = _crearNodoArbol(arbol->orden, clave);
        promovida = NULL; // No hay promoción
    }
    else
    {
        // Buscar el nodo hoja donde se debe insertar la clave
        while (nodoActual != NULL && !salir)
        {
            if (len(nodoActual->claves) < arbol->orden - 1 && nodoActual->hijos[0] == NULL)
            {
                // Si el nodo tiene espacio y no tiene hijos, insertar la clave aquí
                insertar(nodoActual->claves, clave);
                promovida = NULL; // No hay promoción
                salir = 1;
            }
            else
            {
                // Nodo lleno, buscar el hijo adecuado
                padre = nodoActual;
                N = len(nodoActual->claves);
                i = 0;
                while (i < N && clave >= getElemento(nodoActual->claves, i))
                    i++;
                if (i == N)
                    indiceHijo = N;
                else
                    indiceHijo = i;
            }
            i++;
        }
        if (!salir)
        {
            if (i == len(nodoActual->claves))
                indiceHijo = len(nodoActual->claves);

            nodoActual = nodoActual->hijos[indiceHijo];
        }
    }

    // Si llegamos aquí, significa que el nodo hoja está lleno y debemos dividirlo
    if (padre != NULL && !salir)
    {
        *nuevaLista = dividir(padre->claves, len(padre->claves) / 2);
        clavePromovida = getElemento(nuevaLista[1], 0);

        // Crear un nuevo nodo para la nueva lista de claves
        NodoArbol *nuevoNodo = crearNodoArbol(arbol->orden, clavePromovida);
        nuevoNodo->claves = nuevaLista[1];

        // Ajustar los hijos del padre
        for (int j = len(padre->claves); j > indiceHijo; j--)
        {
            padre->hijos[j + 1] = padre->hijos[j];
        }
        padre->hijos[indiceHijo + 1] = nuevoNodo;

        // Insertar la clave promovida en el padre
        insertar(padre->claves, clavePromovida);
    }
}