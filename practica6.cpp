#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double PI = 3.14159265358979323846;

typedef struct
{
    double re;
    double im;
} complex_num;

complex_num divideComplex(complex_num z1, complex_num z2)
{
    complex_num result;

    double denominator =
        z2.re * z2.re +
        z2.im * z2.im;

    result.re =
        (z1.re * z2.re +
         z1.im * z2.im) / denominator;

    result.im =
        (z1.im * z2.re -
         z1.re * z2.im) / denominator;

    return result;
}

void printComplex(complex_num z)
{
    cout << fixed << setprecision(6);

    cout << z.re;

    if (z.im >= 0)
        cout << " + i*" << z.im;
    else
        cout << " - i*" << fabs(z.im);
}

int main()
{
    double R, L, C;
    double fmin, fmax, df;

    cout << "Enter R (Ohm): ";
    cin >> R;

    cout << "Enter L (mH): ";
    cin >> L;

    cout << "Enter C (uF): ";
    cin >> C;

    cout << "Enter fmin: ";
    cin >> fmin;

    cout << "Enter fmax: ";
    cin >> fmax;

    cout << "Enter step df: ";
    cin >> df;

    if (R <= 0 || L <= 0 || C <= 0)
    {
        cout << "Error: all parameters must be positive!" << endl;
        return 1;
    }

    if (fmin > fmax)
    {
        cout << "Error: fmin must be less than or equal to fmax!" << endl;
        return 1;
    }

    // Перевод единиц измерения
    L = L / 1000.0;      // mH -> H
    C = C / 1000000.0;   // uF -> F

    double f0 =
        1.0 /
        (2.0 * PI * sqrt(L * C));

    cout << fixed << setprecision(6);

    cout << "\nResonance frequency f0 = "
         << f0 << " Hz\n";

    cout << "\nFrequency\tZ\n";

    for (double f = fmin; f <= fmax; f += df)
    {
        double w = 2.0 * PI * f;

        complex_num numerator;
        numerator.re = L / C;
        numerator.im = R / (w * C);

        complex_num denominator;
        denominator.re = R;
        denominator.im =
            w * L -
            1.0 / (w * C);

        complex_num Z =
            divideComplex(numerator, denominator);

        cout << "f = " << f << "\tZ = ";
        printComplex(Z);
        cout << endl;
    }

    system("pause");
    return 0;
}
