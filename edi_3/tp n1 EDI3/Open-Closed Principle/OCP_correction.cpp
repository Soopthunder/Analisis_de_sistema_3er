#include <iostream>

class Shape{
public:
    Shape();
    virtual void drawShape()=0;
    void common();
    ~Shape();
};

Shape::Shape(){
    std::cout<<"I'm creating a shape."<<std::endl;
}

Shape::~Shape(){
    std::cout<<"I'm destroying a shape."<<std::endl;
}

void Shape::common(){
    std::cout<<"I'm drawing a shape. ";
}

class Rectangle:public Shape{
public:
    Rectangle();
    void drawShape();
    ~Rectangle();
};

class Circle:public Shape{
public:
    Circle();
    void drawShape();
    ~Circle();
};

Rectangle::Rectangle(){
    std::cout<<"I'm creating a rectangle."<<std::endl;
}

Circle::Circle(){
    std::cout<<"I'm creating a circle."<<std::endl;
}

Rectangle::~Rectangle(){
    std::cout<<"I'm destroying a rectangle."<<std::endl;
}

Circle::~Circle(){
    std::cout<<"I'm destroying a circle."<<std::endl;
}

void Rectangle::drawShape(){
    Rectangle::common();
    std::cout<<"It's a rectangle."<<std::endl;
}

void Circle::drawShape(){
    Circle::common();
    std::cout<<"It's a circle."<<std::endl;
}

class GraphicEditor{
public:
    GraphicEditor();
    void drawShape(Shape* shape);
    ~GraphicEditor();
};

GraphicEditor::GraphicEditor(){
    std::cout<<"I'm creating a graphic editor."<<std::endl;
}

GraphicEditor::~GraphicEditor(){
    std::cout<<"I'm destroying a graphic editor."<<std::endl;
}

void GraphicEditor::drawShape(Shape* shape){
    shape->drawShape();
}

int main()
{
    Shape* shape = new Rectangle();
    GraphicEditor* ge = new GraphicEditor();
    ge->drawShape(shape);
    shape = new Circle();
    ge->drawShape(shape);
    delete ge;
    delete shape;
    return 0;
}
