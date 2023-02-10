#include "fieldmatrix.h"
#include "complexnumber.h"

int main()
{
    FILE *f = fopen("test_in_fieldmatrix", "rb");
    fieldmatrix<complexnumber> M, N, Sigma, U, V, S;
    M.fscan(f);
    M.print();

    printf("rowechelon\n");
    N = row_echelon(M);
    N.print();

    printf("columnechelon\n");
    N = column_echelon(M);
    N.print();

    printf("equivalentnormalizedform\n");
    N = equivalent_normalized_form(M);
    N.print();

    printf("inverse\n");
    N = inverse(M);
    N.print();

    printf("V=\n");
    V.fscan(f);
    V.print();

    printf("Sigma=\n");
    Sigma.fscan(f);
    Sigma.print();

    printf("U=\n");
    U.fscan(f);
    U.print();

    printf("USV=\n");
    (U * Sigma * transpose(V)).print();

    printf("V=\n");
    V.fscan(f);
    S.fscan(f);
    V = V * S;
    (V).print();

    printf("Sigma=\n");
    Sigma.fscan(f);
    Sigma.print();

    printf("U=\n");
    U.fscan(f);
    S.fscan(f);
    U = U * S;
    (U).print();

    printf("USV=\n");
    (U * Sigma * transpose(V)).print();
    return 0;
}
