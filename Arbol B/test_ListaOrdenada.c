#include "ListaOrdenada.h"
#include <stdio.h>
#include <assert.h>

void test_inicializarLista()
{
    printf("Probando inicializarLista...\n");
    ListaOrdenada lista;
    inicializarLista(&lista);
    assert(lista == NULL);
    printf("✓ inicializarLista: PASSED\n");
}

void test_insertar()
{
    printf("Probando insertar...\n");
    ListaOrdenada lista;
    inicializarLista(&lista);

    // Insertar elementos en orden desordenado para verificar que se ordenan automáticamente
    insertar(&lista, 30);
    insertar(&lista, 10);
    insertar(&lista, 20);
    insertar(&lista, 5);
    insertar(&lista, 25);

    // Verificar que los elementos están ordenados
    assert(getElemento(lista, 0) == 5);
    assert(getElemento(lista, 1) == 10);
    assert(getElemento(lista, 2) == 20);
    assert(getElemento(lista, 3) == 25);
    assert(getElemento(lista, 4) == 30);

    printf("✓ insertar: PASSED\n");
}

void test_getElemento()
{
    printf("Probando getElemento...\n");
    ListaOrdenada lista;
    inicializarLista(&lista);

    insertar(&lista, 100);
    insertar(&lista, 50);
    insertar(&lista, 75);

    // Verificar elementos válidos
    assert(getElemento(lista, 0) == 50);
    assert(getElemento(lista, 1) == 75);
    assert(getElemento(lista, 2) == 100);

    // Verificar índices inválidos
    assert(getElemento(lista, -1) == NULL);
    assert(getElemento(lista, 3) == NULL);
    assert(getElemento(lista, 10) == NULL);

    printf("✓ getElemento: PASSED\n");
}

void test_eliminar()
{
    printf("Probando eliminar...\n");
    ListaOrdenada lista;
    inicializarLista(&lista);

    insertar(&lista, 40);
    insertar(&lista, 20);
    insertar(&lista, 60);
    insertar(&lista, 10);

    // Lista: [10, 20, 40, 60]

    // Eliminar elemento del medio
    TElementoLista eliminado = eliminar(&lista, 2);
    assert(eliminado == 40);
    assert(len(lista) == 3);
    assert(getElemento(lista, 0) == 10);
    assert(getElemento(lista, 1) == 20);
    assert(getElemento(lista, 2) == 60);

    // Eliminar primer elemento
    eliminado = eliminar(&lista, 0);
    assert(eliminado == 10);
    assert(len(lista) == 2);

    // Eliminar último elemento
    eliminado = eliminar(&lista, 1);
    assert(eliminado == 60);
    assert(len(lista) == 1);

    // Eliminar último elemento restante
    eliminado = eliminar(&lista, 0);
    assert(eliminado == 20);
    assert(len(lista) == 0);

    // Verificar eliminación de lista vacía
    eliminado = eliminar(&lista, 0);
    assert(eliminado == NULL);

    printf("✓ eliminar: PASSED\n");
}

void test_len()
{
    printf("Probando len...\n");
    ListaOrdenada lista;
    inicializarLista(&lista);

    // Lista vacía
    assert(len(lista) == 0);

    // Agregar elementos
    insertar(&lista, 1);
    assert(len(lista) == 1);

    insertar(&lista, 2);
    assert(len(lista) == 2);

    insertar(&lista, 3);
    insertar(&lista, 4);
    insertar(&lista, 5);
    assert(len(lista) == 5);

    // Eliminar elementos
    eliminar(&lista, 0);
    assert(len(lista) == 4);

    eliminar(&lista, 0);
    eliminar(&lista, 0);
    assert(len(lista) == 2);

    printf("✓ len: PASSED\n");
}

void test_dividir()
{
    printf("Probando dividir...\n");
    ListaOrdenada lista;
    inicializarLista(&lista);

    // Llenar lista con elementos: [1, 2, 3, 4, 5, 6]
    for (int i = 6; i >= 1; i--)
    {
        insertar(&lista, i);
    }

    // Dividir en índice 3
    ListaOrdenada *resultado = dividir(&lista, 3);

    if (resultado != NULL)
    {
        // Primera lista debe tener elementos [1, 2, 3]
        assert(len(resultado[0]) == 3);
        assert(getElemento(resultado[0], 0) == 1);
        assert(getElemento(resultado[0], 1) == 2);
        assert(getElemento(resultado[0], 2) == 3);

        // Segunda lista debe tener elementos [4, 5, 6]
        assert(len(resultado[1]) == 3);
        assert(getElemento(resultado[1], 0) == 4);
        assert(getElemento(resultado[1], 1) == 5);
        assert(getElemento(resultado[1], 2) == 6);

        free(resultado);
    }

    printf("✓ dividir: PASSED\n");
}

void test_toString()
{
    printf("Probando toString...\n");
    ListaOrdenada lista;
    inicializarLista(&lista);

    // Lista vacía
    String str = toString(lista);
    if (str != NULL)
    {
        printf("Lista vacía: %s\n", str);
        free(str);
    }

    // Lista con elementos
    insertar(&lista, 15);
    insertar(&lista, 5);
    insertar(&lista, 25);

    str = toString(lista);
    if (str != NULL)
    {
        printf("Lista [5, 15, 25]: %s\n", str);
        free(str);
    }

    printf("✓ toString: PASSED\n");
}

void mostrar_lista(ListaOrdenada lista, const char *nombre)
{
    printf("%s: ", nombre);
    String str = toString(lista);
    if (str != NULL)
    {
        printf("%s\n", str);
        free(str);
    }
    else
    {
        printf("Error al convertir lista a string\n");
    }
}

int main()
{
    printf("=== PRUEBAS DE LISTA ORDENADA ===\n\n");

    test_inicializarLista();
    printf("\n");

    test_insertar();
    printf("\n");

    test_getElemento();
    printf("\n");

    test_eliminar();
    printf("\n");

    test_len();
    printf("\n");

    test_dividir();
    printf("\n");

    test_toString();
    printf("\n");

    // Prueba integral
    printf("=== PRUEBA INTEGRAL ===\n");
    ListaOrdenada lista;
    inicializarLista(&lista);

    printf("Insertando elementos: 50, 30, 70, 20, 60, 10, 80\n");
    insertar(&lista, 50);
    insertar(&lista, 30);
    insertar(&lista, 70);
    insertar(&lista, 20);
    insertar(&lista, 60);
    insertar(&lista, 10);
    insertar(&lista, 80);

    mostrar_lista(lista, "Lista completa");
    printf("Longitud: %d\n", len(lista));

    printf("\nEliminando elemento en índice 3...\n");
    TElementoLista eliminado = eliminar(&lista, 3);
    printf("Elemento eliminado: %d\n", eliminado);
    mostrar_lista(lista, "Lista después de eliminar");

    printf("\n=== TODAS LAS PRUEBAS COMPLETADAS ===\n");

    return 0;
}