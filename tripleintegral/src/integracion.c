#include <stdlib.h>
#include "../include/integracion.h"

// Función auxiliar para generar un double aleatorio entre min y max [cite: 19]
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

    // Volumen de la región rectangular V = Lx * Ly * Lz [cite: 18]
    double volumen = (lim.x_max - lim.x_min) * (lim.y_max - lim.y_min) * (lim.z_max - lim.z_min);

    for (int i = 0; i < n_puntos; i++) {
        // Generar punto aleatorio (xi, yi, zi) dentro de los límites [cite: 13]
        double rx = random_range(lim.x_min, lim.x_max);
        double ry = random_range(lim.y_min, lim.y_max);
        double rz = random_range(lim.z_min, lim.z_max);

        // Evaluar la densidad en ese punto
        double val_rho = rho(rx, ry, rz);

        // Acumular sumas para Masa y Momentos
        sum_rho   += val_rho;
        sum_x_rho += rx * val_rho;
        sum_y_rho += ry * val_rho;
        sum_z_rho += rz * val_rho;
    }

    // Aplicar teorema del promedio de Monte Carlo: Integral approx V * (Suma / N) [cite: 18]
    *masa = volumen * (sum_rho / n_puntos);

    // Centro de masa: (Integral x*rho) / Masa [cite: 5]
    // Calculamos primero la integral del momento y dividimos por la masa al final
    *cm_x = (volumen * (sum_x_rho / n_puntos)) / *masa;
    *cm_y = (volumen * (sum_y_rho / n_puntos)) / *masa;
    *cm_z = (volumen * (sum_z_rho / n_puntos)) / *masa;
}