#include <iostream>
#include <cmath>
using namespace std;
class Points{
   public:
      Points();
      Points(double x,double y);
      double getX();
      double getY();
      void setPoints(double x,double y);
      double getDistance(Points& p2);
   private:
      double xcoord;
      double ycoord;
};

Points::Points(){
   xcoord = 0;
   ycoord = 0;
}
Points::Points(double x,double y){
   xcoord = x;
   ycoord = y;
}
void Points::setPoints(double x,double y){
   xcoord = x;
   ycoord = y;
}

double Points::getX(){
   return xcoord; 
}

double Points::getY(){
   return ycoord; 
}
double Points::getDistance(Points& p2){
   return sqrt(pow((xcoord - p2.getX()),2)+pow((ycoord - p2.getY()),2));
}
class Circle
{

public:
 
   Circle(double x,double y,double r);
   double circum();
   double area();
   double getRadius();
   bool intersect( Circle& c2);

private:
  // The radius of this circle
   double radius;
   Points p;
};  // Must place a semicolon here


  // Construct a circle object
  Circle::Circle(double x,double y,double r)
  {
      radius = r;
      p.setPoints(x,y);
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
  double Circle::getRadius()
  {
    return radius;
  }
    bool Circle::intersect( Circle& c2)
  {
    return p.getDistance(c2.p) < (radius+c2.getRadius());
  }
int main()
{
  Circle circle1(1,1,3);
  Circle circle2(1,5,2);
  cout << circle1.intersect(circle2);

  
  return 0;
}
