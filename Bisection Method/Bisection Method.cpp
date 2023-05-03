#include <iostream>
#include <cmath>
using namespace std;
int counter=0;  

double f(double x) {
    return x * x * x - 5 * x + 3;
}
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

