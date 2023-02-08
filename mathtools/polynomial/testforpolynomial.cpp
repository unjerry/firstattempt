#include "polynomial.h"
#include "numbertheoryalgorithm.h"
#include <stdio.h>
double a[10] = {1, 4, 3, 1, 1, 1, 1};
double a2[10] = {1, 1, 1, 1, -3, -4, 23};
int leng = 2;
pn P(a, 4);
pn P2(a2, 3), P3;
pn PP[100];

int factori(pn P, pn *PL)
{
    int nm = 0;
    while (P.ctf.size() >= 3)
    {
        PL[nm++] = factorbyShie(P, P2);
        P = P / P2;
    }
    return nm;
}

int main()
{
    printf("P=");
    P.print(1);
    printf("\n");

    printf("P2=");
    P2.print(1);
    printf("\n");

    pn Q = P / P2;
    printf("Q=");
    Q.print(1);
    printf("\n");

    pn R = P % P2;
    printf("R=");
    R.print(1);
    printf("\n");

    P3 = Q * P2;
    printf("P3=");
    P3.print(1);
    printf("\n");

    pn X, Y, D;
    D = extended_euclidean<pn>(P, P2, X, Y);
    D.print(1);
    printf("\n");
    X.print(1);
    printf("\n");
    Y.print(1);
    printf("\n");

    int a = 38, b = 16, x, y, d;
    d = extended_euclidean<int>(a, b, x, y);
    printf("d=%d  %d*%d+%d*%d=%d\n", d, x, a, y, b, d);

    int dd = fast_power<int>(d, 6);
    pn DD = fast_power<pn>(Q, 6);

    printf("%d\n", dd);
    DD.print(1);
    // printf("\n");

    /*
    int lb = factori(P, PP);
    for (int i = 0; i < lb; i++)
    {
        PP[i].print(1);
        printf("\n");
    }
    */
    return 0;
}