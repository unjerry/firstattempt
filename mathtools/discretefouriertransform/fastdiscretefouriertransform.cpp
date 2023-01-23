#include "complexnumber.h"
#include "complexmatrix.h"
#include "listconvolution.h"
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
complexmatrix fast_discrete_fourier_transform(complexmatrix iv)
{
    long long N = iv.r;
    complexnumber xi(1, -1.0 * PI / N, 1);
    complexnumber complexnumber_negative_1(-1, 0, 0);
    xi.print(0);
    complexmatrix a(N, 1);
    complexmatrix b(2 * N - 1, 1);
    complexmatrix c(N, 1);
    complexmatrix tmp;
    for (int i = 1; i <= 2 * N - 1; i++)
    {
        complexnumber complexpower_i(-(N - 1) + i - 1, 0, 0);
        b.dt[i][1] = xi ^ (complexnumber_negative_1 * complexpower_i * complexpower_i);
    }
    for (int i = 1; i <= N; i++)
    {
        complexnumber complexpower_i(i - 1, 0, 0);
        a.dt[i][1] = iv.dt[i][1] * (xi ^ (complexpower_i * complexpower_i));
    }
    printf("this is a\n");
    a.print(0);
    printf("this is b\n");
    b.print(0);
    tmp = listconvolution(a, b);
    tmp.print(0);
    for (int i = 1; i <= N; i++)
    {
        complexnumber complexpower_i(i - 1, 0, 0);
        c.dt[i][1] = tmp.dt[i - 1 + N][1] * (xi ^ (complexpower_i * complexpower_i));
    }
    return c;
}
long long N;
int main()
{
    printf("%lf\n", atan2(0, -1));
    printf("%lf\n", atan2(0, 1));
    printf("%lf\n", atan2(-1, -1));
    printf("%lf\n", atan2(-1, 1));

    FILE *inpt;
    inpt = fopen("fastdiscretefouriertransform.inpt", "r");
    fscanf(inpt, "%lld", &N);
    complexmatrix inpt_list(N, 1);
    for (int i = 1; i <= N; i++)
    {
        inpt_list.dt[i][1].fscan(inpt, 0);
    }
    fclose(inpt);

    inpt_list.print(0);

    complexmatrix oupt_list(N, 1);
    complexmatrix oupt_list_2(N, 1);
    oupt_list = fast_discrete_fourier_transform(inpt_list);
    oupt_list_2 = discrete_fourier_transform(inpt_list);

    FILE *oupt;
    oupt = fopen("fastdiscretefouriertransform.oupt", "w");
    oupt_list.fprint(oupt, 1);
    oupt_list_2.fprint(oupt, 1);
    fclose(oupt);
    return 0;
}
