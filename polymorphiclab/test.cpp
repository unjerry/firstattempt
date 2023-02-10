#include "Z.h"
#include "ApB.h"

int main()
{
    G *z1, *z2, *z3;
    z1 = new Z(4);
    z2 = new Z(3);
    z1->print();
    z2->print();

    z3 = ApB(z1, z2);
    z3->print();

    delete (z1);
    delete (z2);
    return 0;
}
