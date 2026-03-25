#pragma once

struct Price
{
    int hryvnia;
    short int kopecks;
};

void add(Price &target, const Price &other);
void multiply(Price &p, int quantity);
void roundToTen(Price &p);
void print(const Price &p);

void processCheque(const char *filename);