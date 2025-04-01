#include <iostream>

#include <cmath>

using namespace std;



double function(double x) {

    return sin(x / 2);  

}



double trapezoidalRule(double (*f)(double), double a, double b, int n) {

    double h = (b - a) / n;

    double sum = 0.5 * (f(a) + f(b));

    

    for (int i = 1; i < n; ++i) {

        sum += f(a + i * h);

    }

    

    return h * sum;

}



double rombergIntegration(double (*f)(double), double a, double b, int maxIter) {

    double R[maxIter][maxIter];  

    for (int i = 0; i < maxIter; ++i) {

        int n = pow(2, i);

        R[i][0] = trapezoidalRule(f, a, b, n);

        

        for (int j = 1; j <= i; ++j) {

            R[i][j] = (pow(4, j) * R[i][j - 1] - R[i - 1][j - 1]) / (pow(4, j) - 1);

        }

    }

    

    return R[maxIter - 1][maxIter - 1]; 

}



int main() {

    double a, b;

    int maxIter;



    

    cout << "Enter the lower limit of integration: ";

    cin >> a;

    cout << "Enter the upper limit of integration: ";

    cin >> b;

    cout << "Enter the number of iterations for Romberg integration: ";

    cin >> maxIter;

    

    double result = rombergIntegration(function, a, b, maxIter);

    

    cout << "Romberg Integration result: " << result << endl;

    

    return 0;

}

