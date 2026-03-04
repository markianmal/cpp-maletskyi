#include <cstdio>
#include "Money.h"

Price add(Price p1, Price p2)
{
    int total = (p1.hr + p2.hr) * 100 + p1.cop + p2.cop;
    return {total / 100, (short)(total % 100)};
}

Price mult(Price p, int q)
{
    long total = (p.hr * 100L + p.cop) * q;
    return {(int)(total / 100), (short)(total % 100)};
}

Price roundP(Price p)
{
    int r = p.cop % 10;
    if (r > 0 && r < 5)
        p.cop -= r;
    else if (r >= 5)
        p.cop += (10 - r);
    if (p.cop == 100)
    {
        p.hr++;
        p.cop = 0;
    }
    return p;
}

void printP(Price p) { printf("%d hr %02d cop\n", p.hr, p.cop); }