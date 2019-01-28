#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <valarray>

using namespace std;

/* Struct

Struct x {
   Datatype1 name;
   Datatype2 name2;
};

Used to group data and stores them all in one location
REMEMBER THE SEMICOLON

eg.

struct student {
   string first;
   string last;
   unsigned stuNum;
   int grade;
};

void readInStu(student &s){
   cout << "Enter first name:";
   cin >> s.first;
   cout << "Enter last name: ";
   cin >> s.last;
   cout << "Enter student number: ";
   cin >> s.stuNum;
   cout << "Enter grade: ";
   cin >> s.grade;
}

structs are global. You can return them like any other data type.

note: unsigned is 8 bits */


/***Exercise***/

/* struct student {
   string first;
   string last;
   int grade;
};

string checkHighest(student s[]){
   int high = 0;
   for(int i = 1; i < 4; i++){
      if(s[i].grade > s[high].grade){
         high = i;
      }
   }
   return s[high].first + " " + s[high].last;
}

string checkLowest(student s[]){
   int low = 0;
   for(int i = 1; i < 4; i++){
      if(s[i].grade < s[low].grade){
         low = i;
      }
   }
   return s[low].first + " " + s[low].last;
}

int main(){
   student classroom[4];
   classroom[0] = {"Jean","Valjean",24};
   classroom[1] = {"Wade","Watts",95};
   classroom[2] = {"Luke","Skywalker",78};
   classroom[3] = {"Rebecca","Chang",32};
   cout << checkHighest(classroom) << endl;
   cout << checkLowest(classroom) << endl;
}
 */
 
/** ENUM **/
 /* 
enum Coin {HEAD,TAILS};
 
Coin toss(){
   if(rand()%2 == 0){
      return HEADS;
   }else{
      return TAILS;
   }
}

enum Days{SUN,MON,TUE,WED,THU,FRI,SAT}; */

/* struct Point{
   int x,y;
};

int cmp(Point P, Point B){
   if(P.x > Q.x){
      return 1;
   }
   if(P.x < Q.x){
      return -1;
   }
   if(P.y > Q.y){
      return 1;
   }
   if(P.y < Q.y){
      return -1;
   }
   return 0;
}

 */

/* 
struct Point{
   int x, y;
};

double distance(Point P, Point Q){
   double dist = sqrt( (pow((P.x - Q.x),2)) + (pow((P.y - Q.y),2)));
   cout << dist;
   return dist;
}

int main(){
   Point P = {3,4};
   Point Q = {0,0};
   distance(P,Q);
} */