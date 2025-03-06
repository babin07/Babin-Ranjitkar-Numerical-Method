#include <iostream>

#include <cmath>



using namespace std;



void powerMethod(double a[10][10], int n, double tolerance) {

    double x[10] = {1};  // Initial vector (can be anything, here it's set to 1)

    double x_new[10];  // To store new vector

    double lambda_old = 0.0, lambda_new = 0.0;

    double error;



    // Perform iterations

    int iteration = 0;



    do {

        // Multiply matrix a by vector x

        for (int i = 0; i < n; i++) {

            x_new[i] = 0;

            for (int j = 0; j < n; j++) {

                x_new[i] += a[i][j] * x[j];

            }

        }



        // Find the largest absolute value in the new vector

        lambda_new = fabs(x_new[0]);

        for (int i = 1; i < n; i++) {

            if (fabs(x_new[i]) > lambda_new) {

                lambda_new = fabs(x_new[i]);

            }

        }



        // Normalize the new vector by dividing by the largest element

        for (int i = 0; i < n; i++) {

            x_new[i] /= lambda_new;

        }



        // Compute error as the difference between old and new eigenvalues

        error = fabs(lambda_new - lambda_old);

        lambda_old = lambda_new;



        // Copy the new vector into x for the next iteration

        for (int i = 0; i < n; i++) {

            x[i] = x_new[i];

        }



        iteration++;



    } while (error > tolerance);  // Continue until error is less than tolerance



    // Output the results

    cout << "Dominant Eigenvalue: " << lambda_new << endl;

    cout << "Corresponding Eigenvector:" << endl;

    for (int i = 0; i < n; i++) {

        cout << "x" << i + 1 << " = " << x[i] << endl;

    }

    cout << "Number of iterations: " << iteration << endl;

}



int main() {

    int n;

    double tolerance = 0.0001;  // Error tolerance for convergence



    cout << "Enter the size of the matrix (n x n): ";

    cin >> n;



    double a[10][10];



    cout << "Enter the elements of the matrix:" << endl;

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            cout << "a[" << i + 1 << "][" << j + 1 << "]: ";

            cin >> a[i][j];

        }

    }



    // Call the Power Method to find the eigenvalue and eigenvector

    powerMethod(a, n, tolerance);



    return 0;

}

