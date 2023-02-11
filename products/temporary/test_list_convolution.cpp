#include "list_convolution.h"
#include "field_matrix.h"
#include "complexnumber.h"
#include <stdio.h>

FILE *f;
field_matrix<complexnumber> V1, V2, U1, U2, W1, W2, V12;

int main()
{
    f = fopen("test_list_convolution.in", "rb");
    V1.fscan(f);
    V2.fscan(f);
    fclose(f);

    printf("V1=\n");
    V1.print();
    printf("V2=\n");
    V2.print();

    printf("V1*V2=\n");
    V12 = list_convolution(V1, V2);
    V12.print();

    return 0;
}
