// Z represent Zrhng
// Z should contain
/*
operator==
*/
#include <stddef.h>
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

template <class G>
G fast_power(G a, size_t b)
{
    G ans;
    ans = 1;
    G res = a;
    while (b)
    {
        if (b % 2 == 1)
        {
            ans = ans * a;
        }
        a = a * a;
        b = b / 2;
    }
    return ans;
}
