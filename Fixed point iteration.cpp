#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
double f(double num){
	return sqrt(exp(-num)/2);
}
int main(){
	double x,function;
	cout<<"enter a number"<<endl;
	cin>>x;
	cout<<"x="<<x<<",f(x)="<<f(x)<<endl;
	int i=1;
	double err;
	
	cout<<setw(4)<<"i"<<setw(12)<<"x"<<setw(16)<<"f(x)"<<setw(12)<<"error"<<endl;
	do{
		function=f(x);
		err=fabs((function-x)/function);
		cout<<setw(4)<<i<<setw(12)<<x<<setw(16)<<function<<setw(12)<<err<<endl;
		x=function;
		i++;
	}while(err>0.05);
	cout<<"root approx is "<<x;
}