#include <stdlib.h>
#include "integracion.h"

// Generar número aleatorio en [min, max]
double random_range(double min, double max) {
    double scale = rand() / (double) RAND_MAX;
    return min + scale * (max - min);
}

void calcular_monte_carlo(FuncDensidad rho, Limites lim, int n_puntos,
                          double *masa, double *cm_x, double *cm_y, double *cm_z) {

    double sum_rho = 0.0;
    double sum_x_rho = 0.0;
    double sum_y_rho = 0.0;
    double sum_z_rho = 0.0;

    // Volumen de la región rectangular
    double volumen = (lim.x_max - lim.x_min) *
                     (lim.y_max - lim.y_min) *
                     (lim.z_max - lim.z_min);

    for (int i = 0; i < n_puntos; i++) {
        double rx = random_range(lim.x_min, lim.x_max);
        double ry = random_range(lim.y_min, lim.y_max);
        double rz = random_range(lim.z_min, lim.z_max);

        double val_rho = rho(rx, ry, rz);

        sum_rho   += val_rho;
        sum_x_rho += rx * val_rho;
        sum_y_rho += ry * val_rho;
        sum_z_rho += rz * val_rho;
    }

    *masa = volumen * (sum_rho / n_puntos);

    *cm_x = (volumen * (sum_x_rho / n_puntos)) / *masa;
    *cm_y = (volumen * (sum_y_rho / n_puntos)) / *masa;
    *cm_z = (volumen * (sum_z_rho / n_puntos)) / *masa;
}
