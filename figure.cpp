#include "canvas.h"
#include "figure.h"
#include <iostream>
#include <cstring>
#include <math.h>

void Rectangle::draw (CanvasASCII &c) {
    for (int i = 0; i < width; i++){
        for (int j = 0; j < heigth; j++){
            if (c.isCanvasMem(xCoordinate + i, yCoordinate + j))
                c.ptr[yCoordinate + j][xCoordinate + i] = member;
        }
    }
}

void Circle::draw (CanvasASCII &c) {
    float t1 = 0;
    float t2 = 0;
    float t3 = 0;

    for (int i = xCoordinate - radius; i <= xCoordinate + radius; i++){
        for (int j = yCoordinate - radius; j <= yCoordinate + radius; j++){
            if (c.isCanvasMem(i, j)) {
                t1 = abs(xCoordinate - i);
                t1 *= t1;
                t2 = abs(yCoordinate - j);
                t2 *= t2;
                t3 = sqrt(t1 + t2);
                if (t3 <= radius) {
                    c.ptr[j][i] = member;
                } 
            }
        }
    }
}