#include <iostream>

#include <cmath>



using namespace std;



void jacobiMethod(double a[10][10], double b[10], double x[10], int n, double tolerance) {

    double x_new[10];

    double error;

    int iteration = 0;



    // Initialize x_new with the initial guess (which is usually 0)

    for (int i = 0; i < n; i++) {

        x_new[i] = 0;

    }



    do {

        error = 0;



        for (int i = 0; i < n; i++) {

            double sum = b[i];



            // Sum over all terms a_ij * x_j where j != i

            for (int j = 0; j < n; j++) {

                if (i != j) {

                    sum -= a[i][j] * x[j];

                }

            }



            // Update the value of x[i] for this iteration

            x_new[i] = sum / a[i][i];



            // Calculate the maximum error

            error = max(error, fabs(x_new[i] - x[i]));

        }



        // Copy new values into x for the next iteration

        for (int i = 0; i < n; i++) {

            x[i] = x_new[i];

        }



        iteration++;

    } while (error > tolerance);  // Loop until the error is less than the tolerance



    cout << "Number of iterations: " << iteration << endl;

}



int main() {

    int n;

    double tolerance = 0.05;  // Error tolerance



    cout << "Enter the number of variables: ";

    cin >> n;



    double a[10][10], b[10], x[10];



    cout << "Enter the coefficients of the augmented matrix (a):" << endl;

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            cout << "a[" << i + 1 << "][" << j + 1 << "]: ";

            cin >> a[i][j];

        }

    }



    cout << "Enter the values for the right-hand side vector (b):" << endl;

    for (int i = 0; i < n; i++) {

        cout << "b[" << i + 1 << "]: ";

        cin >> b[i];

    }



    // Initialize the solution vector x with zeros (initial guess)

    for (int i = 0; i < n; i++) {

        x[i] = 0;

    }



    // Call the Jacobi method to solve the system

    jacobiMethod(a, b, x, n, tolerance);



    cout << "Solution:" << endl;

    for (int i = 0; i < n; i++) {

        cout << "x" << i + 1 << " = " << x[i] << endl;

    }



    return 0;

}

