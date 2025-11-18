#include <stdlib.h>
#include "integracion.h"

// Versión optimizada de Monte Carlo sin cambiar nada de la estructura original
void calcular_monte_carlo(FuncDensidad rho, Limites lim, int n_puntos,
                          double *masa, double *cm_x, double *cm_y, double *cm_z) {

    double sum_rho = 0.0;
    double sum_x_rho = 0.0;
    double sum_y_rho = 0.0;
    double sum_z_rho = 0.0;

    // Guardar longitudes del dominio (más rápido que recalcular en cada iteración)
    double dx = lim.x_max - lim.x_min;
    double dy = lim.y_max - lim.y_min;
    double dz = lim.z_max - lim.z_min;

    // Volumen del prisma
    double volumen = dx * dy * dz;

    // Factor para evitar división repetida (1 / RAND_MAX)
    const double inv_rand = 1.0 / (double) RAND_MAX;

    for (int i = 0; i < n_puntos; i++) {

        // Generación rápida de aleatorios con menor costo
        double rx = lim.x_min + ((double)rand() * inv_rand) * dx;
        double ry = lim.y_min + ((double)rand() * inv_rand) * dy;
        double rz = lim.z_min + ((double)rand() * inv_rand) * dz;

        // Evaluar densidad
        double val_rho = rho(rx, ry, rz);

        // Acumulación
        sum_rho   += val_rho;
        sum_x_rho += rx * val_rho;
        sum_y_rho += ry * val_rho;
        sum_z_rho += rz * val_rho;
    }

    // Masa aproximada
    *masa = volumen * (sum_rho / n_puntos);

    // Centro de masa
    *cm_x = (volumen * (sum_x_rho / n_puntos)) / *masa;
    *cm_y = (volumen * (sum_y_rho / n_puntos)) / *masa;
    *cm_z = (volumen * (sum_z_rho / n_puntos)) / *masa;
}
