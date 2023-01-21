#include "complexnumber.h"
#include "complexmatrix.h"
#include <math.h>
#define PI acos(-1)
complexmatrix generate_fourier_matrix_of_size(int N)
{
    complexmatrix fouriermatrix(N, N);
    complexnumber zeta(1, -2.0 * PI / N, 1);
    for (int i = 1; i <= N; i++)
    {
        complexnumber power_i(i - 1, 0, 0);
        for (int j = 1; j <= N; j++)
        {
            complexnumber power_j(j - 1, 0, 0);
            fouriermatrix.dt[i][j] = zeta ^ (power_i * power_j);
        }
    }
    return fouriermatrix;
}
complexmatrix discrete_fourier_transform(complexmatrix iv)
{
    complexmatrix fM;
    fM = generate_fourier_matrix_of_size(iv.r);
    fM.print(0);
    return fM * iv;
}
long long N;
int main()
{
    FILE *inpt;
    inpt = fopen("discretefouriertransform.inpt", "r");
    fscanf(inpt, "%lld", &N);
    complexmatrix inpt_list(N, 1);
    for (int i = 1; i <= N; i++)
    {
        inpt_list.dt[i][1].fscan(inpt, 0);
    }
    fclose(inpt);

    inpt_list.print(0);

    complexmatrix oupt_list(N, 1);
    oupt_list = discrete_fourier_transform(inpt_list);

    FILE *oupt;
    oupt = fopen("discretefouriertransform.oupt", "w");
    oupt_list.fprint(oupt, 0);
    fclose(oupt);
    return 0;
}
