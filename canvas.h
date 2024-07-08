#ifndef CANVAS_H
#define CANVAS_H

#include <iostream>

class Canvas {
    protected:
        int width;
        int height;

    public:
        Canvas () = delete;
        Canvas (int a, int b);
        virtual ~Canvas () {};

        virtual void print() = 0; 
};

class CanvasASCII : public Canvas {
    friend class Rectangle;
    friend class Circle;
    private:
        char **ptr = nullptr;

    public:
        CanvasASCII () = delete;
        CanvasASCII (int a, int b, char c);
        ~CanvasASCII ();
        CanvasASCII& operator= (const CanvasASCII&) = delete;

        void print() override;
        bool isCanvasMem (int x, int y);
        char getCanvasMem (int i, int j);
};

#endif