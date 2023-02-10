#include "fieldmatrix.h"
#include "complexnumber.h"

int main()
{
    FILE *f = fopen("test_in_fieldmatrix", "rb");
    fieldmatrix<complexnumber> M, N;
    M.fscan(f);
    M.print();

    printf("rowechelon\n");
    N = rowechelon(M);
    N.print();

    printf("columnechelon\n");
    N = columnechelon(M);
    N.print();

    printf("equivalentnormalizedform\n");
    N = equivalentnormalizedform(M);
    N.print();

    printf("inverse\n");
    N = inverse(M);
    N.print();
    return 0;
}
