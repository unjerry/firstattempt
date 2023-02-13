#ifndef FIELD_MATRIX_ALGORITHM
#define FIELD_MATRIX_ALGORITHM

#include "field_matrix.h"
#include "field_polynomial.h"

template <class F>
field_polynomial<F> character_polynomial(const field_matrix<field_polynomial<F>> &x) // E means Euclidean Ring not ready and im tendto make it a sudoinverse
{
    if (x.r != x.c)
    {
        field_polynomial<F> r;
        return r;
    }
    if (x.r == 1)
    {
        return x.dt[1][1];
    }
    long long N = x.c;
    field_matrix<field_polynomial<F>> M = x, M1(N - 1, N - 1);
    field_polynomial<F> P;
    P = M.dt[1][1];
    for (int i = 1; i <= N - 1; i++)
    {
        for (int j = 1; j <= N - 1; j++)
        {
            // printf("i=%d j=%d\n", i, j);
            M1.dt[i][j] = M.dt[i + 1][j + 1] * M.dt[1][1] - M.dt[1][j + 1] * M.dt[i + 1][1];
        }
    }
    return character_polynomial(M1) / fast_power(P, M.r - 2);
}
template <class F>
field_polynomial<F> character_polynomial(const field_matrix<F> &x) // E means Euclidean Ring not ready and im tendto make it a sudoinverse
{
    // printf("sdfsdf1\n");
    if (x.r != x.c)
    {
        field_polynomial<F> r;
        return r;
    }
    // printf("sdfsdf2\n");
    field_matrix<field_polynomial<F>> M(x.r, x.r);
    // printf("sdfsdf3\n");
    F one;
    one = 1;
    // printf("sdfsdf4\n");
    for (int i = 1; i <= x.r; i++)
    {
        for (int j = 1; j <= x.c; j++)
        {
            if (i == j)
            {
                M.dt[i][j].dt.resize(2);
                M.dt[i][j].dt[0] = x.dt[i][j];
                M.dt[i][j].dt[1] = -one;
            }
            else
            {
                M.dt[i][j].dt.resize(1);
                M.dt[i][j].dt[0] = x.dt[i][j];
            }
        }
    }
    // printf("sdfsdf5\n");
    M.print();
    return character_polynomial(M);
}

#endif
