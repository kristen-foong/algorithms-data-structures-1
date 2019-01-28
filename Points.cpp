#include <iostream>
#include <cmath>
using namespace std;

class Points{
   public:
      Points(double x,double y);
      double getX();
      double getY();
      double getDistance(Points p2);
      double perimeterTri(Points p2,Points p3);
      double perimeter(Points pA[],int n);
   private:
      double xcoord;
      double ycoord;
};

Points::Points(double x,double y){
   xcoord = x;
   ycoord = y;
}

double Points::getX(){
   return xcoord; 
}

double Points::getY(){
   return ycoord; 
}
double Points::getDistance(Points p2){
   return sqrt(pow((xcoord - p2.getX()),2)+pow((ycoord - p2.getY()),2));
}
double Points::perimeterTri(Points p2,Points p3){
   return getDistance(p2) + getDistance(p3) + p3.getDistance(p2);
}
double Points::perimeter(Points pA[],int n){
   int perim = getDistance(pA[0]);
   for(int i = 0; i < n-1;i++){
      perim += pA[i].getDistance(pA[i+1]);
   }
   return perim + getDistance(pA[n-1]);
}

int main()
{
  Points p1(1,1);
  Points p2(1,4);
  Points p3(5,4);
  Points p4(5,1); 
  Points tri[] = {p3,p3}; 
  Points quad[] = {p2,p4,p3}; 
  cout << p1.perimeterTri(p2,p3) << endl;
  cout << p1.perimeter(tri,2) << endl;
  cout << p1.perimeter(quad,3) << endl;


  
  return 0;
}