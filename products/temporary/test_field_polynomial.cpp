#include "field_polynomial.h"
#include "complexnumber.h"
#include "number_theory_algorithm.h"
#include <stdio.h>

FILE *f;

int main()
{
    field_polynomial<complexnumber> p, p2, a, b, p3, x, y, d;

    p.print();
    printf("\n");

    f = fopen("test_field_polynomial.in", "rb");
    p.fscan(f);
    a.fscan(f);
    b.fscan(f);
    fclose(f);

    p.print();
    printf("\n");

    p2 = p * p;
    p2.print();
    printf("\n");

    (a / b).print();
    printf("\n");
    (a % b).print();
    printf("\n");

    p3 = p2 * p;
    p3.print();
    printf("\n1\n");
    p3 = fast_power(p, 10); // if input over 50 it will occur a bug
    p3.print();
    printf("\n2\n");

    d = extended_euclidean(p, p2, x, y);
    d.print();
    printf("\n");
    x.print();
    printf("\n");
    y.print();
    printf("\n");

    return 0;
}
