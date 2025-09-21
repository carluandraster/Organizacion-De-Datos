#include "ArbolBinario.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/**
 * Redondea un numero decimal al entero mas cercano
 * Si la parte fraccionaria es igual o mayor a 0.5, redondea al entero mayor; de lo contrario, al menor
 *
 * @param x (double) - numero decimal a redondear
 *
 * @returns (int) - numero redondeado
 */
int redondear(double x)
{
    double parteFraccionaria = x - round(x);
    if (parteFraccionaria < 0.5)
        return round(x);
    else
        return round(x + 1);
}

/**
 * Genera un valor booleano aleatorio (0 o 1) con igual probabilidad
 *
 * @param void
 *
 * @returns (int) - 0 o 1
 */
int booleanoAleatorio()
{
    return redondear((double)rand() / RAND_MAX);
}

/**
 * Inserta un nodo con valor aleatorio en un arbol binario.
 *
 * La insercion se realiza de forma aleatoria, eligiendo al azar si se inserta en el subarbol izquierdo o derecho
 *
 * @param arbol (ArbolBinario*) - puntero al arbol binario donde se insertara el nodo
 *
 * @returns (void)
 */
void insertarRandom(ArbolBinario *arbol)
{
    ArbolBinario aux;
    int dato = rand();
    int izquierda;
    if (*arbol == NULL)
        *arbol = crearNodo(dato);
    else
    {
        izquierda = booleanoAleatorio();
        if (izquierda)
        {
            aux = getSubarbolIzq(*arbol);
            insertarRandom(&aux);
        }
        else
        {
            aux = getSubarbolDer(*arbol);
            insertarRandom(&aux);
        }
    }
}

int main(int argc, char const *argv[])
{
    srand(time(NULL)); // Inicializa la semilla para la generacion de numeros aleatorios
    ArbolBinario arbol = NULL;

    for (int i = 0; i < 100000; i++)
        insertarRandom(&arbol);

    return 0;
}
