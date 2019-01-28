#include <iostream>
#include <cmath>
using namespace std;

class Circle
{

public:
 
   Circle(double x,double y,double r);
   double circum(); //2*r*pi
   double area(); // r^2*pi
   double getRadius();
   bool intersect( Circle& c2);
   double getX();
   double getY();
private:
  // The radius of this circle
   double radius;
   double xcoord;
   double ycoord;
};  // Must place a semicolon here


  // Construct a circle object
  Circle::Circle(double x,double y,double r)
  {
      radius = r;
      xcoord = x;
      ycoord = y;
  }


  // Return the area of this circle
  double Circle::circum()
  {
    return 2*radius* 3.14159;
  }
  double Circle::area()
  {
    return radius * radius * 3.14159;
  }
  double Circle::getX(){
   return xcoord; 
}

double Circle::getY(){
   return ycoord; 
}
double Circle::getRadius()
  {
    return radius;
  }
    bool Circle::intersect( Circle& c2)
  {
    return sqrt(pow((xcoord - c2.getX()),2)+pow((ycoord - c2.getY()),2)) < (radius+c2.getRadius());
  }
int main()
{
  Circle fkhsdf(1,1,2);
  Circle circle2(1,5,3);
  cout << fkhsdf.intersect(circle2);

  
  return 0;
}
