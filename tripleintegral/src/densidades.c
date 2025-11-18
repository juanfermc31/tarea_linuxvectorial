#include <math.h>
#include "../include/densidades.h"

// 1. Densidad constante: rho = 1
static inline double densidad_constante(double x, double y, double z) {
    return 1.0;
}

// 2. Densidad lineal: rho = x + y + z
// Optimización: se elimina multiplicación innecesaria
static inline double densidad_lineal(double x, double y, double z) {
    return x + y + z;
}

// 3. Densidad gaussiana: rho = exp(-(x^2 + y^2 + z^2))
static inline double densidad_gaussiana(double x, double y, double z) {
    double r2 = x*x + y*y + z*z;   // Guardar para evitar recomputación
    return exp(-r2);
}
