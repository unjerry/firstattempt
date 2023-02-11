#ifndef LIST_CONVOLUTION_H
#define LIST_CONVOLUTION_H

#include "field_matrix.h"
#include "fast_fourier_transform.h"
#include <math.h>

field_matrix<complexnumber> list_convolution(const field_matrix<complexnumber> &a, const field_matrix<complexnumber> &b);

#endif
