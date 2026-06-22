#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    double x, e;
    int k;

    cout << "x=";
    cin >> x;

    cout << "k=";
    cin >> k;

    cout << "e=";
    cin >> e;

    double y = 1.0;
    double delta = 1.0;
    int iteration = 1;

    while (fabs(delta) >= e)
    {
        delta = (1.0 / k) * (x / pow(y, k - 1) - y);
        y += delta;

        cout << fixed << setprecision(6);
        cout << "iteration:" << iteration
            << ", delta=" << delta
            << ", y=" << y << endl;

        iteration++;
    }

    cout << "\nResult: y = " << y << endl;

    return 0;
}