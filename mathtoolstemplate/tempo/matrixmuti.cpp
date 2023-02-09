#include "fieldmatrix.h"
#include "complexnumber.h"
#include "..\..\mathtoolslibrary\src\fieldmatrix.cpp"
#include <math.h>
#include <stdio.h>
#define PI acos(-1)
int main()
{
    FILE *f;
    f = fopen("inputfile", "rb");
    fieldmatrix<complexnumber> R(2, 2);
    R.fscan(f, 0);

    R.print(0);

    fieldmatrix<complexnumber> R2 = R * R;
    R2.print(0);
    fieldmatrix<complexnumber> R3 = R2 * R;
    R3.print(0);

    fieldmatrix<complexnumber> F;
    F.fscan(f, 0);
    fclose(f);
    printf("lll\n");

    F.print(0);

    R.print(0);
    R2.print(0);
    R3.print(0);

    (F * R).print(0);
    (F * R2).print(0);
    (F * R3).print(0);


    return 0;
}
