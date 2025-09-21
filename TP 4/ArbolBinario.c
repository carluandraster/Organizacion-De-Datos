#include <stdlib.h>
#include "ArbolBinario.h"

/**
 * Crea un nuevo nodo de árbol binario con el dato proporcionado
 *
 * @param dato (int) - valor a almacenar en el nodo
 *
 * @returns (ArbolBinario) - puntero al nuevo nodo creado
 */
ArbolBinario crearNodo(int dato)
{
    NodoA *nuevoNodo = (NodoA *)malloc(sizeof(NodoA));
    nuevoNodo->dato = dato;
    nuevoNodo->izq = NULL;
    nuevoNodo->der = NULL;
    return nuevoNodo;
}

/**
 * Asigna dato al nodo hijo izquierdo al nodo padre con el dato proporcionado
 *
 * @param padre (ArbolBinario) - puntero al nodo padre
 * @param dato (int) - valor a almacenar en el nodo hijo izquierdo
 *
 * @returns void
 *
 * @post
 *    - Si el nodo padre es NULL, no se realiza ninguna acción
 *     - Si el nodo padre ya tiene un hijo izquierdo, se sobreescribe su valor con el nuevo dato
 *    - Si el nodo padre no tiene un hijo izquierdo, se crea un nuevo nodo con el dato proporcionado y se asigna como hijo izquierdo
 */
void setHijoIzq(ArbolBinario padre, int dato)
{
    if (padre != NULL)
        if (padre->izq == NULL)
            padre->izq = crearNodo(dato);
        else
            padre->izq->dato = dato;
}

/**
 * Asigna dato al nodo hijo derecho al nodo padre con el dato proporcionado
 *
 * @param padre (ArbolBinario) - puntero al nodo padre
 * @param dato (int) - valor a almacenar en el nodo hijo derecho
 *
 * @returns void
 *
 * @post
 *    - Si el nodo padre es NULL, no se realiza ninguna acción
 *   - Si el nodo padre ya tiene un hijo derecho, se sobreescribe su valor con el nuevo dato
 *  - Si el nodo padre no tiene un hijo derecho, se crea un nuevo nodo con el dato proporcionado y se asigna como hijo derecho
 */
void setHijoDer(ArbolBinario padre, int dato)
{
    if (padre != NULL)
        if (padre->der == NULL)
            padre->der = crearNodo(dato);
        else
            padre->der->dato = dato;
}

/**
 * Obtiene el dato almacenado en el nodo proporcionado
 *
 * @param nodo (ArbolBinario) - puntero al nodo del cual se desea obtener el dato
 *
 * @returns (int) - valor almacenado en el nodo, o -1 si el nodo es NULL
 *
 * @pre
 *    - El nodo no debe ser NULL
 */
int getDato(ArbolBinario nodo)
{
    return nodo->dato;
}

/**
 * Asigna un nuevo valor al dato del nodo proporcionado
 *
 * @param nodo (ArbolBinario) - puntero al nodo al cual se desea asignar el nuevo dato
 * @param dato (int) - nuevo valor a asignar al nodo
 */
void setDato(ArbolBinario nodo, int dato)
{
    if (nodo != NULL)
    {
        nodo->dato = dato;
    }
}

/**
 * Obtiene el subárbol izquierdo del nodo proporcionado
 *
 * @param nodo (ArbolBinario) - puntero al nodo del cual se desea obtener el subárbol izquierdo
 *
 * @returns (ArbolBinario) - puntero al subárbol izquierdo, o NULL si el nodo es NULL o no tiene hijo izquierdo
 */
ArbolBinario getSubarbolIzq(ArbolBinario nodo)
{
    if (nodo != NULL)
    {
        return nodo->izq;
    }
    return NULL;
}

/**
 * Obtiene el subárbol derecho del nodo proporcionado
 *
 * @param nodo (ArbolBinario) - puntero al nodo del cual se desea obtener el subárbol derecho
 *
 * @returns (ArbolBinario) - puntero al subárbol derecho, o NULL si el nodo es NULL o no tiene hijo derecho
 */
ArbolBinario getSubarbolDer(ArbolBinario nodo)
{
    if (nodo != NULL)
    {
        return nodo->der;
    }
    return NULL;
}

/**
 * Calcula el tamaño (número de nodos) del árbol binario
 *
 * @param arbol (ArbolBinario) - puntero al nodo raíz del árbol
 *
 * @returns (int) - número de nodos en el árbol
 */
int size(ArbolBinario arbol)
{
    if (arbol == NULL)
    {
        return 0;
    }
    return 1 + size(arbol->izq) + size(arbol->der);
}

/**
 * Realiza un recorrido inorden del árbol binario y almacena los datos en un arreglo
 *
 * @param arbol (ArbolBinario) - puntero al nodo raíz del árbol
 *
 * @returns (int*) - puntero a un arreglo dinámico que contiene los datos en orden, o NULL si el árbol es vacío
 */
int *inorden(ArbolBinario arbol)
{
    if (arbol == NULL)
        return NULL;

    int *resultado = (int *)malloc(size(arbol) * sizeof(int));
    int i;

    // Recorrer subárbol izquierdo
    if (arbol->izq != NULL)
    {
        int *izq = inorden(arbol->izq);
        int izqSize = size(arbol->izq);
        for (i = 0; i < izqSize; i++)
        {
            resultado[i] = izq[i];
        }
        free(izq);
    }

    // Visitar nodo raíz
    resultado[i] = arbol->dato;

    // Recorrer subárbol derecho
    if (arbol->der != NULL)
    {
        int *der = inorden(arbol->der);
        int derSize = size(arbol->der);
        for (int j = 0; j < derSize; j++)
        {
            resultado[i + 1 + j] = der[j];
        }
        free(der);
    }

    return resultado;
}

/**
 * Busca un nodo con el dato especificado en el árbol binario
 *
 * @param arbol (ArbolBinario) - puntero al nodo raíz del árbol
 * @param dato (int) - valor a buscar en el árbol
 *
 * @returns (ArbolBinario) - puntero al nodo que contiene el dato, o NULL si no se encuentra. Si hay nodos con el mismo dato, retorna el primero que encuentra en un recorrido preorden.
 */
ArbolBinario buscar(ArbolBinario arbol, int dato)
{
    if (arbol == NULL || arbol->dato == dato)
        return arbol;
    else
        return buscar(arbol->izq, dato) || buscar(arbol->der, dato);
}