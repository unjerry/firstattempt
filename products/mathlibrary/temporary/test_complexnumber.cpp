#include "complexnumber.h"
#include <stdio.h>

#define PI 4

FILE *f;

int main()
{
    complexnumber z(1, PI, 1), tmp;
    z.print();
    printf("\n");

    f = fopen("test_out", "ab");
    z.fprint(f);
    fprintf(f, "\n");
    fclose(f);

    tmp = 1;
    tmp.print();
    printf("\n");

    tmp = 0;
    tmp.print();
    printf("\n");

    tmp = z;
    tmp.print();
    printf("\n");

    tmp = -z;
    tmp.print();
    printf("\n");

    tmp = !z;
    tmp.print();
    printf("\n");

    printf("z\n");
    (tmp).print();
    printf("\n");
    (z).print();
    printf("\n");
    (tmp + z).print();
    printf("\n");
    (tmp - z).print();
    printf("\n");
    (tmp * z).print();
    printf("\n");
    (tmp / z).print();
    printf("\n");

    complexnumber zero;
    printf("zero\n");
    z = tmp / zero;
    (z).print();
    printf("\n");
    z = tmp * zero;
    (z).print();
    printf("\n");

    return 0;
}
