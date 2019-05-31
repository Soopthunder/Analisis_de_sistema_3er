#include <iostream>

class IShape{
public:
    virtual int getType()=0;
};

class Rectangle:public IShape{
public:
    Rectangle();
    int getType();
    ~Rectangle();
};

class Circle:public IShape{
public:
    Circle();
    int getType();
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

int Rectangle::getType(){
    return 1;
}

int Circle::getType(){
    return 2;
}

class GraphicEditor{
public:
    GraphicEditor();
    void drawShape(IShape* shape);
    ~GraphicEditor();
private:
    void drawRectangle(Rectangle rectangle);
    void drawCircle(Circle circle);
};

GraphicEditor::GraphicEditor(){
    std::cout<<"I'm creating a graphic editor."<<std::endl;
}

GraphicEditor::~GraphicEditor(){
    std::cout<<"I'm destroying a graphic editor."<<std::endl;
}

void GraphicEditor::drawShape(IShape* shape){
    switch(shape->getType()){
        case 1:
            drawRectangle((Rectangle&) shape);
            break;
        case 2:
            drawCircle((Circle& )shape);
            break;
    }
}

void GraphicEditor::drawRectangle(Rectangle rectangle){
    std::cout<<"I'm drawing a rectangle"<<std::endl;
}

void GraphicEditor::drawCircle(Circle circle){
    std::cout<<"I'm drawing a circle"<<std::endl;
}

int main()
{
    IShape* shape = new Rectangle();
    GraphicEditor* ge = new GraphicEditor();
    ge->drawShape(shape);
    shape = new Circle();
    ge->drawShape(shape);
    delete ge;
    delete shape;
    return 0;
}
