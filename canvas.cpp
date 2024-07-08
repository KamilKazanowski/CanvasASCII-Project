#include "canvas.h"
#include "figure.h"
#include <iostream>
#include <cstring>

Canvas::Canvas (int a, int b) {
    if (a < 3 || b < 3 || a > 50 || b > 50) {
        std::cerr << "Podano nieprawidlowe wymiary plotna." << std::endl;
        exit(-1);
    }
    width = a;
    height = b;
}

CanvasASCII::CanvasASCII (int w, int h, char c) : Canvas(w, h) {
    ptr = new char *[h];

    for (int i = 0; i < h; i++) {
        ptr[i] = new char [w];
    }

    ptr[0][0] = '|';
    for(int i = 1; i + 1 < w; i++){
        ptr[0][i] = '=';
    }
    ptr[0][w-1] = '|';

    strcpy(ptr[h-1], ptr[0]);

    ptr[1][0] = '|';
    for(int i = 1; i + 1 < w; i++){
        ptr[1][i] = c;
    }
    ptr[1][w-1] = '|';

    for(int i = 2; i + 1 < h; i++){
        strcpy(ptr[i], ptr[1]);
    }

    for(int i = 0; i < h; i++){
        ptr[i][w] = '\0';
    }
}; 

CanvasASCII::~CanvasASCII () {
    for(int i = 0; i < height; i++){
        delete [] ptr[i];
    }
    delete [] ptr;
};

void CanvasASCII::print() {
    for(int i = height - 1; i >=0; i--){
        if (i > 9) {
            std::cout << i << ": ";
        } else {
            std::cout << i << ":  " ;
        }
        std::cout << ptr[i] << std::endl;
    }

    std::cout << "    ";
    for(int i = 0; i < width && i < 13; i++){
        std::cout << i;
    }
    std::cout << std::endl;
}

bool CanvasASCII::isCanvasMem (int a, int b) {
    if (a <= 0 || b <= 0 || a >= width - 1 || b >= height - 1){
        return 0;
    }
    return 1;
}

char CanvasASCII::getCanvasMem (int i, int j) {
    return ptr[i][j];
}