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
                  &alumno.codigoUniversidad,
                  &alumno.codigoAsignatura,
                  &alumno.codigoFacultad,
                  &alumno.codigoDocente,
                  &alumno.legajo,
                  &alumno.edad,
                  &alumno.nota,
                  &alumno.observaciones) == 8)
    {
        alumno.baja = 0; // Asumiendo que los datos leídos no están dados de baja
        fwrite(&alumno, sizeof(AlumnoVariable), 1, datFile);
    }

    fclose(txtFile);
    fclose(datFile);
}

int main(int argc, char const *argv[])
{
    fromTXTtoDAT("alumnos.txt", "alumnosVariables.dat");

    // Prueba
    FILE *file = fopen("alumnosVariables.dat", "rb");

    if (file == NULL)
    {
        perror("Error opening DAT file for reading");
        return 1;
    }
    AlumnoVariable alumno;
    while (fread(&alumno, sizeof(alumno), 1, file) == 1)
    {
        printf("Codigo Universidad: %s\n", alumno.codigoUniversidad);
        printf("Codigo Facultad: %s\n", alumno.codigoFacultad);
        printf("Codigo Asignatura: %s\n", alumno.codigoAsignatura);
        printf("Legajo: %d\n", alumno.legajo);
        printf("Edad: %d\n", alumno.edad);
        printf("Codigo Docente: %s\n", alumno.codigoDocente);
        printf("Nota: %.2f\n", alumno.nota);
        printf("Observaciones: %s\n", alumno.observaciones);
        printf("Baja: %d\n", alumno.baja);
        printf("-------------------------\n");
    }
    fclose(file);
    return 0;
}
