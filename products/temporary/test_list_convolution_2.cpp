#include "complexnumber.h"
#include "list_convolution.h"
#include <vector>

int main()
{
    std::vector<complexnumber> a, b, c;
    complexnumber one(1, 0), two(2, 0), three(3, 0);

    a.resize(3);
    a[0] = one;
    a[1] = two;
    a[2] = three;
    printf("a=[%d\n", a.size());
    for (int i = 0; i < a.size(); i++)
    {
        a[i].print();
        printf("\n");
    }
    printf("]\n");

    b.resize(3);
    b[0] = three;
    b[1] = two;
    b[2] = one;
    printf("b=[%d\n", b.size());
    for (int i = 0; i < b.size(); i++)
    {
        b[i].print();
        printf("\n");
    }
    printf("]\n");

    c = list_convolution(a, b);

    printf("c=[%d\n", c.size());
    for (int i = 0; i < c.size(); i++)
    {
        c[i].print();
        printf("\n");
    }
    printf("]\n");

    return 0;
}
