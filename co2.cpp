#include "y_functions.h"
#include <iostream>
#include <math.h>

//known constants
double ROC =2.2620020083; //distance between the two atoms
double Zc = 6; //atomic number of carbon
double Zo = 8; //atomic number of oxigen
//guassian exponent values for carbon
double c_a1 = 71.61683735;
double c_a2 = 13.04509632;
double c_a3 = 3.53051216;

//contraction coefficient values for carbon
double c_c1 = 0.1543289673;
double c_c2 = 0.5353281423;
double c_c3 = 0.4446345422;

//guassian integral values for oxigen
double o_a1 = 130.7093200;
double o_a2 = 23.80886605;
double o_a3 = 6.443608313;

//contraction coefficient values for oxigen
double o_c1 = 0.1543289673;
double o_c2 = 0.5353281423;
double o_c3 = 0.4446345422;



//Laplacian matrix element values for carbon
c_Lap_1 = y_feta(-1, c_a1)*y_gaussian_integral(c_a1, c_a1);
c_Lap_2 = y_feta(-1, c_a2)*y_gaussian_integral(c_a2, c_a2);
c_Lap_3 = y_feta(-1, c_a3)*y_gaussian_integral(c_a3, c_a3);

//construct the QC
double QC = (((y_feta(c_c1, c_a1))^2)*y_gaussian_integral(c_a1,c_a1) )+
            (2*y_feta(c_c2, c_a2)*y_feta(c_c1, c_a1))*y_gaussian_integral(c_a2,c_a1)+
            (2*y_feta(c_c3, c_a3)*y_feta(c_c1, c_a1))*y_gaussian_integral(c_a3,c_a1)+
            (((y_feta(c_c2, c_a2))^2)*y_gaussian_integral(c_a2,c_a2))+
            (((y_feta(c_c3, c_a3))^2)*y_gaussian_integral(c_a3,c_a3))+
            (2*y_feta(c_c2, c_a2)*y_feta(c_c3, c_a3))*y_gaussian_integral(c_a2,c_a3);

//construct the QO
double QO = (((y_feta(o_c1, o_a1))^2)*y_gaussian_integral(o_a1,o_a1) )+
            (2*y_feta(o_c2, o_a2)*y_feta(o_c1, o_a1))*y_gaussian_integral(o_a2,o_a1)+
            (2*y_feta(o_c3, o_a3)*y_feta(o_c1, o_a1))*y_gaussian_integral(o_a3,o_a1)+
            (((y_feta(o_c2, o_a2))^2)*y_gaussian_integral(o_a2,o_a2))+
            (((y_feta(o_c3, o_a3))^2)*y_gaussian_integral(o_a3,o_a3))+
            (2*y_feta(o_c2, o_a2)*y_feta(o_c3, o_a3))*y_gaussian_integral(o_a2,o_a3);

//calculate the coulomb interaction
double coulomb_interaction = y_coulomb_interaction(QC, QO, ROC);

//bhor radius of the 3 atoms
double rs[] = {3.2125341806,2.8723835026,3.2125341806};

double r_s[] = {0.340150678,0.340150678};

//calculate volume of the system

//overall volume of the system
double volume_total = y_volumes(rs);

//correction volume 
double volume_correction = y_volumes(r_s);

double volume = volume_total - volume_correction;

//calculate the density of the system
double density = (6+8+8)/volume;

//calculate the exchange potential
double exchange_potential = y_exchange_potential(density);

//ccalculate the nuclear attraction term

double r1c = (3/4)*3.2125341806;
double r1o = (3/4)*2.8723835026;

double ena_potential = 2*(ena(6,r1c)) + ena(8,r1o);


