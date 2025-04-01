#include<iostream>

#include<math.h>

#include<iomanip>

using namespace std;



float fun(float x){

	

	return sin(x/2);

}



int main(){

			float I,h,lwr,upr,x1,x2;

	

		cout << "Enter the limit: "<<endl;

    cout<<"lower limit: ";

    cin >> lwr ;

	cout<<"upper limit: ";

	cin>> upr;

			h=(upr-lwr)/3.0;

			x1=lwr+h;

			x2=lwr+h+h;

			I=((3.0/8.0)*h)*(fun(lwr)+(3.0*fun(x1))+(3.0*fun(x2))+fun(upr));

		

		cout << "The integration of sin(x/2) by using Simpson's 3/8 rule is " << fixed << setprecision(4) << I << endl;

		

		

	return 0;

}

