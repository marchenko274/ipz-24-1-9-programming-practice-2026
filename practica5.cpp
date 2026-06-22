#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    double eps;

    cout << "Enter system size: ";
    cin >> n;

    cout << "Enter epsilon: ";
    cin >> eps;

    double** A = new double* [n];
    for (int i = 0; i < n; i++)
        A[i] = new double[n];

    double* B = new double[n];
    double* X = new double[n];
    double* Xnew = new double[n];

    cout << "\nEnter matrix A:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "A[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> A[i][j];
        }
    }

    cout << "\nEnter vector B:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "B[" << i + 1 << "] = ";
        cin >> B[i];
    }

    for (int i = 0; i < n; i++)
        X[i] = 0;

    bool stop;

    do
    {
        stop = true;

        for (int i = 0; i < n; i++)
        {
            double sum = 0;

            for (int j = 0; j < n; j++)
            {
                if (i != j)
                    sum += A[i][j] * X[j];
            }

            Xnew[i] = (B[i] - sum) / A[i][i];

            if (fabs(Xnew[i] - X[i]) > eps)
                stop = false;
        }

        for (int i = 0; i < n; i++)
            X[i] = Xnew[i];

    } while (!stop);

    cout << "\nResult:\n";

    for (int i = 0; i < n; i++)
        cout << "x" << i + 1 << " = " << X[i] << endl;

    for (int i = 0; i < n; i++)
        delete[] A[i];

    delete[] A;
    delete[] B;
    delete[] X;
    delete[] Xnew;

    return 0;
}
