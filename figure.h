#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>

class Figure {
    protected:
        int xCoordinate = 0;
        int yCoordinate = 0;
        char member = '#';
    
    public:
        Figure (int a, int b, char c) : xCoordinate(a), yCoordinate(b), member(c) {};
        virtual ~Figure () {};

        virtual void draw (CanvasASCII&) = 0;
};

class Rectangle : public Figure {
    protected:
        int width = 0;
        int heigth = 0;

    public:
        Rectangle (int x, int y, int a, int b, char c) : Figure(x, y, c) {
            if (a < 1 || b < 1) {
                std::cerr << "Niepoprawne wymiary prostokata." << std::endl;
                exit(-1);
            }
            width = a; 
            heigth = b;
        };
        ~Rectangle () {};

        void draw (CanvasASCII&) override;
};

class Square : public Rectangle {
    public:
        Square (int x, int y, int a, char c) : Rectangle(x, y, a, a, c) {};
        ~Square () {};
};

class Circle : public Figure {
    private:
        int radius = 0;

    public:
        Circle (int x, int y, int a, char c) : Figure(x, y, c) {
            if (a < 1) {
                std::cerr << "Niepoprawny promien kola." << std::endl;
                exit(-1);
            }
            radius = a;
        };
        ~Circle () {};

        void draw (CanvasASCII&) override;
};

#endif