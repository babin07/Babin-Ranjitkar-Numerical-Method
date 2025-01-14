#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double f(double x) {
    return exp(-x) - 2 * x * x;
}
int main() {
    double u, l;
     cout << "Enter a number such that value in function is negative: ";
    cin >> u;
    while (f(u) >= 0) {  
        cout << "Invalid input. f(" << u << ") = " << f(u) << " is not negative. Try again: ";
        cin >> u;
    }

    cout << "Enter a number such that value in function is positive: ";
    cin >> l;
    while (f(l) <= 0) {  
        cout << "Invalid input. f(" << l << ") = " << f(l) << " is not positive. Try again: ";
        cin >> l;
    }
    if (f(u) * f(l) > 0) {
        cout << "The function does not change signs in the interval. Bisection method cannot be applied." << endl;
        return 1;
    }
    double m_new = (u + l) / 2;
    double m_old;
    double error = 1.0;
    int i = 0;
    cout << fixed << setprecision(6);
    cout << left
         << setw(12) << "i"
         << setw(12) << "u"
         << setw(12) << "f(u)"
         << setw(12) << "l"
         << setw(12) << "f(l)"
         << setw(12) << "m"
         << setw(12) << "f(m)"
         << setw(12) << "error" << endl;
    while (true) {
        m_old = m_new;
        m_new = (u + l) / 2;
        if(m_new==0){
        	error=fabs(m_new-m_old);
		}
		else{
			error = fabs((m_new - m_old) / m_new);
		}
        cout << setw(12) << i
             << setw(12) << u
             << setw(12) << f(u)
             << setw(12) << l
             << setw(12) << f(l)
             << setw(12) << m_new
             << setw(12) << f(m_new)
             << setw(12) << error << endl;
        if (error <= 0.05) {
            break;
        }
        if (f(m_new) < 0) {
            u = m_new;
        } else {
            l = m_new;
        }
        i++;
    }
    cout << "\nRoot is: " << m_new << endl;
    return 0;
}
