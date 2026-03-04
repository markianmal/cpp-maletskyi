#include <cstdio>
#include "Money.h"

int main()
{
    // read pairs: hours, copecks and a multiplier until EOF
    Price p;
    int q;

    while (scanf("%d %hd %d", &p.hr, &p.cop, &q) == 3)
    {
        Price result = mult(p, q);
        printP(result);
    }

    return 0;
}