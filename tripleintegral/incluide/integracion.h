// =========================
// Archivo: integracion.h
// =========================
#ifndef INTEGRACION_H
#define INTEGRACION_H


double riemann(double (*f)(double,double,double), double xmin,double xmax,
double ymin,double ymax,double zmin,double zmax,int n);


double montecarlo(double (*f)(double,double,double), double xmin,double xmax,
double ymin,double ymax,double zmin,double zmax,int N);


double integrar(int metodo, double (*f)(double,double,double),
double xmin,double xmax,double ymin,double ymax,
double zmin,double zmax,int n);


#endif