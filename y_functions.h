#ifndef Y_FUNCTION_H
#define Y_FUNCTION_H

double y_laplacian_factor(double a, double r);
double y_coulomb(double feta_1, double feta_2, double feta_3, double gi1, double gi2, double gi3, double gi4, double gi5);
double y_feta(double c , double a);
double y_gaussian_integral(double a, double b);
double y_volumes(double rs[]);
int y_orbital(int n);
double ena(double za, double r1a);
double y_ena(int zs[], double r1a);
double y_exchange_potential(double av_density);
double y_coulomb_interaction( double QA, double QB, double RAB);

#endif