#ifndef MONEY_H
#define MONEY_H
struct Price
{
    int hr;
    short cop;
};
Price add(Price p1, Price p2);
Price mult(Price p, int q);
Price roundP(Price p);
void printP(Price p);
#endif