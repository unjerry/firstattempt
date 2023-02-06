#include "fieldelement.h"
#include "complexnumber.h"
int main()
{
    fieldelement<complexnumber> a;
    fieldelement<complexnumber> b;
    a.print(0);
    a.print(1);
    return 0;
}
