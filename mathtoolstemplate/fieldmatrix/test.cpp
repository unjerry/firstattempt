#include "pfieldnumber.h"
#include "complexnumber.h"
#include "fieldmatrix.h"
int main()
{
    FILE *f;
    fieldmatrix<pfieldnumber> M(2, 3), B;
    pfieldnumber a(4, 5);
    pfieldnumber b(2, 5);
    a.print(0);
    printf("\n");
    b.print(0);
    printf("\n");
    (a + b).print(0);
    printf("\n");
    (a - b).print(0);
    printf("\n");
    (a * b).print(0);
    printf("\n");
    (a / b).print(0);
    printf("\n");

    f = fopen("testout", "wb");
    M.fprint(f, 0);
    fclose(f);
    f = fopen("testin", "rb");
    M.fscan(f, 0);
    M.print(0);
    B = rowechelon(M);
    B.print(0);
    B = columnechelon(M);
    B.print(0);
    B = inverse(M);
    B.print(0);
    fclose(f);
    return 0;
}
