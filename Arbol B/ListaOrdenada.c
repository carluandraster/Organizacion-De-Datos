#include "ListaOrdenada.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * Inicializa la lista ordenada en NULL.
 * @param l Puntero a la lista ordenada a inicializar.
 */
void inicializarLista(ListaOrdenada *l)
{
    *l = NULL;
}

/**
 * (Método privado)
 * Crea un nuevo nodo con el elemento dado.
 * @param e Elemento a almacenar en el nodo.
 * @return Puntero al nuevo nodo creado, o NULL si no se pudo asignar memoria.
 */
Nodo *crearNodo(TElementoLista e)
{
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    if (nuevo != NULL)
    {
        nuevo->dato = e;
        nuevo->siguiente = NULL;
    }
    return nuevo;
}

/**
 * Inserta un elemento en la lista ordenada manteniendo el orden.
 * @param l Puntero a la lista ordenada donde se insertará el elemento.
 * @param e Elemento a insertar.
 */
void insertar(ListaOrdenada *l, TElementoLista e)
{
    Nodo **iterador = l;
    Nodo *nuevo = crearNodo(e);
    while (*iterador != NULL && (*iterador)->dato < e)
        iterador = &(*iterador)->siguiente;
    nuevo->siguiente = *iterador;
    *iterador = nuevo;
}

/**
 * Obtiene el elemento en la posición indicada.
 * Pre: la lista no está vacía y el índice es válido.
 * @param l Lista ordenada de la cual se obtendrá el elemento.
 * @param indice Índice del elemento a obtener (0-based).
 * @return El elemento en la posición indicada
 */
TElementoLista getElemento(ListaOrdenada l, int indice)
{
    Nodo *actual = l;
    int contador = 0;
    while (actual != NULL && contador < indice)
    {
        actual = actual->siguiente;
        contador++;
    }
    if (actual != NULL && contador == indice)
        return actual->dato;
    return NULL;
}

/**
 * Elimina el elemento en la posición indicada y lo retorna.
 * Pre: la lista no está vacía y el índice es válido.
 * @param l Puntero a la lista ordenada de la cual se eliminará el elemento.
 * @param indice Índice del elemento a eliminar (0-based).
 * @return El elemento eliminado
 */
TElementoLista eliminar(ListaOrdenada *l, int indice)
{
    Nodo **iterador = l;
    int contador = 0;
    Nodo *eliminado;
    TElementoLista dato;

    if (l == NULL || *l == NULL)
        return NULL;

    while (*iterador != NULL && contador < indice)
    {
        iterador = &(*iterador)->siguiente;
        contador++;
    }

    if (*iterador != NULL && contador == indice)
    {
        eliminado = *iterador;
        *iterador = (*iterador)->siguiente;
        dato = eliminado->dato;
        free(eliminado);
        return dato;
    }

    return NULL;
}

/**
 * Divide la lista en dos partes en el índice indicado.
 * La lista original se modifica para contener solo la primera parte.
 *
 * @param l Puntero a la lista ordenada a dividir.
 * @param indice Índice en el cual dividir la lista (0-based).
 * @return Vector de las 2 listas, o NULL si el índice es inválido.
 */
ListaOrdenada *dividir(ListaOrdenada *l, int indice)
{
    ListaOrdenada *resultado;
    Nodo *actual = *l;
    Nodo *anterior = NULL;
    int contador = 0;

    if (l == NULL || *l == NULL || indice < 0 || resultado == NULL)
        return NULL;

    *resultado = (ListaOrdenada *)malloc(2 * sizeof(ListaOrdenada *));

    resultado[0] = *l;
    inicializarLista(&resultado[1]);

    while (actual != NULL && contador < indice)
    {
        anterior = actual;
        actual = actual->siguiente;
        contador++;
    }

    // Si el índice es válido, crear la segunda lista
    if (contador == indice)
    {
        // Terminar la primera lista
        if (anterior != NULL)
            anterior->siguiente = NULL;
        resultado[1] = actual;
    }
    else
    {
        free(resultado);
        return NULL;
    }

    return resultado;
}

/**
 * Calcula la longitud de la lista.
 * @param l Lista ordenada de la cual se calculará la longitud.
 * @return La longitud de la lista.
 */
int len(ListaOrdenada l)
{
    int longitud = 0;
    Nodo *actual = l;
    while (actual != NULL)
    {
        longitud++;
        actual = actual->siguiente;
    }
    return longitud;
}

/**
 * Convierte la lista a una representación en cadena.
 * @param l Lista ordenada a convertir.
 * @return Cadena que representa la lista, o NULL si no se pudo asignar memoria.
 */
String toString(ListaOrdenada l)
{
    String resultado = (String)malloc(1024);
    Nodo *actual = l;
    String buffer;
    if (resultado == NULL)
        return NULL;
    resultado[0] = '[';
    while (actual != NULL)
    {
        if (actual->siguiente != NULL)
        {
            sprintf(buffer, "%d]", actual->dato);
        }
        else
        {
            sprintf(buffer, "%d, ", actual->dato);
        }
        strcat(resultado, buffer);
        actual = actual->siguiente;
    }

    return resultado;
}
