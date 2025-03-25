#include <iostream>
#include <math.h>

//array of atoms of the system


double y_laplacian_factor(double a, double r){ //single component of the laplacian matrix element. There are 3
    return -0.5*(4*a*r^2 - 2*a)
}

double y_coulomb(double feta_1, double feta_2, double feta_3, //this is also used in the exchange potential
                    double gi1, double gi2, double gi3, double gi4, double gi5){
    return (((feta_1^2)*gi1)+(2*feta_2*feta_1*gi2)+(2*feta_3*feta_1*gi2)+
            ((feta_2^2)*gi3)+((feta_3^2)*gi4)+(2*feta_2*feta_3*gi5));
}

double y_feta(double c , double a){
    return c*((2*a)/M_PI)^(3/4);
}

double y_gaussian_integral(double a, double b){
    return sqrt(M_PI/(a+b));
}

double y_volumes(double rs[]){
    double solution = 0;
    for (int i=0; i < sizeof(rs); i++){
        solution = solution + (4/3)*M_1_PI*(rs[i])^3
    }
    return solution;
}


//orbital calculator

int y_orbital(int n){ // n is the number of electron 

    int solution = 0;
    if (n%2 ==0){
        solution = n/2
    }
    else{
        solution = (n/2)+1
    }

}

//electron-nuclear attraction
double ena(double za, double r1a){
    return za/r1a
} 

double y_ena(int zs[], double r1a){ //complete electron-nuclear attraction
    double sum = 0;
    for(int i = 0; i < sizeof(zs); i++){
        sum += ena(zs[i], r1a);
    }
    return -sum;
}

//Exchange-correlation potential.
double y_exchange_potential(double av_density){
    return -(3/4)*((3/M_1_PI)^(1/3))*(av_density^(1/3))
}

//evaluate the coulomb interaction between two electrons
double y_coulomb_interaction(double QA, double QB, double RAB){
    return (QA*QB)/RAB;

}