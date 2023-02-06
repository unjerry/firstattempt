#include "pfieldnumber.h"

pfieldnumber::pfieldnumber()
{
    this->dt = 0;
    this->ch = 2;
}
pfieldnumber::pfieldnumber(long long dt, long long ch)
{
    this->ch = ch;
    this->dt = dt % ch;
}

void pfieldnumber::print(int opt)
{
    printf("<%lld>(p=%lld)", this->dt, this->ch);
}
void pfieldnumber::fprint(FILE *f, int opt)
{
    fprintf(f, "<%lld>(p=%lld)", this->dt, this->ch);
}
int pfieldnumber::scan(int opt)
{
    int rt;
    scanf("%*[^<]");
    rt = scanf("<%lld>(p=%lld)", &this->dt, &this->ch);
    return rt;
}
int pfieldnumber::fscan(FILE *f, int opt)
{
    int rt;
    fscanf(f, "%*[^<]");
    rt = fscanf(f, "<%lld>(p=%lld)", &this->dt, &this->ch);
    return rt;
}

pfieldnumber operator+(const pfieldnumber &a, const pfieldnumber &b)
{
    long long p = a.ch;
    pfieldnumber c((a.dt + b.dt + p) % p, a.ch);
    return c;
}
pfieldnumber operator-(const pfieldnumber &a, const pfieldnumber &b)
{
    long long p = a.ch;
    pfieldnumber c((a.dt - b.dt + p) % p, a.ch);
    return c;
}
pfieldnumber operator*(const pfieldnumber &a, const pfieldnumber &b)
{
    long long p = a.ch;
    pfieldnumber c((a.dt * b.dt) % p, a.ch);
    return c;
}
long long extended_euclidean(long long a, long long b, long long &x, long long &y)
{
    long long d;
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    d = extended_euclidean(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
pfieldnumber operator/(const pfieldnumber &a, const pfieldnumber &b)
{
    long long p = a.ch;
    long long bv, y;
    extended_euclidean(b.dt, p, bv, y);
    bv = (bv + p) % p;
    pfieldnumber c((a.dt * bv + p) % p, a.ch);
    return c;
}
bool operator==(const pfieldnumber &a, const pfieldnumber &b)
{
    return (a.dt == b.dt);
}
