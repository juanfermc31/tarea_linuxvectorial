#include <math.h>
#include <stdlib.h>
#include "integracion.h"

// Método Riemann 3D
double riemann(double (*f)(double,double,double),
               double xmin, double xmax,
               double ymin, double ymax,
               double zmin, double zmax,
               int n) {

    double dx = (xmax - xmin) / n;
    double dy = (ymax - ymin) / n;
    double dz = (zmax - zmin) / n;

    double suma = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                double x = xmin + (i + 0.5) * dx;
                double y = ymin + (j + 0.5) * dy;
                double z = zmin + (k + 0.5) * dz;

                suma += f(x, y, z);
            }
        }
    }

    return suma * dx * dy * dz;
}

// Método Monte Carlo
double montecarlo(double (*f)(double,double,double),
                  double xmin, double xmax,
                  double ymin, double ymax,
                  double zmin, double zmax,
                  int N) {

    double V = (xmax - xmin) * (ymax - ymin) * (zmax - zmin);
    double suma = 0;

    for(int i = 0; i < N; i++) {
        double x = xmin + (double)rand()/RAND_MAX * (xmax - xmin);
        double y = ymin + (double)rand()/RAND_MAX * (ymax - ymin);
        double z = zmin + (double)rand()/RAND_MAX * (zmax - zmin);

        suma += f(x, y, z);
    }

    return V * (suma / N);
}

double integrar(int metodo, double (*f)(double,double,double),
                double xmin,double xmax,double ymin,double ymax,
                double zmin,double zmax,int n) {

    if (metodo == 1)
        return riemann(f, xmin, xmax, ymin, ymax, zmin, zmax, n);
    else
        return montecarlo(f, xmin, xmax, ymin, ymax, zmin, zmax, n);
}
