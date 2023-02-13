/*
this is a program to generate A0 set
*/
#include "complexnumber.h"
#include "field_matrix.h"

FILE *f;
field_matrix<complexnumber> A0(2, 1);

int main()
{
    f = fopen("20230213_artificial_neural_network_data_generator.out", "wb");
    for (int i = -10; i <= 10; i++)
    {
        complexnumber complexnumber_i(i, 0);
        for (int j = -10; j <= 10; j++)
        {
            complexnumber complexnumber_j(j, 0);
            A0.dt[1][1] = complexnumber_i;
            A0.dt[2][1] = complexnumber_j;
            A0.fprint(f);
        }
    }
    fclose(f);
    return 0;
}
