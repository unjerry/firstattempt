#include "G.h"

G *ApB(G *A, G *B)
{
    G *g;
    using Z::mul
    g = (*A).multiplication(*A, *B);
    return g;
}
