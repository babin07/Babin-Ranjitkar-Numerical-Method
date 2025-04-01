#include <iostream>

#include <cmath>

#include <iomanip>



using namespace std;



float fun(float x) {

    return sin(x / 2);  

}



int main() {

    float I, h, lwr, upr,x1;

    

	cout << "Enter the limit: "<<endl;

    cout<<"lower limit: ";

    cin >> lwr ;

	cout<<"upper limit: ";

	cin>> upr;

	

	 h = (upr - lwr) / 2.0;

    x1 = lwr + h;  

		I = (h / 3.0) * (fun(lwr) + 4 * fun(x1) + fun(upr));

	cout << "The integration of  sin(x/2) by using Simpson's 1/3 rule is " << fixed << setprecision(4) <<I << endl;



    return 0;

}

