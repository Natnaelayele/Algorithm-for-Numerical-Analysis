//Bisection Method
#include <iostream>
#include <cmath>
using namespace std;
int counter=0;   //Here is Counter Global Variable for counting the iteration of the program that excute

// Equation f(x)=x^3-5x+3  

//first you should find root interval  for equation 

double f(double x) {
    return x * x * x - 5 * x + 3;
}
//Parameter a the negative root and b the positive root
//tolerance parameter is given in the equation that is optional so remove when the tolerance not given
 
double bisection(double a, double b, double tolerance) {
    double c = (a + b) / 2;
    while (abs(f(c)) > tolerance && abs(b - a) > tolerance) {
        if (f(a) * f(c) < 0) {
            b = c;
        } else {
            a = c;
        }
        c = (a + b) / 2;
        counter++;
    }
    return c;
}

int main() {
    double a = 0, b = 1, tolerance = 0.001;
    double root = bisection(a, b, tolerance);
    cout << "The root of x^3 - 5x + 3 = 0 in the interval [0,1] is: " << root << endl;
    cout<<"Equation Takes :"<<counter<<" Iteration ";
    return 0;
}

