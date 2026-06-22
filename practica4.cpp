#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double taylorSin(double x, double eps)
{
    double term = x;
    double sum = x;
    int n = 1;

    while (fabs(term) > eps)
    {
        term *= -x * x / ((2 * n) * (2 * n + 1));
        sum += term;
        n++;
    }

    return sum;
}

int main()
{
    double x1, x2, dx, eps;

    cout << "x1 = ";
    cin >> x1;

    cout << "x2 = ";
    cin >> x2;

    cout << "dx = ";
    cin >> dx;

    cout << "epsilon = ";
    cin >> eps;

    cout << fixed << setprecision(6);

    cout << "\n"
        << setw(10) << "x"
        << setw(15) << "Taylor"
        << setw(15) << "sin(x)"
        << setw(15) << "Difference"
        << endl;

    for (double x = x1; x <= x2; x += dx)
    {
       const double PI = 3.14159265358979323846;
double rad = x * PI / 180.0;

        double taylor = taylorSin(rad, eps);
        double standard = sin(rad);

        cout << setw(10) << x
            << setw(15) << taylor
            << setw(15) << standard
            << setw(15) << fabs(taylor - standard)
            << endl;
    }

    return 0;
}