#include "field_matrix.h"
#include "complexnumber.h"
#include "field_matrix_algorithm.h"

field_matrix<complexnumber> A, B, C, Q, L;
FILE *f;

int main()
{
    f = fopen("20230215_matrix_mutiplier.in", "rb");
    A.fscan(f);
    B.fscan(f);
    fclose(f);

    C = A * B;

    printf("A=\n");
    A.print();
    printf("B=\n");
    B.print();
    printf("A*B=\n");
    C.print();

    spectral_decomposition(C, Q, L);
    printf("C=\n");
    C.print();
    printf("Q=\n");
    Q.print();
    printf("L=\n");
    L.print();
    printf("C=Q*L*QT=\n");
    (Q * L * transpose(Q)).print();

    return 0;
}
