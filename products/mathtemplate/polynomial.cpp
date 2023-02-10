#include "polynomial.h"
pn::~pn()
{
}
pn pn::operator-() // negative O(N)
{
    pn x = *this;
    for (int i = 0; i < x.ctf.size(); i++)
    {
        x.ctf[i] = -x.ctf[i];
    }
    return x;
}
void pn::print(int k) // k=1 coefficient k=2 polynomial
{
    switch (k)
    {
    case 1:
        printf("<%.3lf", this->ctf[0]);
        for (int i = 1; i < this->ctf.size(); i++)
        {
            printf(",%.3lf", this->ctf[i]);
        }
        printf(">");
        break;

    default:
        break;
    }
}
void pn::operator=(const size_t &y)
{
    switch (y)
    {
    case 1:
        this->ctf.resize(1);
        this->ctf[0] = 1;
        break;

    default:
        this->ctf.resize(1);
        this->ctf[0] = 0;
        break;
    }
}
pn operator+(const pn &x, const pn &y) // polynomial plus O(N)
{
    pn z;
    z.ctf.resize(Max(x.ctf.size(), y.ctf.size()));
    for (int i = 0; i < z.ctf.size(); i++)
    {
        z.ctf[i] = x.ctf[i] + y.ctf[i];
    }
    for (int i = z.ctf.size() - 1; i >= 0; i--)
    {
        if (Abs(z.ctf[i], 0) > Eps)
        {
            z.ctf.resize(i + 1);
            break;
        }
        if (i == 0)
        {
            z.ctf.resize(i + 1);
            break;
        }
    }
    return z;
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
pn operator/(const pn &x, const pn &y) // polynomial divi O(N^2)
{
    pn z;
    pn xx = x;
    int degx = x.ctf.size() - 1;
    int degy = y.ctf.size() - 1;
    int degz = degx - degy;
    z.ctf.resize(degz + 1);
    double leady = y.ctf[degy];
    for (int i = degz; i >= 0; i--)
    {
        z.ctf[i] = xx.ctf[i + degy] / leady;
        for (int j = degy; j >= 0; j--)
        {
            xx.ctf[i + j] -= y.ctf[j] * z.ctf[i];
        }
    }
    return z;
}
pn operator%(const pn &x, const pn &y) // polynomial modu O(N^2)
{
    pn z;
    pn xx = x;
    int degx = x.ctf.size() - 1;
    int degy = y.ctf.size() - 1;
    int degz = degx - degy;
    z.ctf.resize(degz + 1);
    double leady = y.ctf[degy];
    for (int i = degz; i >= 0; i--)
    {
        z.ctf[i] = xx.ctf[i + degy] / leady;
        for (int j = degy; j >= 0; j--)
        {
            xx.ctf[i + j] -= y.ctf[j] * z.ctf[i];
        }
    }
    for (int i = degx; i >= 0; i--)
    {
        if (Abs(xx.ctf[i], 0) > Eps)
        {
            xx.ctf.resize(i + 1);
            break;
        }
        if (i == 0)
        {
            xx.ctf.resize(i + 1);
            break;
        }
    }
    return xx;
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
