//secant method
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
double f(double x) {
    return log10(x)-cos(x);
}
int main(){
	double a,b,c;
	do{
		cout<<"enter a"<<endl;
		cin>>a;
		cout<<"enter b"<<endl;
		cin>>b;
		if(f(a)==f(b)){
			cout<<"enter value so that f(a) is not equal to f(b)."<<endl;
		}
	}while(f(a)==f(b));
	if(f(a)==0){
		cout<<"root is "<<a<<endl;
		return 0;
	}
	if(f(b)==0){
		cout<<"root is "<<b<<endl;
		return 0;
		
	}
	
	double error=1.0;
	int i=1;
	cout<<setw(4)<<"i"<<setw(12)<<"a"<<setw(16)<<"f(a)"<<setw(12)<<"b"<<setw(16)<<"f(b)"<<setw(12)<<"c"<<setw(16)<<"f(c)"<<setw(16)<<error<<endl;
	do{
	  c=b-f(b)*(b-a)/(f(b)-f(a));
	  error=fabs((c-b)/c);
	  cout<<setw(4)<<i<<setw(12)<<a<<setw(16)<<f(a)<<setw(12)<<b<<setw(16)<<f(b)<<setw(12)<<c<<setw(16)<<f(c)<<setw(16)<<error<<endl;
	  a=b;
	  b=c;
	  i++;
	}while(error>0.05);
	cout<<"root is "<<c<<endl;
}