#include "pfield.h"

pfield::pfield(long long p)
{
    this->field_character = p;
    this->multiplication_inverse.resize(p);
    this->multiplication_inverse[0] = 0;
    this->multiplication_inverse[1] = 1;
    for (int i = 2; i < this->field_character; i++)
    {
        this->multiplication_inverse[i] = (p - ((p / i) * this->multiplication_inverse[p % i])) % p;
    }
}
