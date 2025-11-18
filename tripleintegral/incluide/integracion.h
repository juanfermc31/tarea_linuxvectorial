#ifndef INTEGRACION_H
#define INTEGRACION_H

// Estructura para definir los límites de la región rectangular
typedef struct {
    double x_min, x_max;
    double y_min, y_max;
    double z_min, z_max;
} Limites;

// Puntero a función para pasar la densidad como argumento
typedef double (*FuncDensidad)(double, double, double);

// Función principal que calcula Masa y Centro de Masa por Monte Carlo
void calcular_monte_carlo(FuncDensidad rho, Limites lim, int n_puntos,
                          double *masa, double *cm_x, double *cm_y, double *cm_z);

#endif
