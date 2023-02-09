#include "fieldelement.h"
#include "complexnumber.h"
#include <vector>
int main()
{
    //int lst[100000];
    std::vector<int> clst;
    clst.resize(1000000000);

    fieldelement<complexnumber> a;
    fieldelement<complexnumber> b;
    a.print(0);
    a.print(1);
    return 0;
}
