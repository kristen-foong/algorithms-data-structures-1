#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/*** Classes & Constructors ***/

/* class Circle {
   public:
      double radius; //data field
      //Constructors
      Circle(){
         radius = 1;
      }
      Circle(double nr){
         radius = nr;
      }
   double getArea(){
      return radius*radius*3.1415;
   }
}; // ends with a semicolon!

int main() {
   Circle c(1);
   cout << c.radius << " " << c.getArea() << endl;
} */

/*    public:
      Circle();
      Circle(double newRadius);
      void setRadius(double r);
      double getArea();
      double getRadius();
   private: 
      double radius;
};

Circle::Circle(){
   radius = 1;
}

//construct a circle object
Circle::Circle(double newRadius){
   radius = newRadius;
}

void Circle::setRadius(double r){
   radius = r;
}

int main(){
   Circle circle(1.0);
   circle.getRadius() << " is " << circle.getArea() << endl;
   
   //Modify circle radius
   circle.setRadius(100);
   return 0;
} */

class Circle{
   public:
      Circle(double x, double y, double r);
      double circum();
      double area();
      double getRadius();
      bool intersect(Circle& c2);
      double getX();
      double getY();
   private:
      double radius;
      double xcoord;
      double ycoord;
      //next exercise pretend we have the following
      Points p;
};

Circle::Circle(double x, double y, double r){
   xcoord = x;
   ycoord = y;
   radius = r;
}

double Circle::circum(){
   return 2*Math.PI*r;
}

double Circle::area(){
   return Math.PI*(pow(r,2));
}

double Circle::getRadius(){
   return radius;
}

bool Circle::intersect( Circle& c2){
   if(intersects)
      return true;
   else
      return false;
}

double Circle::getX(){
   return xcoord;
}

double Circle::getY(){
   return ycoord;
}

int main(){
   Circle c1(1,1,2);
   Circle c2(1,5,3);
   cout << c1.intersect(c2);
}
 
//hbo game of thrones go watch it

//pretend we have Points p in the Circle class

class Points{
   public:
      Points(double x, double y);
      void setPoint(double x, double y);
      double getX();
      double getY();
      double getDist(Points& p2);
      double perimeterTri(Points p2, Points p3);
      double perimeter(Points pA[], int n);
   private:
      double x;
      double y;
}; // MUST PLACE SEMICOLON HERE */

/* int main() {
   Points tri[] = {p3, p2};
   Points quad[] = {p2,p4,p3};
   cout << p1.perimeterTri(p2,p3);
} */

double Points::perimeterTri(Points p2, Points p3){
   return getDistance(p2) + getDistance(p3) + getDistance(p1);
}

double Points::perimeter(Points pA[], int n){
   double sum = 0.0;
   for(int i = 1; i <= n; i++){
      if(i == n){
         sqrt(pow((pA[0].getX() - pA[i-1].getX()),2) + pow((pA[0].getY() - pA[i-1].getY()),2));
      }
   }
}

int main() {
}