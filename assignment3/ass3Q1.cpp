#include<iostream>
using namespace std;

class cylinder{

private:
    double radius;
    double height;
    static constexpr double PI=3.14;
public:
    cylinder() : radius(0.0),height(0.0){};

    cylinder(double r, double h): radius(r),height(h){};

    double getRadius()const{

        return radius;
    }
    void setRadius(double r)
    {
        radius=r;
    }

    double getHeight()const
    {
        return height;
    }
    void setHeight(double h)
    {
        height=h;
    }
    double calculatevolume() const
    {
        return PI*radius*radius*height;
    }

    void display()const
    {
        cout<<"Radius:"<<radius<<endl;
        cout<<"Height"<<height<<endl;
        cout<<"volume"<<calculatevolume() <<endl;
    }

};

int main()
{
    cylinder cyl1;
    cout<<"defaulter cylinder"<<endl;
    cyl1.display();

    cylinder cyl2(5.0,2.9);
    cout<<"inside parameterized"<<endl;
    cyl2.display();

    cyl1.setRadius(7.0);
    cyl1.setHeight(6.0);
    cout<<"cylinder after setting values"<<endl;
    cyl1.display();
    return 0;
};