#include <iostream>

#include <cmath>

using namespace std;



double gaussIntegration(int n, double (*f)(double)) {

    double result = 0.0;

    

    if (n == 2) {

        double x1 = -1.0 / sqrt(3);

        double x2 = 1.0 / sqrt(3);

        double w1 = 1.0;

        double w2 = 1.0;

        

        result = 0.5 * (w1 * f(x1) + w2 * f(x2));

    } 

    else if (n == 3) {

        double x1 = -sqrt(3.0 / 5.0);

        double x2 = 0.0;

        double x3 = sqrt(3.0 / 5.0);

        double w1 = 5.0 / 9.0;

        double w2 = 8.0 / 9.0;

        double w3 = 5.0 / 9.0;

        

        result = (x2 - x1) / 2.0 * (w1 * f(x1) + w2 * f(x2) + w3 * f(x3));

    }



    return result;

}



double function(double x) {

    return x * x;  

}



int main() {

    cout << "Gauss Integration for n=2: " << gaussIntegration(2, function) << endl;

    cout << "Gauss Integration for n=3: " << gaussIntegration(3, function) << endl;



    return 0;

}

