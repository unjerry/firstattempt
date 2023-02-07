#ifndef PN_H
#define PN_H

#include <vector>
#include <stdio.h>
#include <math.h>

#define Max(a, b) ((a > b) ? (a) : (b))
#define Abs(a, b) (((a - b) >= 0) ? (a - b) : (b - a))
#define Eps 1e-15

class pn
{
public:
    std::vector<double> ctf; // coefficient
    pn();
    pn(double *coef, int len);
    ~pn();
    pn operator-(); // negative O(N)
    void print(int k);
    void operator=(const size_t &y);
};
pn operator+(const pn &x, const pn &y);    // polynomial plus O(N)
pn operator-(const pn &x, const pn &y);    // polynomial minus O(N)
pn operator*(const pn &x, const pn &y);    // polynomial muti O(N^2)
pn operator/(const pn &x, const pn &y);    // polynomial divi O(N)
pn operator%(const pn &x, const pn &y);    // polynomial modu O(N)
bool operator==(const pn &x, const pn &y); // polynomial equal O(N)
pn factorbyShie(const pn &f, const pn &h);

#endif
