#include <iostream>

#include <cmath>

using namespace std;



double function(double x, double y) {

    return x + pow(y, 2);

}



double trapezoidalRule2D(double (*f)(double, double), double x_min, double x_max, double y_min, double y_max, int nx, int ny) {

    double hx = (x_max - x_min) / nx;

    double hy = (y_max - y_min) / ny;

    double sum = 0.0;



    for (int i = 0; i <= nx; ++i) {

        for (int j = 0; j <= ny; ++j) {

            double x = x_min + i * hx;

            double y = y_min + j * hy;

            if (i == 0 || i == nx) {

                if (j == 0 || j == ny) {

                    sum += f(x, y);

                }

                else {

                    sum += 2 * f(x, y);

                }

            } else {

                if (j == 0 || j == ny) {

                    sum += 2 * f(x, y);

                } else {

                    sum += 4 * f(x, y);

                }

            }

        }

    }

    

    return hx * hy / 4.0 * sum;

}



int main() {

    double x_min, x_max, y_min, y_max;

    int nx, ny;



    cout << "Enter the lower limit for x: ";

    cin >> x_min;

    cout << "Enter the upper limit for x: ";

    cin >> x_max;

    cout << "Enter the lower limit for y: ";

    cin >> y_min;

    cout << "Enter the upper limit for y: ";

    cin >> y_max;

    cout << "Enter the number of intervals for x: ";

    cin >> nx;

    cout << "Enter the number of intervals for y: ";

    cin >> ny;

    

    double result = trapezoidalRule2D(function, x_min, x_max, y_min, y_max, nx, ny);

    

    cout << "Double integration result using Trapezoidal rule: " << result << endl;

    

    return 0;

}

