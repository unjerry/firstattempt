#ifndef Z_H
#define Z_H

#include "G.h"

class Z : public G
{
public:
    long long dt;
    Z(long long x = 0);
    ~Z();
    virtual Z *multiplication(const Z &x, const Z &y)
    {
        printf("Zmult\n");
        Z *z = new Z(x.dt + y.dt);
        return z;
    }
    virtual void print(int opt = 0)
    {
        printf("%lld\n", this->dt);
    }
    // virtual Z operator*(const Z &x);
};

#endif
