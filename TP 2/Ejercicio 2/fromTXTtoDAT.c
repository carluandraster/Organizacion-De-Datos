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

    AlumnoFijo alumnoFijo;
    while (fscanf(txtFile, "%4s %4s %4s %4s %d %d %f %s",
                  alumnoFijo.codigoUniversidad,
                  alumnoFijo.codigoAsignatura,
                  alumnoFijo.codigoFacultad,
                  alumnoFijo.codigoDocente,
                  &alumnoFijo.legajo,
                  &alumnoFijo.edad,
                  &alumnoFijo.nota,
                  alumnoFijo.observaciones) == 8)
    {
        alumnoFijo.baja = 0; // Asumiendo que los datos leídos no están dados de baja
        fwrite(&alumnoFijo, sizeof(AlumnoFijo), 1, datFile);
    }

    fclose(txtFile);
    fclose(datFile);
}

int main(int argc, char const *argv[])
{
    fromTXTtoDAT("alumnos.txt", "alumnos.dat");
    return 0;
}
