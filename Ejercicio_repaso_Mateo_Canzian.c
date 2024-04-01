#include <stdio.h>
#define CANT_EMPLEADOS 4
#define CANT_MAX_LETRAS 50

typedef struct {
    char nombre[CANT_MAX_LETRAS];
    int edad;
    float salario; 
} empleado;

void MOSTRAR_OPCIONES(void);
void INGRESAR_DATOS(empleado [], int);
void PROCESAR_DATOS(empleado [], int);
void MOSTRAR_DATOS(empleado [], int);

int main(void) {
    int empleados_ingresados = 0;
    empleado persona[CANT_EMPLEADOS];
    int c = 0;
    for (c = 0; c<CANT_EMPLEADOS; c++)
        persona[c].edad = 0;
        persona[c].salario = 0; 
        
    int opcionElegida;
    do {
        MOSTRAR_OPCIONES();
        scanf("%i", &opcionElegida);
        while (opcionElegida != 1 && opcionElegida != 2 && opcionElegida != 3) {
            printf("Debes elegir entre las opciónes 1, 2, 3\n");
            printf("Opción elegida: ");
            scanf("%i", &opcionElegida);
        }
        switch (opcionElegida) {
            case 1:
                INGRESAR_DATOS(persona, empleados_ingresados);
                empleados_ingresados++;
                printf("\nIngresaste correctamente al empleado. Actualmente hay %d de 5 empleados ingresados.\n", empleados_ingresados);
                break;
                
            case 2:
                MOSTRAR_DATOS(persona, empleados_ingresados);
                PROCESAR_DATOS(persona, empleados_ingresados);
                break;
        }

    } while (opcionElegida != 3);
    return 0;
}

void MOSTRAR_OPCIONES(void) {
    printf("Menu:\n");
    printf("1: Escribi los datos de un empleado\n");
    printf("2: Mostrar los datos y procesar la info\n");
    printf("3: Salir del programa\n");
    printf("Opción elegida: ");
}

void INGRESAR_DATOS(empleado persona[], int empleados_ingresados) {
    printf("\nEscribi el nombre del empleado: ");
    scanf("%s", persona[empleados_ingresados].nombre);
    printf("Escribir la edad del empleado: ");
    scanf("%d", &persona[empleados_ingresados].edad);
    printf("Escribi el salario del empleado: ");
    scanf("%f", &persona[empleados_ingresados].salario);
}

void PROCESAR_DATOS(empleado persona[], int empleados_ingresados) {
    unsigned int promedio = 0;
    unsigned int maximo = 0;
    int maximo_empleados;
    for (int a = 0; a < empleados_ingresados; a++) {
        if (persona[a].salario > persona[maximo].salario) {
            maximo = persona[a].salario;
            maximo_empleados=a;
        }
        promedio += persona[a].salario;
    }
    promedio /= empleados_ingresados;
    printf("\nDatos:\n%s tiene el mayor salario con: %f\n", persona[maximo].nombre, persona[maximo].salario);
    printf("El promedio de los salarios de todos los empleados es de: %u\n\n", promedio);
}

void MOSTRAR_DATOS(empleado persona[], int empleados_ingresados) {
    printf("\nEmpleados ingresados:");
    for (int b = 0; b < empleados_ingresados; b++) {
        printf("\n%i. Nombre: %s, Edad: %d, Salario: %f", b+1, persona[b].nombre, persona[b].edad, persona[b].salario);
    }
}