#include<iostream>

#include<math.h>

#include<iomanip>

using namespace std;



float fun(float x){

	

	return sin(x/2);

}



int main(){

		float I, lwr,upr;

		

		cout << "Enter the limit: "<<endl;

    cout<<"lower limit: ";

    cin >> lwr ;

	cout<<"upper limit: ";

	cin>> upr;

		I=((upr-lwr)/2.0)*(fun(upr)+fun(lwr));

		

		 cout << "The integration of sin(x/2) by using Trapezoidal rule is " << fixed << setprecision(4) << I << endl;

		

		return 0;

}
