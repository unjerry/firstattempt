#include "fieldmatrix.h"
#include "complexnumber.h"

int main()
{
    FILE *f;

    fieldmatrix<complexnumber> M, MT, S;

    f = fopen("test_in_fieldmatrix_2", "rb");

    printf("M=\n");
    M.fscan(f);
    M.print();

    printf("MT=\n");
    MT = transpose(M);
    MT.print();

    printf("M*MT=\n");
    S = M * MT;
    S.print();

    fclose(f);

    return 0;
}
