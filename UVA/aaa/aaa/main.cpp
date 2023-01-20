#include <iostream>
using namespace std;
#define PI 3.1415926

class Shape
{
public:
    double getArea(){return area;}
    double getPerimeter(){return perimeter;}
protected:
    void setArea(double a){
        if(a>0)
            area = a;
    };
    void setPerimeter(double p){
        if(p>0)
            perimeter = p;
    };
private:
    double area;
    double perimeter;
};

class Rectangle : public Shape
{
public:
    Rectangle(double _width, double _height);

private:
    double width;
    double height;
};

class Circle : public Shape
{
public:
    Circle(double _radius);

private:
    double radius;
};

Rectangle::Rectangle(double _width, double _height)
{
    if(_width>0 && _height>0)
    {
        width = _width;
        height = _height;
        setArea(width*height);
        setPerimeter(2*(width+height));
    }
};
Circle::Circle(double _radius)
{
    if(_radius>0)
    {
        radius= _radius;
        setArea(radius*radius*PI);
        setPerimeter(radius*2*PI);
    }
};

int main()
{
    double totalArea = 0.0, totalPerimeter = 0.0;
    Shape shapes[3];
    shapes[0] = Rectangle(10, 15);
    shapes[1] = Circle(10);
    shapes[2] = Rectangle(3, 4);
    for(int i=0; i<3; i++){
        totalArea += shapes[i].getArea();
        totalPerimeter += shapes[i].getPerimeter();
    }
    cout << "形狀總面積為: "<< totalArea << endl;
    cout << "形狀總周長為: "<< totalPerimeter << endl;
    return 0;
}
