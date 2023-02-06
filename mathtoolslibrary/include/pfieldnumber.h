#ifndef PFIELDNUMBER_H
#define PFIELDNUMBER_H

#include <stdio.h>

class pfieldnumber
{
public:
    long long ch;
    long long dt;
    pfieldnumber();
    pfieldnumber(long long dt, long long ch);
    void print(int opt);
    void fprint(FILE *f, int opt);
    int scan(int opt);
    int fscan(FILE *f, int opt);
};
pfieldnumber operator+(const pfieldnumber &a, const pfieldnumber &b);
pfieldnumber operator-(const pfieldnumber &a, const pfieldnumber &b);
pfieldnumber operator*(const pfieldnumber &a, const pfieldnumber &b);
pfieldnumber operator/(const pfieldnumber &a, const pfieldnumber &b);
bool operator==(const pfieldnumber &a, const pfieldnumber &b);

#endif
