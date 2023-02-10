#include "Z.h"

Z::Z(long long x)
{
    printf("Z()\n");
    this->dt = x;
}
Z::~Z()
{
    printf("~Z()\n");
}

/*
Z *Z::operator*(const Z &x)
{
    Z *z = new Z(this->dt + x.dt);
    return z;
}
*/
