#include <iostream>

#include <cmath>



using namespace std;



void gaussElimination(double a[10][10], double b[10], double x[10], int n) {

    for (int i = 0; i < n; i++) {

        int max_row = i;

        for (int k = i + 1; k < n; k++) {

            if (fabs(a[k][i]) > fabs(a[max_row][i])) {

                max_row = k;

            }

        }

        for (int k = 0; k < n; k++) {

            swap(a[i][k], a[max_row][k]);

        }

        swap(b[i], b[max_row]);

        for (int j = i + 1; j < n; j++) {

            double ratio = a[j][i] / a[i][i];

            b[j] -= ratio * b[i];

            for (int k = i; k < n; k++) {

                a[j][k] -= ratio * a[i][k];

            }

        }

    }

    for (int i = n - 1; i >= 0; i--) {

        x[i] = b[i] / a[i][i];

        for (int j = i - 1; j >= 0; j--) {

            b[j] -= a[j][i] * x[i];

        }

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

    gaussElimination(a, b, x, n);

    cout << "Solution: " << endl;

    for (int i = 0; i < n; i++) {

        cout << "x" << i + 1 << " = " << x[i] << endl;

    }

    return 0;

}

