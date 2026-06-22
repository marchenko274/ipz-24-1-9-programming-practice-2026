#include <iostream>
#include <complex>
#include <cmath>

using namespace std;

int main()
{
    double a, b, c;

    cout << "Enter coefficient a: ";
    cin >> a;

    cout << "Enter coefficient b: ";
    cin >> b;

    cout << "Enter coefficient c: ";
    cin >> c;

    double p = b - a * a / 3.0;
    double q = 2.0 * a * a * a / 27.0 - a * b / 3.0 + c;

    complex<double> D = pow(q / 2.0, 2) + pow(p / 3.0, 3);

    complex<double> sqrtD = sqrt(D);

    complex<double> u = pow(-q / 2.0 + sqrtD, 1.0 / 3.0);
    complex<double> v = pow(-q / 2.0 - sqrtD, 1.0 / 3.0);

    complex<double> x1 = u + v - a / 3.0;

    complex<double> omega(-0.5, sqrt(3.0) / 2.0);

    complex<double> x2 =
        omega * u +
        conj(omega) * v -
        a / 3.0;

    complex<double> x3 =
        conj(omega) * u +
        omega * v -
        a / 3.0;

    cout << "\nResults:\n";
    cout << "x1 = " << x1 << endl;
    cout << "x2 = " << x2 << endl;
    cout << "x3 = " << x3 << endl;

    system("pause");
    return 0;
}