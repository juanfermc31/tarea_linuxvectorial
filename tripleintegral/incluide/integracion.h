#ifndef INTEGRACION_H
#define INTEGRACION_H

// Estructura para límites del dominio
typedef struct {
    double x_min, x_max;
    double y_min, y_max;
    double z_min, z_max;
} Limites;

// Puntero a función para densidad (double -> double)
typedef double (*FuncDensidad)(double, double, double);

// Función principal Monte Carlo (debe permanecer igual)
void calcular_monte_carlo(
    FuncDensidad rho, 
    Limites lim, 
    int n_puntos,
    double *masa, 
    double *cm_x, 
    double *cm_y, 
    double *cm_z
);

#endif
