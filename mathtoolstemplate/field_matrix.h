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
    int scan(int opt);
    int fscan(FILE *f, int opt);
    virtual fieldmatrix<F> operator*(const fieldmatrix<F> &x);
};
template <class F>
fieldmatrix<F>::fieldmatrix()
{
    this->r = 0;
    this->c = 0;
    this->dt.resize(0);
}
template <class F>
fieldmatrix<F>::fieldmatrix(const long long r, const long long c)
{
    this->r = r;
    this->c = c;
    this->dt.resize(r + 1);
    for (int i = 1; i <= r; i++)
    {
        this->dt[i].resize(c + 1);
        for (int j = 1; j <= this->c; j++)
        {
            F zero;
            dt[i][j] = zero;
        }
    }
}
template <class F>
void fieldmatrix<F>::print(int opt)
{
    printf("[%d,%d\n", r, c);
    if (r * c != 0)
    {
        for (int i = 1; i <= this->r; i++)
        {
            for (int j = 1; j <= this->c; j++)
            {
                this->dt[i][j].print(opt);
                printf(",");
            }
            printf("\n");
        }
    }
    else
    {
        printf("NULLMATRIX\n");
    }
    printf("]\n");
}
template <class F>
void fieldmatrix<F>::fprint(FILE *f, int opt)
{
    fprintf(f, "[%d,%d\n", r, c);
    if (r * c != 0)
    {
        for (int i = 1; i <= this->r; i++)
        {
            for (int j = 1; j <= this->c; j++)
            {
                this->dt[i][j].fprint(f, opt);
                fprintf(f, ",");
            }
            fprintf(f, "\n");
        }
    }
    else
    {
        fprintf(f, "NULLMATRIX\n");
    }
    fprintf(f, "]\n");
}
template <class F>
int fieldmatrix<F>::scan(int opt)
{
    int rt;
    scanf("%*[^[]");
    rt = scanf("[%d,%d\n", &this->r, &this->c);
    this->dt.resize(r + 1);
    for (int i = 1; i <= r; i++)
    {
        this->dt[i].resize(c + 1);
    }
    if (r * c != 0)
    {
        for (int i = 1; i <= this->r; i++)
        {
            for (int j = 1; j <= this->c; j++)
            {
                this->dt[i][j].scan(opt);
                scanf(",");
            }
            scanf("\n");
        }
    }
    else
    {
        scanf("NULLMATRIX\n");
    }
    scanf("]\n");
    return rt;
}
template <class F>
int fieldmatrix<F>::fscan(FILE *f, int opt)
{
    int rt;
    fscanf(f, "%*[^[]");
    rt = fscanf(f, "[%d,%d\n", &this->r, &this->c);
    this->dt.resize(r + 1);
    for (int i = 1; i <= r; i++)
    {
        this->dt[i].resize(c + 1);
    }
    if (r * c != 0)
    {
        for (int i = 1; i <= this->r; i++)
        {
            for (int j = 1; j <= this->c; j++)
            {
                this->dt[i][j].fscan(f, opt);
                fscanf(f, ",");
            }
            fscanf(f, "\n");
        }
    }
    else
    {
        fscanf(f, "NULLMATRIX\n");
    }
    fscanf(f, "]\n");
    return rt;
}

template <class F>
fieldmatrix<F> fieldmatrix<F>::operator*(const fieldmatrix<F> &x)
{
    if (this->c == x.r)
    {
        fieldmatrix<F> c(this->r, x.c);
        for (int i = 1; i <= c.r; i++)
        {
            for (int j = 1; j <= c.c; j++)
            {
                for (int k = 1; k <= this->c; k++)
                {
                    c.dt[i][j] = c.dt[i][j] + (this->dt[i][k] * x.dt[k][j]);
                }
            }
        }
        return c;
    }
    else
    {
        fieldmatrix<F> c;
        return c;
    }
}
template <class F>
fieldmatrix<F> rowechelon(const fieldmatrix<F> &x)
{
    fieldmatrix<F> M = x;
    // printf("m\n");
    // M.print(0);
    const F zero;
    int r = 1;
    int c = 1;
    int tr;
    int tc;
    F tmp;
    while (1)
    {
        if (r > M.r || c > M.c)
        {
            break;
        }
        // printf("%d %d\n", r, c);
        tr = tc = 0;
        for (int j = c; j <= M.c; j++)
        {
            if (tr != 0)
            {
                break;
            }
            for (int i = r; i <= M.r; i++)
            {
                if (!(M.dt[i][j] == zero))
                {
                    tr = i;
                    tc = j;
                    break;
                }
            }
        }
        if (tr == 0)
        {
            break;
        }
        // printf("tr=%d tc=%d\n", tr, tc);
        //   exchange
        for (int j = tc; j <= M.c; j++)
        {
            tmp = M.dt[r][j];
            M.dt[r][j] = M.dt[tr][j];
            M.dt[tr][j] = tmp;
        }
        tmp = M.dt[r][tc];
        for (int j = tc; j <= M.c; j++)
        {
            M.dt[r][j] = M.dt[r][j] / tmp;
        }
        for (int i = 1; i <= M.r; i++)
        {
            if (i == r)
            {
                continue;
            }
            tmp = M.dt[i][tc];
            for (int j = tc; j <= M.c; j++)
            {
                M.dt[i][j] = M.dt[i][j] - M.dt[r][j] * tmp;
            }
        }
        // M.print(0);
        // printf("%dr\n", r);
        r += 1;
        c = tc + 1;
    }
    return M;
}
template <class F>
fieldmatrix<F> columnechelon(const fieldmatrix<F> &x) // can be replace by transpose & rowechelon
{
    fieldmatrix<F> M = x;
    // printf("m\n");
    // M.print(0);
    const F zero;
    int r = 1;
    int c = 1;
    int tr;
    int tc;
    F tmp;
    while (1)
    {
        if (r > M.r || c > M.c)
        {
            break;
        }
        // printf("%d %d\n", r, c);
        tr = tc = 0;
        for (int i = r; i <= M.r; i++)
        {
            if (tr != 0)
            {
                break;
            }
            for (int j = c; j <= M.c; j++)
            {
                if (!(M.dt[i][j] == zero))
                {
                    tr = i;
                    tc = j;
                    break;
                }
            }
        }
        if (tr == 0)
        {
            break;
        }
        // printf("tr=%d tc=%d\n", tr, tc);
        //   exchange
        for (int i = tr; i <= M.r; i++)
        {
            tmp = M.dt[i][c];
            M.dt[i][c] = M.dt[i][tc];
            M.dt[i][tc] = tmp;
        }
        tmp = M.dt[tr][c];
        for (int i = tr; i <= M.r; i++)
        {
            M.dt[i][c] = M.dt[i][c] / tmp;
        }
        for (int j = 1; j <= M.c; j++)
        {
            if (j == c)
            {
                continue;
            }
            tmp = M.dt[tr][j];
            for (int i = tr; i <= M.r; i++)
            {
                M.dt[i][j] = M.dt[i][j] - M.dt[i][c] * tmp;
            }
        }
        // M.print(0);
        // printf("%dr\n", r);
        c += 1;
        r = tr + 1;
    }
    return M;
}
template <class F>
fieldmatrix<F> inverse(const fieldmatrix<F> &x) // not ready and im tendto make it a sudoinverse
{
    fieldmatrix<F> M = x;
    // printf("m\n");
    // M.print(0);
    const F zero;
    int r = 1;
    int c = 1;
    int tr;
    int tc;
    F tmp;

    // for(int i=)

    while (1)
    {
        if (r > M.r || c > M.c)
        {
            break;
        }
        // printf("%d %d\n", r, c);
        tr = tc = 0;
        for (int j = c; j <= M.c; j++)
        {
            if (tr != 0)
            {
                break;
            }
            for (int i = r; i <= M.r; i++)
            {
                if (!(M.dt[i][j] == zero))
                {
                    tr = i;
                    tc = j;
                    break;
                }
            }
        }
        if (tr == 0)
        {
            break;
        }
        // printf("tr=%d tc=%d\n", tr, tc);
        //   exchange
        for (int j = tc; j <= M.c; j++)
        {
            tmp = M.dt[r][j];
            M.dt[r][j] = M.dt[tr][j];
            M.dt[tr][j] = tmp;
        }
        tmp = M.dt[r][tc];
        for (int j = tc; j <= M.c; j++)
        {
            M.dt[r][j] = M.dt[r][j] / tmp;
        }
        for (int i = 1; i <= M.r; i++)
        {
            if (i == r)
            {
                continue;
            }
            tmp = M.dt[i][tc];
            for (int j = tc; j <= M.c; j++)
            {
                M.dt[i][j] = M.dt[i][j] - M.dt[r][j] * tmp;
            }
        }
        // M.print(0);
        // printf("%dr\n", r);
        r += 1;
        c = tc + 1;
    }
    return M;
}
template <class F>
fieldmatrix<F> equivalentnormalizedform(const fieldmatrix<F> &x)
{
    return columnechelon(rowechelon(x));
}
#endif
