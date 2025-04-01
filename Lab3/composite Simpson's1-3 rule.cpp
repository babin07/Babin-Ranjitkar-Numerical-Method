#include <iostream>

#include <cmath>

#include <iomanip>



using namespace std;



float fun(float x) {

    return sin(x / 2);  

}



int main() {

    float lwr, upr, h, I;

    int n;



   

    cout << "Enter the limits: " << endl;

    cout << "Lower limit: ";

    cin >> lwr;

    cout << "Upper limit: ";

    cin >> upr;

    cout << "Enter the number of subintervals (must be even): ";

    cin >> n;



    

    if (n % 2 != 0) {

        cout << "Error: Number of subintervals must be even!" << endl;

        return 1;

    }



    h = (upr - lwr) / n;

    I = fun(lwr) + fun(upr); 



   

    for (int i = 1; i < n; i++) {

        float x = lwr + i * h;

        if (i % 2 == 0) {

            I += 2 * fun(x);

        } else {

            I += 4 * fun(x);

        }

    }



    I = (h / 3.0) * I; 



   

    cout << "The integration of sin(x/2) using Composite Simpson's 1/3 Rule is "

         << fixed << setprecision(4) << I << endl;



    return 0;

}

