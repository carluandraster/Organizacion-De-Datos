#include <stdio.h>

typedef struct
{
    char codigoUniversidad[5];
    char codigoFacultad[5];
    char codigoAsignatura[5];
    int legajo;
    int edad;
    char codigoDocente[5];
    float nota;
    char observaciones[255];
    char baja; // 1 si esta dado de baja, 0 si no
} AlumnoFijo;

typedef struct
{
    char* codigoUniversidad;
    char* codigoFacultad;
    char* codigoAsignatura;
    int legajo;
    int edad;
    char* codigoDocente;
    float nota;
    char* observaciones;
    char baja; // 1 si esta dado de baja, 0 si no
} AlumnoVariable;
