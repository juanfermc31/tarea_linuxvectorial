#ifndef DENSIDADES_H
#define DENSIDADES_H

// Declaración de funciones de densidad
// Se marca como inline para mejorar velocidad (opcional y seguro)

static inline double densidad_constante(double x, double y, double z);
static inline double densidad_lineal(double x, double y, double z);
static inline double densidad_gaussiana(double x, double y, double z);

#endif
