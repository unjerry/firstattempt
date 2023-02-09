#ifndef SQUARE_MATRIX_H
#define SQUARE_MATRIX_H

#include "fieldmatrix.h"

template <class F, size_t N>
class square_matrix : public fieldmatrix<F>
{
public:
    square_matrix();
    square_matrix(const fieldmatrix<F> &x);
    void operator=(const size_t &x);
};

template <class F, size_t N>
square_matrix<F, N>::square_matrix() : fieldmatrix<F>::fieldmatrix(N, N) {}

template <class F, size_t N>
void square_matrix<F, N>::operator=(const size_t &x)
{
    switch (x)
    {
    case 1:
        for (int i = 1; i <= this->r; i++)
        {
            for (int j = 1; j <= this->c; j++)
            {
                if (i == j)
                {
                    this->dt[i][j] = 1;
                }
                else
                {
                    this->dt[i][j] = 0;
                }
            }
        }
        break;

    default:
        for (int i = 1; i <= this->r; i++)
        {
            for (int j = 1; j <= this->c; j++)
            {
                this->dt[i][j] = 0;
            }
        }
        break;
    }
}

template <class F, size_t N>
square_matrix<F, N>::square_matrix(const fieldmatrix<F> &x)
{
    this->r = this->c = x.r;
    this->dt = x.dt;
}
#endif
