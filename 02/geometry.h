#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <iostream>
#include <cmath>
#include <string>

struct Point {
    double x, y;
};

struct Triangle {
    Point A, B, C; 

    double crossProduct(Point p1, Point p2, Point p3) const {
        return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
    }

    double distance(Point p1, Point p2) const {
        return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
    }

    double heronArea(Point p1, Point p2, Point p3) const {
        double a = distance(p1, p2);
        double b = distance(p2, p3);
        double c = distance(p3, p1);
        double s = (a + b + c) / 2.0;
        
        double val = s * (s - a) * (s - b) * (s - c);
        if (val < 0) val = 0.0; 
        
        return std::sqrt(val);
    }

    bool isDegenerate() const { 
        return std::abs(crossProduct(A, B, C)) < 1e-9; 
    }
    
    int checkPointVector(Point p, std::string& ruleText) const; 
    int checkPointHeron(Point p, std::string& ruleText) const; 

    void showPoints() const {
        std::cout << "  A (" << A.x << ", " << A.y << ")\n"
                  << "  B (" << B.x << ", " << B.y << ")\n"
                  << "  C (" << C.x << ", " << C.y << ")\n";
    }
};

#endif