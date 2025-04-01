#include<iostream>

#include<math.h>

#include<iomanip>

using namespace std;





float fun(float x) {

    return sin(x / 2);

}





float compositeSimpsons38(float lwr, float upr, int n) {

   

    if (n % 3 != 0) {

        cout << "n must be a multiple of 3." << endl;

        return -1;

    }



    float h = (upr - lwr) / n; 

    float sum = fun(lwr) + fun(upr);



   

    for (int i = 1; i < n; i++) {

        if (i % 3 == 0) {

            sum += 2 * fun(lwr + i * h);  

        } else {

            sum += 3 * fun(lwr + i * h);  

        }

    }



    return (3 * h / 8) * sum;

}



int main() {

    float lwr, upr;

    int n;



    cout << "Enter the limits:" << endl;

    cout << "Lower limit: ";

    cin >> lwr;

    cout << "Upper limit: ";

    cin >> upr;

    cout << "Enter the number of subintervals (must be a multiple of 3): ";

    cin >> n;



    

    float result = compositeSimpsons38(lwr, upr, n);



    if (result != -1) {

        cout << "The integration of sin(x/2) by using Composite Simpson's 3/8 rule is " << fixed << setprecision(4) << result << endl;

    }



    return 0;

}



