#include <math.h>
#include "../include/densidades.h"

// 1. Densidad constante: rho = 1
double densidad_constante(double x, double y, double z) {
    return 1.0;
}

// 2. Densidad lineal: rho = ax + by + cz
// Usaremos coeficientes a=1, b=1, c=1 para el ejemplo
double densidad_lineal(double x, double y, double z) {
    return 1.0 * x + 1.0 * y + 1.0 * z;
}

// 3. Densidad gaussiana: rho = e^-(x^2 + y^2 + z^2)
double densidad_gaussiana(double x, double y, double z) {
    return exp(-(x*x + y*y + z*z));
}