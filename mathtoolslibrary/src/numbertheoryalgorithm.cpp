#include "numbertheoryalgorithm.h"

template <class Z>
Z extended_euclidean(Z a, Z b, Z &x, Z &y)
{
    Z d;
    Z zero;
    zero = 0;
    if (b == zero)
    {
        x = 1;
        y = 0;
        return a;
    }
    d = extended_euclidean(b, a % b, y, x);
    y = y - (a / b * x);
    return d;
}
