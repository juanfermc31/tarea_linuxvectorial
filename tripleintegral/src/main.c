#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/densidades.h"
#include "../include/integracion.h"

int main() {
    // Semilla para números aleatorios [cite: 19]
    srand(time(NULL));

    Limites lim;
    int opcion, n_puntos;
    FuncDensidad funcion_seleccionada;
    char *nombre_densidad;

    // Interacción con el usuario [cite: 15]
    printf("--- Calculadora de Centro de Masa (Monte Carlo) ---\n");
    printf("Ingrese limites X (min max): "); scanf("%lf %lf", &lim.x_min, &lim.x_max);
    printf("Ingrese limites Y (min max): "); scanf("%lf %lf", &lim.y_min, &lim.y_max);
    printf("Ingrese limites Z (min max): "); scanf("%lf %lf", &lim.z_min, &lim.z_max);
    printf("Numero de muestras (N): "); scanf("%d", &n_puntos);

    printf("\nSeleccione densidad:\n1. Constante (1)\n2. Lineal (x+y+z)\n3. Gaussiana\nOpcion: ");
    scanf("%d", &opcion);

    switch(opcion) {
        case 1: funcion_seleccionada = densidad_constante; nombre_densidad = "Constante"; break;
        case 2: funcion_seleccionada = densidad_lineal; nombre_densidad = "Lineal"; break;
        case 3: funcion_seleccionada = densidad_gaussiana; nombre_densidad = "Gaussiana"; break;
        default: printf("Opcion invalida.\n"); return 1;
    }

    // Variables para resultados
    double M, cx, cy, cz;

    // Medición de tiempo [cite: 30, 31]
    clock_t start = clock();

    calcular_monte_carlo(funcion_seleccionada, lim, n_puntos, &M, &cx, &cy, &cz);

    clock_t end = clock();
    double tiempo_seg = (double)(end - start) / CLOCKS_PER_SEC;

    // Mostrar resultados en consola
    printf("\n--- Resultados ---\n");
    printf("Masa Total: %f\n", M);
    printf("Centro de Masa: (%f, %f, %f)\n", cx, cy, cz);
    printf("Tiempo: %f segundos\n", tiempo_seg);

    // Guardar en CSV [cite: 16, 29]
    FILE *fp = fopen("resultados.csv", "a"); // "a" para agregar al final sin borrar
    if (fp == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    // Formato: Metodo, Densidad, Nx, Ny, Nz, M, x_bar, y_bar, z_bar, Tiempo
    // Nota: En Monte Carlo Nx, Ny, Nz son el mismo N total.
    fprintf(fp, "MonteCarlo,%s,%d,%d,%d,%.6f,%.6f,%.6f,%.6f,%.6f\n",
            nombre_densidad, n_puntos, n_puntos, n_puntos, M, cx, cy, cz, tiempo_seg);

    fclose(fp);
    printf("Datos guardados en 'resultados.csv'\n");

    return 0;
}