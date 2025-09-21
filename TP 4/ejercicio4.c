#include "ArbolBinario.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/**
 * Redondea un numero decimal al entero mas cercano
 * Si la parte fraccionaria es igual o mayor a 0.5, redondea al entero mayor; de lo contrario, al menor
 *
 * Parametros:
 *      - x (double) - numero decimal a redondear
 *
 * Retorna: (int) - numero redondeado
 */
int redondear(double x)
{
    double parteFraccionaria = x - round(x);
    if (parteFraccionaria < 0.5)
        return round(x);
    else
        return round(x + 1);
}

// Devuelve 0 o 1 de forma aleatoria
// No requiere parametros
// Retorna: 0 con probabilidad 0.5 y 1 con probabilidad 0.5
int booleanoAleatorio()
{
    return redondear((double)rand() / RAND_MAX);
}

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
