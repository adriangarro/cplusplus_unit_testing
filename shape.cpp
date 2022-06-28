#include <iostream>
#include <vector>

using std::cout;
using std::string;
using std::vector;

class Shape {
public:
    virtual void draw() = 0;
};

class Circle : public Shape {
public:
    Circle() = default;

    void draw() override {
        cout << "circle\n";
    }
};

class Triangle : public Shape {
public:
    Triangle() = default;

    void draw() override {
        cout << "triangle\n";
    }
};

class Drawing {
private:
    Shape *shape = nullptr;
public:
    explicit Drawing(Shape *pShape) {
        shape = pShape;
    }

    void drawShape()
    {
        if (shape != nullptr) {
            shape->draw();
        }
    }
};

class IDrawing {
private:
    Drawing* drawing = nullptr;
public:
    explicit IDrawing(const string& s) {
        if (s == "triangle")
            drawing = new Drawing(new Triangle());
        else if( s == "circle")
            drawing = new Drawing(new Circle());
        else
            cout << " Need shape";
    }

    ~IDrawing() {
        delete drawing;
    }

    void draw() {
        if (drawing != nullptr) {
            drawing->drawShape();
        }
    }

};

int main() {
    auto i = IDrawing{"circle"};
    i.draw();
}
