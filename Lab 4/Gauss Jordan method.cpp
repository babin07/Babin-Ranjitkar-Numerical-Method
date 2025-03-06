#include <iostream>

#include <cmath>



using namespace std;



void gaussJordan(double a[10][10], double b[10], double x[10], int n) {

    double augmented[10][10]; // Augmented matrix (a|b)



    // Creating the augmented matrix

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            augmented[i][j] = a[i][j];

        }

        augmented[i][n] = b[i];

    }



    // Applying Gauss-Jordan Elimination

    for (int i = 0; i < n; i++) {

        // Make the diagonal element 1 by dividing the row by the diagonal element

        double diagElement = augmented[i][i];

        for (int j = 0; j <= n; j++) {

            augmented[i][j] /= diagElement;

        }



        // Make all elements in the current column except for the diagonal 0

        for (int j = 0; j < n; j++) {

            if (i != j) {

                double ratio = augmented[j][i];

                for (int k = 0; k <= n; k++) {

                    augmented[j][k] -= ratio * augmented[i][k];

                }

            }

        }

    }



    // Extracting the solution

    for (int i = 0; i < n; i++) {

        x[i] = augmented[i][n];

    }

}



int main() {

    int n;

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



    gaussJordan(a, b, x, n);



    cout << "Solution: " << endl;

    for (int i = 0; i < n; i++) {

        cout << "x" << i + 1 << " = " << x[i] << endl;

    }



    return 0;

}

