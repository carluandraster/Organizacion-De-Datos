#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    char *codigoUniversidad;
    char *codigoFacultad;
    char *codigoAsignatura;
    int legajo;
    int edad;
    char *codigoDocente;
    float nota;
    char *observaciones;
    char baja; // 1 si esta dado de baja, 0 si no
} AlumnoVariable;

void fromTXTtoDAT(const char *inputTXT, const char *outputDAT)
{
    char codigoUniversidad[5];
    char codigoFacultad[5];
    char codigoAsignatura[5];
    char codigoDocente[5];
    char observaciones[255];
    FILE *txtFile = fopen(inputTXT, "rt");
    if (txtFile == NULL)
    {
        perror("Error opening input TXT file");
        return;
    }

    FILE *datFile = fopen(outputDAT, "wb");
    if (datFile == NULL)
    {
        perror("Error opening output DAT file");
        fclose(txtFile);
        return;
    }

    AlumnoVariable alumno;
    while (fscanf(txtFile, "%s %s %s %s %d %d %f %s",
                  codigoUniversidad,
                  codigoAsignatura,
                  codigoFacultad,
                  codigoDocente,
                  &alumno.legajo,
                  &alumno.edad,
                  &alumno.nota,
                  observaciones) == 8)
    {
        alumno.codigoUniversidad = malloc(strlen(codigoUniversidad) + 1);
        strcpy(alumno.codigoUniversidad, codigoUniversidad);
        alumno.codigoFacultad = malloc(strlen(codigoFacultad) + 1);
        strcpy(alumno.codigoFacultad, codigoFacultad);
        alumno.codigoAsignatura = malloc(strlen(codigoAsignatura) + 1);
        strcpy(alumno.codigoAsignatura, codigoAsignatura);
        alumno.codigoDocente = malloc(strlen(codigoDocente) + 1);
        strcpy(alumno.codigoDocente, codigoDocente);
        alumno.observaciones = malloc(strlen(observaciones) + 1);
        strcpy(alumno.observaciones, observaciones);
        alumno.baja = 0; // Asumiendo que los datos leídos no están dados de baja
        fwrite(&alumno, sizeof(AlumnoVariable), 1, datFile);
        free(alumno.codigoUniversidad);
        free(alumno.codigoFacultad);
        free(alumno.codigoAsignatura);
        free(alumno.codigoDocente);
        free(alumno.observaciones);
    }

    fclose(txtFile);
    fclose(datFile);
}

int main(int argc, char const *argv[])
{
    fromTXTtoDAT("alumnos.txt", "alumnosVariables.dat");
    return 0;
}
