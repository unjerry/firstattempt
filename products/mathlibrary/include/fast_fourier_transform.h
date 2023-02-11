#ifndef FAST_FOURIER_TRANSFORM_H
#define FAST_FOURIER_TRANSFORM_H

#include "field_matrix.h"
#include "complexnumber.h"
#include <math.h>

#define PI acos(-1)

field_matrix<complexnumber> fast_fourier_transform_of_power_two(field_matrix<complexnumber> P, int opt);
field_matrix<complexnumber> fast_fourier_transform(field_matrix<complexnumber> P, int opt);

#endif
