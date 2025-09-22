#include "ArbolBinario.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define MENOS_INFINITO -2147483648

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

void _insertarRandom(ArbolBinario *arbol, int random)
{
    int izquierda = booleanoAleatorio();
    if (random > getDato(*arbol))
    {
        if (izquierda)
        {
            if (getSubarbolIzq(*arbol) == NULL)
                setHijoIzq(*arbol, random);
            else
            {
                ArbolBinario izq = getSubarbolIzq(*arbol);
                _insertarRandom(&izq, random);
            }
        }
        else
        {
            if (getSubarbolDer(*arbol) == NULL)
                setHijoDer(*arbol, random);
            else
            {
                ArbolBinario der = getSubarbolDer(*arbol);
                _insertarRandom(&der, random);
            }
        }
    }
    else
    {
        ArbolBinario nuevoNodo = crearNodo(random);
        if (izquierda)
            nuevoNodo->izq = *arbol;
        else
            nuevoNodo->der = *arbol;
        *arbol = nuevoNodo;
    }
}

void insertarRandom(ArbolBinario *arbol)
{
    int dato = rand();
    if (*arbol == NULL)
        *arbol = crearNodo(dato);
    else
        _insertarRandom(arbol, dato);
}

int main(int argc, char const *argv[])
{
    srand(time(NULL)); // Inicializa la semilla para la generacion de numeros aleatorios
    ArbolBinario arbol = NULL;

    for (int i = 0; i < 100000; i++)
        insertarRandom(&arbol);

    return 0;
}