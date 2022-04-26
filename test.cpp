#include "mylib.h"

void Mul(double *x, double *res, int *pai1, int *pai2, double *a, double *b, int x_r, int x_c)
{
    for (int i = 0; i < x_r; i++)
    {
        for (int j = 0; j < x_c; j++)
            res[i * x_c + j] = (double)a[i] / b[j] * x[(pai1[i] - 1) * x_c + (pai2[j] - 1)];
    }
}

int main()
{
    /*
    double x[6] = {1, 1, 1, 1, 1, 1};
    double res[6] = {0};
    int x_r = 2;
    int x_c = 3;
    double a[2] = {2, 3};
    double b[3] = {4, 5, 6};
    int pai1[2] = {2, 1};
    int pai2[3] = {2, 1, 3};
    */
    /*
    for (int i = 0; i < x_r; i++)
    {
        for (int j = 0; j < x_c; j++)
            res[i * x_c + j] = (double)a[i] / b[j] * x[(pai1[i] - 1) * x_c + (pai2[j] - 1)];
    }
    */
    double x[6] = {1, 1, 1, 1, 1, 1};
    double res[6] = {0};
    int x_r = 2;
    int x_c = 3;
    double a[2] = {2, 3};
    double b[3] = {4, 5, 6};
    int pai1[2] = {2, 1};
    int pai2[3] = {2, 1, 3};
    Mul(x, res, pai1, pai2, a, b, x_r, x_c);
    for (int i = 0; i < x_r; i++)
    {
        for (int j = 0; j < x_c; j++)
            cout << res[i * x_c + j] << ",";
        cout << endl;
    }
    return 0;
}