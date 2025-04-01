#include <iostream>

#include <cmath>

#include <iomanip>



using namespace std;



float fun(float x) {

    return sin(x / 2);

}



int main() {

    float lwr, upr;

    int n;



    // Input

    cout << "Enter the limits: " << endl;

    cout << "Lower limit: ";

    cin >> lwr;

    cout << "Upper limit: ";

    cin >> upr;

    cout << "Enter the number of subintervals: ";

    cin >> n;



    

    float h = (upr - lwr) / n;

    float I = fun(lwr) + fun(upr); 



    

    for (int i = 1; i < n; i++) {

        float x = lwr + i * h;

        I += 2 * fun(x);

    }



    I = (h / 2) * I; 



   

    cout << "The integration of sin(x/2) using Composite Trapezoidal Rule is "<< fixed << setprecision(4) << I << endl;



    return 0;

}

