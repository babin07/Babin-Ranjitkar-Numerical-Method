#include <iostream>

#include <cmath>

#include <iomanip>



using namespace std;

float fun(float x, float y) {

    if (x == 0.4) {

        return x + y; 

    }

    return x + y; 

}



// Runge-Kutta 4th Order Method

void Rk4(float h, float x, float y, float xn) {

    float m1, m2, m3, m4;

    int i = 1;



    cout <<endl<<"Runge-Kutta Method:"<<endl;

    while (x < xn) {  

        m1 = fun(x, y);

        m2 = fun(x + (h / 2), y + (m1 * (h / 2)));

        m3 = fun(x + (h / 2), y + (m2 * (h / 2)));

        m4 = fun(x + h, y + (m3 * h));

        

        y = y + (m1 + 2 * m2 + 2 * m3 + m4) * (h / 6);

        x += h;



        cout << "Itr " << i++ <<endl;

		cout<<"y(" << fixed << setprecision(3) << x << ") = " << y << endl;

    }

}



// Euler's Method

void Euler(float h, float x, float y, float xn) {

    int i = 1;

    cout <<endl<< "Euler's Method:"<<endl;

    while (x < xn) {

        y = y + (h * fun(x, y));

        x += h;



        cout << "Itr " << i++ <<endl;

		cout<< "y(" << fixed << setprecision(3) << x << ") = " << y << endl;

    }

}



// Heun's Method

void Heun(float h, float x, float y, float xn) {

    float m1, m2;

    int i = 1;



    cout <<endl<<"Heun's Method:"<<endl;

    while (x < xn) {

        m1 = fun(x, y);

        m2 = fun(x + h, y + (m1 * h));

        y = y + ((m1 + m2) * (h / 2.0));

        x += h;



        cout << "Itr " << i++ <<endl;

		 cout<<"y(" << fixed << setprecision(3) << x << ") = " << y << endl;

    }

}

int main() {

    float h, x, y, xn;



    cout << "Enter the step size (h): ";

    cin >> h;

    cout << "Enter the initial values for x and y: ";

    cin >> x >> y;

    cout << "Enter the final value for x: ";

    cin >> xn;



    Euler(h, x, y, xn);

    Heun(h, x, y, xn);

    Rk4(h, x, y, xn);



    return 0;

}

