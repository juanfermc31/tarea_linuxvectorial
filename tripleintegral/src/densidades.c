// =========================
// Archivo: densidades.c
// =========================
#include <math.h>
#include "densidades.h"


double densidad_constante(double x,double y,double z){
return 1.0;
}


double densidad_lineal(double x,double y,double z){
return x + y + z;
}


double densidad_gaussiana(double x,double y,double z){
return exp(-(x*x + y*y + z*z));
}


// Para centro de masa


double dens_x(double x,double y,double z){ return x * densidad_constante(x,y,z); }
double dens_y(double x,double y,double z){ return y * densidad_constante(x,y,z); }
double dens_z(double x,double y,double z){ return z * densidad_constante(x,y,z); }

