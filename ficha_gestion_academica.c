#include <stdio.h>
#include <string.h>

#define MAX_NOTAS 5
#define FILAS 3
#define COLUMNAS 4

void moduloVerificacion(void);
void moduloControlFlujo(void);
void moduloVector(void);
void moduloMatriz(void);
void moduloCadenas(void);

int main(void) {
    int opcion;

    do {
        printf("\n===============================================\n");
        printf("   SISTEMA INTEGRAL DE GESTION ACADEMICA\n");
        printf("===============================================\n");
        printf("1. Verificacion y grados\n");
        printf("2. Control de flujo con bucles\n");
        printf("3. Registro de notas con vector\n");
        printf("4. Calificaciones con matriz\n");
        printf("5. Manejo de cadenas de texto\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                moduloVerificacion();
                break;
            case 2:
                moduloControlFlujo();
                break;
            case 3:
                moduloVector();
                break;
            case 4:
                moduloMatriz();
                break;
            case 5:
                moduloCadenas();
                break;
            case 0:
                printf("\nPrograma finalizado correctamente.\n");
                break;
            default:
                printf("\nOpcion no valida. Intente nuevamente.\n");
        }
    } while (opcion != 0);

    return 0;
}

void moduloVerificacion(void) {
    int edad;
    float nota;
    char letra;

    printf("\n--- MODULO 1: VERIFICACION Y GRADOS ---\n");
    printf("Ingrese la edad del estudiante: ");
    scanf("%d", &edad);
    printf("Ingrese la nota final (0-100): ");
    scanf("%f", &nota);

    if (edad >= 18) {
        printf("Categoria por edad: estudiante mayor de edad.\n");
    } else {
        printf("Categoria por edad: estudiante menor de edad.\n");
    }

    printf("Estado academico: %s\n", nota >= 60 ? "APROBADO" : "REPROBADO");

    if (nota >= 90) letra = 'A';
    else if (nota >= 80) letra = 'B';
    else if (nota >= 70) letra = 'C';
    else letra = 'D';

    printf("Categoria asignada: %c\n", letra);

    switch (letra) {
        case 'A':
            printf("Excelente rendimiento academico.\n");
            break;
        case 'B':
            printf("Muy buen rendimiento academico.\n");
            break;
        case 'C':
            printf("Rendimiento satisfactorio.\n");
            break;
        default:
            printf("Debe mejorar su rendimiento academico.\n");
    }
}

void moduloControlFlujo(void) {
    float nota;
    int contador = 0;
    float suma = 0.0f;

    printf("\n--- MODULO 2: CONTROL DE FLUJO ---\n");
    printf("Ingrese notas entre 0 y 100. Use -1 para terminar.\n");

    while (contador < 10) {
        printf("Nota %d: ", contador + 1);
        scanf("%f", &nota);

        if (nota == -1) {
            break;
        }

        if (nota < 0 || nota > 100) {
            printf("Valor fuera de rango. Se descarta con continue.\n");
            continue;
        }

        suma += nota;
        contador++;
    }

    if (contador > 0) {
        printf("Notas validas registradas: %d\n", contador);
        printf("Promedio de notas validas: %.2f\n", suma / contador);
    } else {
        printf("No se registraron notas validas.\n");
    }
}

void moduloVector(void) {
    int notas[MAX_NOTAS];
    int i;
    int suma = 0;
    float promedio;

    printf("\n--- MODULO 3: VECTOR DE NOTAS ---\n");

    for (i = 0; i < MAX_NOTAS; i++) {
        do {
            printf("Ingrese la nota %d (0-100): ", i + 1);
            scanf("%d", &notas[i]);
            if (notas[i] < 0 || notas[i] > 100) {
                printf("Nota invalida. Debe estar entre 0 y 100.\n");
            }
        } while (notas[i] < 0 || notas[i] > 100);
    }

    for (i = 0; i < MAX_NOTAS; i++) {
        suma += notas[i];
    }

    promedio = (float)suma / MAX_NOTAS;

    printf("\nCalificaciones almacenadas: ");
    for (i = 0; i < MAX_NOTAS; i++) {
        printf("%d", notas[i]);
        if (i < MAX_NOTAS - 1) printf(", ");
    }
    printf("\nPromedio final: %.2f\n", promedio);
}

void moduloMatriz(void) {
    float notas_estudiantes[FILAS][COLUMNAS];
    int i, j;

    printf("\n--- MODULO 4: MATRIZ DE CALIFICACIONES ---\n");
    printf("3 estudiantes x 4 asignaturas\n");

    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            do {
                printf("Estudiante %d, asignatura %d: ", i + 1, j + 1);
                scanf("%f", &notas_estudiantes[i][j]);
                if (notas_estudiantes[i][j] < 0 || notas_estudiantes[i][j] > 100) {
                    printf("Valor invalido. Debe estar entre 0 y 100.\n");
                }
            } while (notas_estudiantes[i][j] < 0 || notas_estudiantes[i][j] > 100);
        }
    }

    printf("\nTABLA DE CALIFICACIONES\n");
    printf("            Asig.1  Asig.2  Asig.3  Asig.4\n");
    for (i = 0; i < FILAS; i++) {
        printf("Estudiante %d ", i + 1);
        for (j = 0; j < COLUMNAS; j++) {
            printf("%7.2f", notas_estudiantes[i][j]);
        }
        printf("\n");
    }
}

void moduloCadenas(void) {
    char nombre[50];
    char apellido[50];
    char nombreCompleto[110];
    char nombreComparacion[110];
    size_t longitud;

    printf("\n--- MODULO 5: CADENAS DE TEXTO ---\n");

    printf("Ingrese el nombre: ");
    scanf(" %49[^\n]", nombre);
    printf("Ingrese el apellido: ");
    scanf(" %49[^\n]", apellido);

    strcpy(nombreCompleto, nombre);
    strcat(nombreCompleto, " ");
    strcat(nombreCompleto, apellido);

    longitud = strlen(nombreCompleto);

    printf("Nombre completo: %s\n", nombreCompleto);
    printf("Longitud total: %zu caracteres\n", longitud);

    strcpy(nombreComparacion, nombreCompleto);

    if (strcmp(nombreCompleto, nombreComparacion) == 0) {
        printf("Validacion strcmp: los nombres coinciden.\n");
    } else {
        printf("Validacion strcmp: los nombres no coinciden.\n");
    }
}
