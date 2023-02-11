#include "list_convolution.h"

field_matrix<complexnumber> list_convolution(const field_matrix<complexnumber> &a, const field_matrix<complexnumber> &b)
{
    long long N = exp2(ceil(log2(a.r + b.r - 1)));
    complexnumber complex_N(N, 0, 0);
    field_matrix<complexnumber> ac(N, 1);
    for (int i = 1; i <= a.r; i++)
    {
        ac.dt[i][1] = a.dt[i][1];
    }
    field_matrix<complexnumber> bc(N, 1);
    for (int i = 1; i <= b.r; i++)
    {
        bc.dt[i][1] = b.dt[i][1];
    }
    field_matrix<complexnumber> A(N, 1), B(N, 1), C(N, 1);
    A = fast_fourier_transform(ac, 1);
    B = fast_fourier_transform(bc, 1);
    for (int i = 1; i <= N; i++)
    {
        C.dt[i][1] = A.dt[i][1] * B.dt[i][1] / complex_N;
    }
    field_matrix<complexnumber> cc(N, 1);
    cc = fast_fourier_transform(C, -1);
    long long NN = a.r + b.r - 1;
    field_matrix<complexnumber> c(NN, 1);
    for (int i = 1; i <= NN; i++)
    {
        c.dt[i][1] = cc.dt[i][1];
    }
    return c;
}
