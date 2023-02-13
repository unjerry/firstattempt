/*
this exp was about a very tiny model
wich has one hidden layer W[2*2]
it will fit one vector function F[x,y]=x^2+y^2
*/
#include "complexnumber.h"
#include "field_matrix.h"
#include <math.h>

FILE *f1, *f2;
field_matrix<complexnumber> W1, W2;
field_matrix<complexnumber> B1, B2;
field_matrix<complexnumber> A1, A2;
field_matrix<complexnumber> Z1, Z2;
field_matrix<complexnumber> A0[500], YY;
field_matrix<complexnumber> d1, d2;
field_matrix<complexnumber> dW1, dW2;
field_matrix<complexnumber> dB1, dB2;
field_matrix<complexnumber> deltaC;

double euler_number = exp(1);
complexnumber complex_euler_number(euler_number, 0);
complexnumber one(1, 0);
complexnumber delta(2, 0);
complexnumber factor(0.1, 0);

field_matrix<complexnumber> Y(const field_matrix<complexnumber> &x)
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

field_matrix<complexnumber> forward(const field_matrix<complexnumber> &X)
{
    Z1 = W1 * X + B1;
    A1 = Sigmoid_over_matrix(Z1);
    Z2 = W2 * A1 + B2;
    A2 = Sigmoid_over_matrix(Z2);
    return A2;
}
field_matrix<complexnumber> del_cost(const field_matrix<complexnumber> &X)
{
    field_matrix<complexnumber> Z;
    Z = (forward(X) - Y(X));
    for (int i = 1; i <= Z.r; i++)
    {
        for (int j = 1; j <= Z.c; j++)
        {
            Z.dt[i][j] = Z.dt[i][j] * delta;
        }
    }
    return Z;
}

int main()
{
    printf("e=%llf\n", euler_number);

    f1 = fopen("20230213_artificial_neural_network.out", "rb");
    W1.fscan(f1);
    B1.fscan(f1);
    W2.fscan(f1);
    B2.fscan(f1);
    fclose(f1);

    printf("W1=");
    W1.print();
    printf("B1=");
    B1.print();
    printf("W2=");
    W2.print();
    printf("B2=");
    B2.print();

    // A0[0].r = 2;
    // A0[0].c = 1;
    // A0[0].dt[1][1] = aa;
    // A0[0].dt[2][1] = bb;
    complexnumber aa(0.3, 0);
    complexnumber bb(0.2, 0);
    field_matrix<complexnumber> AA(2, 1);
    A0[0] = AA;
    A0[0].dt[1][1] = aa;
    A0[0].dt[2][1] = bb;
    A0[0].print();

    printf("start-------1\n");
    printf("W1=");
    W1.print();
    printf("B1=");
    B1.print();
    printf("W2=");
    W2.print();
    printf("B2=");
    B2.print();

    printf("A0=");
    A0[0].print();

    Z1 = W1 * A0[0] + B1;
    printf("Z1=");
    Z1.print();
    A1 = Sigmoid_over_matrix(Z1);
    printf("A1=");
    A1.print();

    Z2 = W2 * A1 + B2;
    printf("Z1=");
    Z2.print();
    A2 = Sigmoid_over_matrix(Z2);
    printf("A2=");
    A2.print();

    printf("YY=");
    YY = Y(A0[0]);
    YY.print();

    printf("delC=");
    deltaC = A2 - YY;
    deltaC.print();
    deltaC.dt[1][1] = deltaC.dt[1][1] * delta;

    printf("de2=");
    d2 = matrix_pointwise_multiplication(deltaC, dSigmoid_over_matrix(Z2));
    d2.print();
    printf("de1=");
    d1 = matrix_pointwise_multiplication(transpose(W2) * d2, dSigmoid_over_matrix(Z1));
    d1.print();
    printf("A1=");
    A1.print();
    printf("Z1=");
    Z1.print();
    printf("A2=");
    A2.print();
    printf("Z2=");
    Z2.print();

    printf("dW2=");
    dW2 = d2 * transpose(A1);
    dW2.print();
    printf("dW1=");
    dW1 = d1 * transpose(A0[0]);
    dW1.print();
    printf("--------\n");
    A0[0].print();
    printf("A2=");
    A2.print();

    return 0;
}
