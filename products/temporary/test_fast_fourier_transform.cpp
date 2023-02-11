#include "fast_fourier_transform.h"
#include "field_matrix.h"
#include "complexnumber.h"
#include <stdio.h>

FILE *f;
field_matrix<complexnumber> V1, V2, U1, U2, W1, W2;

int main()
{
    f = fopen("test_fast_fourier_transform.in", "rb");
    V1.fscan(f);
    V2.fscan(f);
    fclose(f);

    printf("V1=\n");
    V1.print();
    printf("V2=\n");
    V2.print();

    printf("U1=\n");
    U1 = fast_fourier_transform(V1, 1);
    U1.print();
    printf("U2=\n");
    U2 = fast_fourier_transform(V2, 1);
    U2.print();

    printf("W1=\n");
    W1 = fast_fourier_transform(U1, -1);
    W1.print();
    printf("W2=\n");
    W2 = fast_fourier_transform(U2, -1);
    W2.print();

    return 0;
}
