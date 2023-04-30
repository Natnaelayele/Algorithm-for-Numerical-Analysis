#include <iostream>
#include <cmath>

using namespace std;
double f(double x) {
    return pow(x, 3) - pow(x, 2) - 1;
}

double false_position(double x1, double x2, double tolerance) {
    double f_x1 = f(x1);
    double f_x2 = f(x2);
    double x_new;
    
    while (abs(f_x2 - f_x1) > tolerance) {
        // Find the equation of the line passing through (x1, f_x1) and (x2, f_x2)
        double slope = (f_x2 - f_x1) / (x2 - x1);
        double y_intercept = f_x1 - slope * x1;
        
        // Find the x-intercept of the line
        x_new = -y_intercept / slope;
        
        // Check if the x-intercept is within the interval [x1, x2]
        if (x_new > x1 && x_new < x2) {
            double f_new = f(x_new);
            
            if (f_new == 0) {
                return x_new;
            } else if (f_new * f_x1 < 0) {
                x2 = x_new;
                f_x2 = f_new;
            } else {
                x1 = x_new;
                f_x1 = f_new;
            }
        } else {
            cout << "Error: x_new is not within the interval [x1, x2]." << endl;
            return NAN;
        }
    }
    
    return x_new;
    
}

int main() {
    double x1 = 1;
    double x2 = 2;
    double tolerance = 1e-4;
    
    double root = false_position(x1, x2, tolerance);
    
    if (!isnan(root)) {
        cout << "Approximate root: " << root << endl;
    }
    
    cout<<counter;
    return 0;
}

