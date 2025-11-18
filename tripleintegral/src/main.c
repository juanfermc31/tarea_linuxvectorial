#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "integracion.h"
#include "densidades.h"

// Variables globales para densidad lineal
double ax = 1, by = 1, cz = 1;

int main() {
    double xmin, xmax, ymin, ymax, zmin, zmax;
    int metodo, dens, n;

    printf("--- Calculo de masa y centro de masa ---\n");

    printf("Ingrese xmin xmax: ");
    scanf("%lf %lf", &xmin, &xmax);

    printf("Ingrese ymin ymax: ");
    scanf("%lf %lf", &ymin, &ymax);

    printf("Ingrese zmin zmax: ");
    scanf("%lf %lf", &zmin, &zmax);

    printf("Metodo (1=Riemann, 2=Monte Carlo): ");
    scanf("%d", &metodo);

    printf("Densidad (1=constante, 2=lineal, 3=gaussiana): ");
    scanf("%d", &dens);

    if (dens == 2) {
        printf("Ingrese a, b, c para densidad lineal ax + by + cz: ");
        scanf("%lf %lf %lf", &ax, &by, &cz);
    }

    printf("Ingrese numero de subdivisiones/puntos: ");
    scanf("%d", &n);

    double (*rho)(double,double,double);
    if(dens == 1)
        rho = densidad_constante;
    else if(dens == 2)
        rho = densidad_lineal;
    else
        rho = densidad_gaussiana;

    clock_t start = clock();

    double M = integrar(metodo, rho, xmin, xmax, ymin, ymax, zmin, zmax, n);
    double xbar = integrar(metodo, dens_x, xmin, xmax, ymin, ymax, zmin, zmax, n) / M;
    double ybar = integrar(metodo, dens_y, xmin, xmax, ymin, ymax, zmin, zmax, n) / M;
    double zbar = integrar(metodo, dens_z, xmin, xmax, ymin, ymax, zmin, zmax, n) / M;

    clock_t end = clock();
    double tiempo = (double)(end - start) / CLOCKS_PER_SEC;

    FILE *f = fopen("resultado.csv", "w");
    if (!f) {
        perror("fopen");
    } else {
        fprintf(f, "Metodo,Densidad,N,M,x_bar,y_bar,z_bar,Tiempo\n");
        fprintf(f, "%d,%d,%d,%lf,%lf,%lf,%lf,%lf\n",
            metodo, dens, n, M, xbar, ybar, zbar, tiempo);
        fclose(f);
    }

    printf("\nResultados:\n");
    printf("Masa: %lf\n", M);
    printf("Centro de masa: (%lf, %lf, %lf)\n", xbar, ybar, zbar);
    printf("Tiempo: %lf s\n", tiempo);

    return 0;
}
