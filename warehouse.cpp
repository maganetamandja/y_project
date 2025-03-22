// This program solves the KS equation

#include <iostream>
#include <ginac/ginac.h>

int main() {
    using namespace GiNaC;
    using namespace std;
    
    // Initialize GiNaC
    symbol x("x");
    
    // Create an expression
    ex expr = pow(x, 3) + 2 * pow(x, 2) - 5 * x + 3;
    
    // Differentiate with respect to x
    ex derivative = diff(expr, x);
    
    // Print the original expression and its derivative
    cout << "Original: " << expr << endl;
    cout << "Derivative: " << derivative << endl;
    
    // Second derivative
    ex second_derivative = diff(derivative, x);
    cout << "Second derivative: " << second_derivative << endl;

    return 0;
}