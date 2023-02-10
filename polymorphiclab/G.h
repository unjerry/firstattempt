#ifndef G_H
#define G_H

#include <stdio.h>

class G
{
public:
    G();
    ~G();
    virtual G *multiplication(const G &x, const G &y)
    {
        G *g = new G;
        return g;
    }
    virtual void print(int opt = 0)
    {
        printf("Gprint\n");
    }
};

#endif
