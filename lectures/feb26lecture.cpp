#include <iostream>

using namespace std;

int a, b, p*, q*;

a & b are int var
p* and q* are pointers to int var

except wait theyre *p and *q from the code below idk man

a = 17;
p = &a;
q = p;
b = *q;

2036 2040 2044 2048 2052
17    17  2036 2036

wtf

p --> a
a = 17
q --> a
b = 17

int a, *p;
double b, *q;

a = 17;
p &a;
b = a; <-- ok
q = p; <-- not ok

cout << "*p = " << *p << endl; // prints off *p = 17
*p = 2;
cout << "a =" << a << endl;

what prints out???
answer: "a = 2"



struct Student{
   int id;
   double gpa;
};

int a = 0, *p = nullptr;

Student s = {213, 3.0};
Student *pS = nullptr;

therefore

a = 0;
p = 0;
S = 213, 3.0;
pS = 0;



we can also do 
   
*p = 2;
(*pS).id = 416; // pS -> id = 416
(*pS).gpa = 3.5; // pS -> gpa = 3.5

so

a = 0
p = 2
s = 213, 3.0
pS = 0 , pS -> id = 416;


if we add
pS = nullptr;

then we cannot access pS anymore cuz it is null

ha fml



StudentInfo s[10000];

StudentInfo *p[10000];
for(i = 0; o < 10000; i++){
   p[i] = &s[i];
}
sort(p,10000);

void sort(StudentInfp *p[], int n){
   for(int i = n-1; i > 0; i--){
      for(int j = 0; j < i; j++){
         if((*p[j]).id > p[j+1]->id){
            StudentInfo *temp;
            temp = p[j];
            p[j] = p[j+1];
            p[j+1] = temp;
         }
      }
   }
}



int *p = new int; //creates new int object and makes new chunk of memory?
int *p = new int(3); // points to a piece of memory which has the value 3 in it

Time *pT; // just a pointer doesn't point to anything, but can point to time class
//the following point to default constructor
pT = new Time; //makes pointer equal to new Time
Time *pA = new Time(); //makes it weirder
Time *pB = new Time{}; //does even weirder
//makes it to a value
Time *pC = new Time(15,30,50); // has value of 15, 20, 50

(*pT).printTime();//int
cout << (*pT).hours(); 
cout << pT->hours();