#ifndef FIELD_POLYNOMIAL_H
#define FIELD_POLYNOMIAL_H

#include <vector>
#include <stdio.h>
#include <math.h>

#define Max(a, b) ((a > b) ? (a) : (b))
#define Abs(a, b) (((a - b) >= 0) ? (a - b) : (b - a))
#define Eps 1e-15

template <class F>
class field_polynomial
{
public:
    long long dgr;
    std::vector<F> ctf; // coefficient
    field_polynomial(long long len = -1);
    field_polynomial(F *coef, int len);
    ~field_polynomial();
    field_polynomial operator-(); // negative O(N)
    void print(int k);
    void operator=(const size_t &y);
};
template <class F>
field_polynomial<F>::field_polynomial(long long d)
{
    switch (d)
    {
    case -1:
        this->dgr = d;
        break;

    default:
        this->dgr = d;
        this->ctf.resize(d);
        break;
    }
}
template <class F>
field_polynomial<F>::field_polynomial(F *coef, int d)
{
    this->ctf.resize(d);
    for (int i = 0; i < d; i++)
    {
        this->ctf[i] = coef[i] / coef[d];
    }
}

field_polynomial operator+(const field_polynomial &x, const field_polynomial &y); // polynomial plus O(N)
field_polynomial operator-(const field_polynomial &x, const field_polynomial &y); // polynomial minus O(N)
field_polynomial operator*(const field_polynomial &x, const field_polynomial &y); // polynomial muti O(N^2)
field_polynomial operator/(const field_polynomial &x, const field_polynomial &y); // polynomial divi O(N)
field_polynomial operator%(const field_polynomial &x, const field_polynomial &y); // polynomial modu O(N)
bool operator==(const field_polynomial &x, const field_polynomial &y);            // polynomial equal O(N)
field_polynomial factorbyShie(const field_polynomial &f, const field_polynomial &h);

#endif
