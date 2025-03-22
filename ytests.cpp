// This program solves the KS equation

#include <iostream>
#include <ginac/ginac.h>

GiNaC::symbol x("x"); //set x as a symbol

//the laplacian represent the scalar multiplication born from taking the second derivative of the STO-3G function
double laplacian1_i(double a_i,double r){ //a_i is alpha_i and r is the distance from the nucleus

    return ((4*std::pow(a_i,2)*std::pow(r,2))-(2*a_i))
        
}

GiNaC::ex coulomb_numerator(GiNaC::ex sto_3g ){
    return std::pow(sto_3g,2);


}

double coulomb_i(GiNaC::ex varphi_j, double r12){
    

}

int main() {
    using namespace GiNaC;
    using namespace std;
    
    

    return 0;
}