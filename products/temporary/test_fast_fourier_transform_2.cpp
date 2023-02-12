#include "complexnumber.h"
#include "fast_fourier_transform.h"
#include <vector>

int main()
{
    std::vector<complexnumber> a, b, c, A, B, C;
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

    A = fast_fourier_transform(a, 1);
    printf("A=[%d\n", A.size());
    for (int i = 0; i < b.size(); i++)
    {
        A[i].print();
        printf("\n");
    }
    printf("]\n");

    B = fast_fourier_transform(b, 1);
    printf("B=[%d\n", c.size());
    for (int i = 0; i < B.size(); i++)
    {
        B[i].print();
        printf("\n");
    }
    printf("]\n");

    printf("c=[%d\n", c.size());
    for (int i = 0; i < c.size(); i++)
    {
        b[i].print();
        printf("\n");
    }
    printf("]\n");

    return 0;
}
