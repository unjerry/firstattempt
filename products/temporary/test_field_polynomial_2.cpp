#include "field_polynomial.h"
#include "complexnumber.h"
#include "number_theory_algorithm.h"
#include <stdio.h>

FILE *f;

int main()
{
    field_polynomial<complexnumber> p, p2, a, b, p3, x, y, d;
    printf("p=");
    p.print();
    printf("\n");

    f = fopen("test_field_polynomial.in", "rb");
    p.fscan(f);
    a.fscan(f);
    b.fscan(f);
    fclose(f);

    printf("p=");
    p.print();
    printf("\n");

    p2 = p * p;
    printf("p2=");
    p2.print();
    printf("\n");

    printf("a=");
    a.print();
    printf("\n");
    printf("b=");
    b.print();
    printf("\n");

    printf("a/b=");
    (a / b).print();
    printf("\n");
    printf("a%b=");
    (a % b).print();
    printf("\n");

    p3 = p2 * p;
    printf("p3=");
    p3.print();
    printf("\n");
    p3 = fast_power(p, 50); // if input over 50 it will occur a bug
    printf("p10=");
    p3.print();
    printf("\n");

    d = extended_euclidean(p, p2, x, y);
    printf("d=");
    d.print();
    printf("\n");
    printf("x=");
    x.print();
    printf("\n");
    printf("y=");
    y.print();
    printf("\n");

    d = derive_polynomial(a);
    printf("a=");
    a.print();
    printf("\n");
    printf("da=");
    d.print();
    printf("\n");

    std::vector<complexnumber> vv;
    vv = factorization(a);
    printf("len=%d\n", vv.size());
    for (int i = 0; i < vv.size(); i++)
    {
        vv[i].print();
    }

    return 0;
}
