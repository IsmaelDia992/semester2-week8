#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

#include "shapes.h"

/* --- Structure initialization functions --- */

Point makePoint(float x, float y) {
    Point newP;
    newP.x = x;
    newP.y = y;
    return newP;
}

Line makeLine(Point p1, Point p2) {
    Line newL;
    newL.p[0] = p1;
    newL.p[1] = p2;
    return newL;
}

Triangle makeTriangle(Point p1, Point p2, Point p3) {
    Triangle newT;
    newT.p[0] = p1;
    newT.p[1] = p2;
    newT.p[2] = p3;
    return newT;
}

/* --- Structure calculation functions --- */

float lineLength(Line l) {
    float dx = l.p[1].x - l.p[0].x;
    float dy = l.p[1].y - l.p[0].y;
    return sqrtf(dx * dx + dy * dy);
}

float triangleArea(Triangle t) {
    // Using Heron's Formula or the Shoelace Formula
    // Shoelace Formula: 0.5 * |x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2)|
    float area = 0.5f * fabsf(
        t.p[0].x * (t.p[1].y - t.p[2].y) +
        t.p[1].x * (t.p[2].y - t.p[0].y) +
        t.p[2].x * (t.p[0].y - t.p[1].y)
    );
    return area;
}

/* --- Structure comparison functions --- */

bool samePoint(Point p1, Point p2) {
    // As per header note: check if distance is "close enough"
    float dx = p1.x - p2.x;
    float dy = p1.y - p2.y;
    float dist = sqrtf(dx * dx + dy * dy);
    
    return dist < 1.0e-6f;
}

bool pointInLine(Point p, Line l) {
    // Returns true if p is either endpoint of the line
    return (samePoint(p, l.p[0]) || samePoint(p, l.p[1]));
}

bool pointInTriangle(Point p, Triangle t) {
    // Returns true if p is one of the three vertices
    return (samePoint(p, t.p[0]) || 
            samePoint(p, t.p[1]) || 
            samePoint(p, t.p[2]));
}