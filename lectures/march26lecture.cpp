#include <cstdlib>
#include <iostream>

using namespace std;

copy constructor
overloading
destructor

object(const Object&obj)

object a(x)
object b = a;

function(object x);

return Object(5);

// delete all dynamic memory
~object(){
   //stuff
}   


//sets 
//subset symbols
S = {}; //empty set
|S|
XES //idk did the math 'E'
insert(X,S);
remove(X,S);
SUT //union
SnT // idr but like an upside down u — INTERSECT
SCT //is subset S contained in T


S = {1,3,5}
T = {3,5,7}
SUT = {1,3,5,7}
SnT = {3,5}

/*
TYPE                  NOT SORTED              SORTED
insert(x,s)                     O(n)                            O(n)
xES                                 O(n)                            O(n)
|S|                           O(n) / O(1)                  O(n) / O(1)  
remove(x,s)                 O(n)                             O(n)
SU, ST                     O(|S|*|T|)                   O(|S|+|T|)    
*/


/*header file*/

struct Node{
   int value;
   Node* next;   
};

Node* con(int x, Node* p){
   return new Node{x,p};
}

class Set{
   private:
      bool member(int x, Node* p);
      Node* S;
   public:
      Set() { S = nullptr };
      Set(const Set&a);
      void insert(int x);
      void remove(int x);
      void member(int x);
      int size();
      friend const Set operator + (const Set&a, const Set&b);
}

/* cpp file */

bool Set::member(int x){
   return member(x,s);
}

bool Set::member(int x, Node* p){
   if(p == nullptr){
      return false;
   }
   if(p->value ==x){
      return true;
   }
   return member(x, p->next);
}

void Set::insert(int x){
   if(!member(x,s)){
      s = cons(x,s);
   }
}

Set::Set(const Set&a){
   S = nullptr;
   Node*p = a.S;
   while(p!= nullptr){
      S = cons(p->value, S);
      p = p->next;
   }
   //instead of while loop
   /* 
         for(Node*p = a.S; p !=nullptr; p = p->next){
               s = cons(p->value, S);
         }
   */
}

const Set operator +(const set&a, const Set&b){
   set c = a;
   for(Node*p = b.S; p!= nullptr; p=p->next){
      c.insert(p->value);
   }
   return c;
}

const Set operator + (const Set&a, const Set&b){
   Node*p = a.S;
   Node*q = b.S;
   Node*r = nullptr;
   while(p!=nullptr && q!= nullptr){
      if(p!= nullptr && q!= nullptr){
         if(p->value < q->value){
            r = con(p->value,r);
            p = p->next;
         }
         if(p->value > q->value){
            r = cons(q->value, r);
            q = q->next;
         }
      }
   }
}