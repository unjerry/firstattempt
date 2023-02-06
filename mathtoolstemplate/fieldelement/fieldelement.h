#ifndef FIELDELEMENT_H
#define FIELDELEMENT_H

template <class F>
class fieldelement
{
public:
    F dt;
    fieldelement(); // the F create default as zero element
    fieldelement(F fi);
    void print(int opt);
};
template <class F>
fieldelement<F>::fieldelement()
{
    F zero;
    dt = zero;
}
template <class F>
fieldelement<F>::fieldelement(F fi)
{
    dt = fi;
}
template <class F>
void fieldelement<F>::print(int opt)
{
    this->dt.print(opt);
}

template <class F>
fieldelement<F> operator+(const fieldelement<F> &a, const fieldelement<F> &b)
{
    fieldelement<F> c(a.dt + b.dt);
    return c;
}
template <class F>
fieldelement<F> operator-(const fieldelement<F> &a, const fieldelement<F> &b)
{
    fieldelement<F> c(a.dt - b.dt);
    return c;
}
template <class F>
fieldelement<F> operator*(const fieldelement<F> &a, const fieldelement<F> &b)
{
    fieldelement<F> c(a.dt * b.dt);
    return c;
}
template <class F>
fieldelement<F> operator/(const fieldelement<F> &a, const fieldelement<F> &b)
{
    fieldelement<F> c(a.dt / b.dt);
    return c;
}

#endif
