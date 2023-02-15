#include "field_matrix.h"
#include "complexnumber.h"
#include <math.h>

field_matrix<complexnumber> W[11], B[11], Z[11], A[11];
field_matrix<complexnumber> dW[11], d[11], D(1, 1);
field_matrix<complexnumber> X[441], Y[441];

complexnumber one(1, 0);
complexnumber scc(0.1 / sqrt(2), 0);
complexnumber complex_euler_number(exp(1), 0);

FILE *f;

field_matrix<complexnumber> Func(const field_matrix<complexnumber> &x)
{
    complexnumber z;
    z = x.dt[1][1] * x.dt[1][1] + x.dt[2][1] * x.dt[2][1];
    field_matrix<complexnumber> Z(1, 1);
    Z.dt[1][1] = z;
    return Z;
}
complexnumber Sigmoid(const complexnumber &x)
{
    complexnumber y;
    y = x;
    return one / (one + (complex_euler_number ^ (-y)));
}
complexnumber dSigmoid(const complexnumber &x)
{
    complexnumber y, ey;
    y = x;
    ey = complex_euler_number ^ (-y);
    return ey / ((one + ey) * (one + ey));
}
field_matrix<complexnumber> Sigmoid_over_matrix(const field_matrix<complexnumber> &x)
{
    field_matrix<complexnumber> z(x.r, x.c);
    for (int i = 1; i <= x.r; i++)
    {
        for (int j = 1; j <= x.c; j++)
        {
            z.dt[i][j] = Sigmoid(x.dt[i][j]);
        }
    }
    return z;
}
field_matrix<complexnumber> dSigmoid_over_matrix(const field_matrix<complexnumber> &x)
{
    field_matrix<complexnumber> z(x.r, x.c);
    for (int i = 1; i <= x.r; i++)
    {
        for (int j = 1; j <= x.c; j++)
        {
            z.dt[i][j] = dSigmoid(x.dt[i][j]);
        }
    }
    return z;
}

void calculate_cost()
{
    field_matrix<complexnumber> tdW[11], td[11];
    D.dt[1][1] = 0;
    for (int t = 0; t < 441; t++)
    {
        A[0] = X[t];
        for (int i = 1; i <= 3; i++)
        {
            // printf("%d\n", i);
            Z[i] = W[i] * A[i - 1] + B[i];
            A[i] = Sigmoid_over_matrix(Z[i]);
        }
        d[0] = A[3] - Y[t];
        D = D + (d[0] * d[0]);
        d[3] = matrix_pointwise_multiplication(d[0], dSigmoid_over_matrix(Z[3]));
        dW[3] = d[3] * transpose(A[2]);
        for (int i = 2; i >= 1; i--)
        {
            d[i] = matrix_pointwise_multiplication(transpose(W[i + 1]) * d[i + 1], dSigmoid_over_matrix(Z[i]));
            dW[i] = d[i] * transpose(A[i - 1]);
        }
        for (int i = 1; i <= 3; i++)
        {
            tdW[i] = tdW[i] + dW[i];
            td[i] = td[i] + d[i];
        }
    }
    // tdW[10].print();
    complexnumber scl(1.0 / 411, 0);
    for (int i = 1; i <= 3; i++)
    {
        dW[i] = scl * tdW[i];
        d[i] = scl * td[i];
    }
    D = scl * D;
    // dW[3].print();
}

int main()
{
    f = fopen("ann11.in", "rb");
    for (int i = 1; i <= 3; i++)
    {
        W[i].fscan(f);
        B[i].fscan(f);
    }
    fclose(f);

    f = fopen("ann.dt", "rb");
    for (int i = 0; i < 441; i++)
    {
        X[i].fscan(f);
        X[i] = scc * X[i];
        Y[i] = Func(X[i]);
    }
    X[1].print();
    Y[1].print();
    fclose(f);

    printf("star\n");
    for (int T = 1; T <= 100000; T++)
    {
        if (T % 100 == 0)
        {
            printf("%d\n", T);
            dW[3].print();
            D.print();
        }
        calculate_cost();
        for (int i = 1; i <= 3; i++)
        {
            W[i] = W[i] - dW[i];
            B[i] = B[i] - d[i];
        }
    }

    f = fopen("ann.out", "wb");
    for (int i = 1; i <= 3; i++)
    {
        W[i].fprint(f);
        B[i].fprint(f);
    }
    fclose(f);

    return 0;
}
