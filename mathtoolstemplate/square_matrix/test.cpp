#include "square_matrix.h"
#include "complexnumber.h"
#include "numbertheoryalgorithm.h"
int main()
{
    FILE *f;

    square_matrix<complexnumber, 3> M;
    M.print(0);
    printf("\n");

    M = 1;
    M.print(0);
    printf("\n");

    f = fopen("testin", "rb");
    M.fscan(f, 0);
    fclose(f);
    M.print(0);
    // printf("dsdf\n");
    (fast_power<square_matrix<complexnumber, 3>>(M, 6)).print(0);
    // printf("fsfddf\n");
    return 0;
}
