#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/densidades.h"
#include "../include/integracion.h"

int main() {

    // Semilla rápida
    srand((unsigned) time(NULL));

    Limites lim;
    int opcion = 0, n_puntos = 0;
    FuncDensidad funcion_seleccionada = NULL;
    const char *nombre_densidad = "N/A";

    printf("--- Calculadora de Centro de Masa (Monte Carlo) ---\n");

    // Entradas del usuario
    printf("Ingrese limites X (min max): ");
    scanf("%lf %lf", &lim.x_min, &lim.x_max);

    printf("Ingrese limites Y (min max): ");
    scanf("%lf %lf", &lim.y_min, &lim.y_max);

    printf("Ingrese limites Z (min max): ");
    scanf("%lf %lf", &lim.z_min, &lim.z_max);

    printf("Numero de muestras (N): ");
    scanf("%d", &n_puntos);

    printf("\nSeleccione densidad:\n");
    printf("1. Constante\n");
    printf("2. Lineal (x+y+z)\n");
    printf("3. Gaussiana\n");
    printf("Opcion: ");
    scanf("%d", &opcion);

    // Selección de densidad (rápida y segura)
    switch (opcion) {
        case 1:
            funcion_seleccionada = densidad_constante;
            nombre_densidad = "Constante";
            break;
        case 2:
            funcion_seleccionada = densidad_lineal;
            nombre_densidad = "Lineal";
            break;
        case 3:
            funcion_seleccionada = densidad_gaussiana;
            nombre_densidad = "Gaussiana";
            break;
        default:
            printf("Opción inválida.\n");
            return 1;
    }

    // Variables para resultados
    double M = 0.0, cx = 0.0, cy = 0.0, cz = 0.0;

    // Medición de tiempo
    clock_t start = clock();

    calcular_monte_carlo(funcion_seleccionada, lim, n_puntos, &M, &cx, &cy, &cz);

    double tiempo_seg = (double)(clock() - start) / CLOCKS_PER_SEC;

    // Mostrar resultados
    printf("\n--- Resultados ---\n");
    printf("Masa Total: %.6f\n", M);
    printf("Centro de Masa: (%.6f, %.6f, %.6f)\n", cx, cy, cz);
    printf("Tiempo: %.6f segundos\n", tiempo_seg);

    // Guardar en CSV
    FILE *fp = fopen("resultados.csv", "a");
    if (!fp) {
        printf("Error al abrir 'resultados.csv'\n");
        return 1;
    }

    fprintf(fp, "MonteCarlo,%s,%d,%d,%d,%.6f,%.6f,%.6f,%.6f,%.6f\n",
            nombre_densidad,
            n_puntos, n_puntos, n_puntos,
            M, cx, cy, cz, tiempo_seg);

    fclose(fp);

    printf("Datos guardados en 'resultados.csv'\n");

    return 0;
}
