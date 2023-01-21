#include "complexmatrix.h"
#include "fastfouriertransform.h"
#include <math.h>
complexmatrix listconvolution(complexmatrix a, complexmatrix b)
{
    long long N = exp2(ceil(log2(a.r + b.r - 1)));
    complexnumber complex_N(N, 0, 0);
    complexmatrix ac(N, 1);
    for (int i = 1; i <= a.r; i++)
    {
        ac.dt[i][1] = a.dt[i][1];
    }
    complexmatrix bc(N, 1);
    for (int i = 1; i <= b.r; i++)
    {
        bc.dt[i][1] = b.dt[i][1];
    }
    complexmatrix A(N, 1), B(N, 1), C(N, 1);
    A = fastfouriertransform(ac, 1);
    B = fastfouriertransform(bc, 1);
    for (int i = 1; i <= N; i++)
    {
        C.dt[i][1] = A.dt[i][1] * B.dt[i][1] / complex_N;
    }
    complexmatrix cc(N, 1);
    cc = fastfouriertransform(C, -1);
    return cc;
}
int main()
{
    complexmatrix a, b, c;
    FILE *inpt;
    inpt = fopen("listconvolution.inpt", "r");
    a.fscan(inpt, 0);
    b.fscan(inpt, 0);
    fclose(inpt);

    c = listconvolution(a, b);

    FILE *oupt;
    oupt = fopen("listconvolution.oupt", "w");
    c.fprint(inpt, 0);
    fclose(oupt);

    return 0;
}
