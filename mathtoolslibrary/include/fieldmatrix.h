#ifndef FIELDMATRIX_H
#define FIELDMATRIX_H

#include <vector>
#include <stdio.h>

template <class F>
class fieldmatrix
{
public:
    long long r, c;
    std::vector<std::vector<F>> dt;
    fieldmatrix();
    fieldmatrix(const long long r, const long long c);
    void print(int opt);
    void fprint(FILE *f, int opt);
    void scan(int opt);
    void fscan(FILE *f, int opt);
};
template <class F>
fieldmatrix<F> operator*(const fieldmatrix<F> &a, const fieldmatrix<F> &b);
template <class F>
fieldmatrix<F> rowechelon(const fieldmatrix<F> &x);
template <class F>
fieldmatrix<F> columnechelon(const fieldmatrix<F> &x); // can be replace by transpose & rowechelon
template <class F>
fieldmatrix<F> inverse(const fieldmatrix<F> &x);
template <class F>
fieldmatrix<F> equivalentnormalizedform(const fieldmatrix<F> &x);
#endif
