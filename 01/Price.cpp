#define _CRT_SECURE_NO_WARNINGS
#include "Price.h"
#include <cstdio>

void add(Price &target, const Price &other)
{
    target.hryvnia += other.hryvnia;
    target.kopecks += other.kopecks;
}

void multiply(Price &p, int quantity)
{
    p.hryvnia *= quantity;
    p.kopecks *= quantity;
}

void roundToTen(Price &p)
{
    int remainder = p.kopecks % 10;

    if (remainder < 5)
    {
        p.kopecks -= remainder;
    }
    else
    {
        p.kopecks += (10 - remainder);
    }
}

void print(const Price &p)
{

    printf("%d грн %02d коп", p.hryvnia, p.kopecks);
}

void processCheque(const char *filename)
{
    FILE *f = fopen(filename, "r");
    if (!f)
    {
        printf("Помилка файлу!\n");
        return;
    }

    Price total = {0, 0};
    Price cur;
    int qty;

    printf("--- ВАШ ЧЕК ---\n");

    while (!feof(f))
    {

        int parsed = fscanf(f, "%*s %d %hi %d", &cur.hryvnia, &cur.kopecks, &qty);

        if (parsed == 3)
        {

            if (cur.hryvnia >= 0 && cur.kopecks >= 0 && qty > 0)
            {
                multiply(cur, qty);
                add(total, cur);
            }
        
        
        }
    }
    fclose(f);

    total.hryvnia += total.kopecks / 100;
    total.kopecks %= 100;

    printf("----------------\n");
    printf("Сума: ");
    print(total);

    roundToTen(total);

    total.hryvnia += total.kopecks / 100;
    total.kopecks %= 100;

    printf("\nДо оплати: ");
    print(total);
    printf("\n");
}