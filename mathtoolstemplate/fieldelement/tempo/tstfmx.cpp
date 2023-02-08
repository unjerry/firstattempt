#include <stdio.h>
#include "numbertheoryalgorithm.h"
#include "fieldmatrix.h"
#include "complexnumber.h"
int main()
{
    FILE *f;
    f = fopen("tstfmxin", "rb");

    int a = 234, b = 38, x, y, d;
    d = extended_euclidean(a, b, x, y);
    int dx = -b / d, dy = a / d;
    for (int i = 0; i <= 0; i++)
    {
        printf("%d*%d+%d*%d=(%d,%d)=%d\n", x + i * dx, a, y + i * dy, b, a, b, d);
    }

    printf("--1\n");

    fieldmatrix<complexnumber> M(2, 3);
    M.print(0);

    printf("--2\n");

    complexnumber ca(1, 1, 0), cap;
    cap = fast_power<complexnumber>(ca, 6);
    ca.print(0);
    ca.print(1);
    printf("\n");
    cap.print(0);
    cap.print(1);
    printf("\n");

    printf("--3\n");

    long long ia = 2, iap;
    iap = fast_power<long long>(ia, 8);
    printf("%d^%d=%d\n", ia, 8, iap);

    printf("--4\n");

    fieldmatrix<complexnumber> A(3, 3), Ap;
    A.fscan(f, 0);
    A.print(0);

    printf("--5\n");

    fclose(f);
    return 0;
}
