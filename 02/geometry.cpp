#include "geometry.h"
#include <cmath>
#include <algorithm>

using namespace std;

int Triangle::checkPointVector(Point p, string& ruleText) const {
    ruleText = "Метод векторних добутків";

    double minX = min(min(A.x, B.x), C.x);
    double maxX = max(max(A.x, B.x), C.x);
    double minY = min(min(A.y, B.y), C.y);
    double maxY = max(max(A.y, B.y), C.y);

    if (p.x < minX - 1e-7 || p.x > maxX + 1e-7 || p.y < minY - 1e-7 || p.y > maxY + 1e-7) {
        return -1; 
    }

    double cp1 = crossProduct(A, B, p);
    double cp2 = crossProduct(B, C, p);
    double cp3 = crossProduct(C, A, p);
    
    bool hasPos = (cp1 > 1e-9) || (cp2 > 1e-9) || (cp3 > 1e-9);
    bool hasNeg = (cp1 < -1e-9) || (cp2 < -1e-9) || (cp3 < -1e-9);
    bool hasZero = abs(cp1) <= 1e-9 || abs(cp2) <= 1e-9 || abs(cp3) <= 1e-9;

    if (hasPos && hasNeg) return -1; 
    if (hasZero) return 0;           
    return 1;                        
}

int Triangle::checkPointHeron(Point p, string& ruleText) const {
    ruleText = "Метод площ (Формула Герона)";

    double minX = min(min(A.x, B.x), C.x);
    double maxX = max(max(A.x, B.x), C.x);
    double minY = min(min(A.y, B.y), C.y);
    double maxY = max(max(A.y, B.y), C.y);

    if (p.x < minX - 1e-7 || p.x > maxX + 1e-7 || p.y < minY - 1e-7 || p.y > maxY + 1e-7) {
        return -1; 
    }

    double S_main = heronArea(A, B, C);
    double S1 = heronArea(A, B, p);
    double S2 = heronArea(B, C, p);
    double S3 = heronArea(C, A, p);

    double sum = S1 + S2 + S3;

    if (abs(S_main - sum) > 1e-7) {
        return -1; 
    }

    if (S1 < 1e-7 || S2 < 1e-7 || S3 < 1e-7) {
        return 0; 
    }

    return 1; 
}