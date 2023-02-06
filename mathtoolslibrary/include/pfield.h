#ifndef PFIELD_H
#define PFIELD_H

#include <vector>

class pfield
{
public:
    long long field_character;
    std::vector<long long> multiplication_inverse;
    pfield(long long p);
};

#endif
