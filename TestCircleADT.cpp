#include <iostream>
using namespace std;

class Circle
{

public:
  Circle();
   Circle(double newRadius);
   void setRadius(double r);
   double getArea();
   double getRadius();
private:
  // The radius of this circle
   double radius;
};  // Must place a semicolon here

  Circle::Circle()
  {
    radius = 1;
  }

  // Construct a circle object
  Circle::Circle(double newRadius)
  {
    radius = newRadius;
  }

  // Return the area of this circle
  void Circle::setRadius(double r)
  {
    radius = r;
  }
  // Return the area of this circle
  double Circle::getArea()
  {
    return radius * radius * 3.14159;
  }
  double Circle::getRadius()
  {
    return radius;
  }
int main()
{
  Circle circle1(1.0);
  Circle circle2(25);
  Circle circle3(125);

  cout << "The area of the circle of radius "
    << circle1.getRadius() << " is " << circle1.getArea() << endl;
  cout << "The area of the circle of radius "
    << circle2.getRadius() << " is " << circle2.getArea() << endl;
  cout << "The area of the circle of radius "
    << circle3.getRadius() << " is " << circle3.getArea() << endl;

  // Modify circle radius
  circle2.setRadius(100);
  cout << "The area of the circle of radius "
    << circle2.getRadius() << " is " << circle2.getArea() << endl;

  return 0;
}
