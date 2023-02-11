#include "polynomial.h"
pn::~pn()
{
}
pn operator-(const pn &x, const pn &y) // polynomial minu O(N)
{
    pn z = y;
    return x + (-z);
}
pn operator*(const pn &x, const pn &y) // polynomial muti O(N^2)
{
    pn z;
    z.ctf.resize(x.ctf.size() + y.ctf.size() - 2 + 1);
    for (int i = 0; i < x.ctf.size(); i++)
    {
        for (int j = 0; j < y.ctf.size(); j++)
        {
            z.ctf[i + j] += x.ctf[i] * y.ctf[j];
        }
    }
    return z;
}
bool operator==(const pn &x, const pn &y) // polynomial equal O(N)
{
    if (x.ctf.size() != y.ctf.size())
    {
        return 0;
    }
    for (int i = 0; i < x.ctf.size(); i++)
    {
        if (Abs(x.ctf[i], y.ctf[i]) >= Eps)
        {
            return 0;
        }
    }
    return 1;
}

pn factorbyShie(const pn &f, const pn &h)
{
    pn r, g, rq, rp, X;
    pn hh = h;
    hh.print(1);
    double dr;
    double ds;
    double dp = 1;
    double dq = 1;
    double drdq;
    double dsdq;
    double drdp;
    double dsdp;
    X.ctf.resize(2);
    X.ctf[1] = 1;
    X.ctf[0] = 0;
    while (Abs(dp, 0) > Eps || Abs(dq, 0) > Eps)
    {
        r = f % hh;
        g = f / hh;
        // printf("r=");
        // r.print(1);
        // printf("\n");
        // printf("g=");
        // g.print(1);
        // printf("\n");
        dr = -r.ctf[1];
        ds = -r.ctf[0];
        rp = (X * g) % hh;
        // printf("rp=");
        // rp.print(1);
        // printf("\n");
        drdp = -rp.ctf[1];
        dsdp = -rp.ctf[0];
        rq = g % hh;
        // printf("rq=");
        // rq.print(1);
        // printf("\n");
        drdq = -rq.ctf[1];
        dsdq = -rq.ctf[0];
        if (Abs((drdp * dsdq - drdq * dsdp), 0) < Eps)
        {
            break;
        }
        dq = (drdp * ds - dr * dsdp) / (drdp * dsdq - drdq * dsdp);
        dp = (dr * dsdq - drdq * ds) / (drdp * dsdq - drdq * dsdp);
        // printf("dp=%lf\ndq=%lf\n", dp, dq);
        hh.ctf[1] += dp;
        hh.ctf[0] += dq;
        // printf("hh=");
        // hh.print(1);
        // printf("\n");
    }
    return hh;
}
