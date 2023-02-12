#include "field_matrix.h"
#include "complexnumber.h"
#include "field_matrix_algorithm.h"
#include "field_polynomial.h"

int main()
{
    FILE *f;

    field_matrix<complexnumber> M;
    field_polynomial<complexnumber> P;
    field_matrix<field_polynomial<complexnumber>> MP(1, 1);

    f = fopen("test_fieldmatrix_3.in", "rb");
    M.fscan(f);
    fclose(f);

    MP.print();

    P = character_polynomial(M);
    f = fopen("test_fieldmatrix_3.out", "wb");
    P.fprint(f, 2);
    fclose(f);

    return 0;
}
