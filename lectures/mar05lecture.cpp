#include <iostream>
#include <cstdlib>
#ifndef "VECTOR_H";
#define "VECTOR_H";

using namespace std;

/** header **/

class Vector{
   public:
      Vector(int N);
      Vector() {size = 0; n = 0; A = nullptr;}
      int length() {return n}
      void append(int x);
      int& operator[] (int i);
   private:
      int size;
      int *A;
      int n;
};
#endif


/** cpp **/

Vector::Vector(int N){
   if(N < 0){
      N = 0;
   }
   A = new int[N];
   size = N;
   n = 0;
}

void Vector::append(int x){
   //if array isn't big enough
   if(n == size){
      //if we've used up everything in the array
      //increase size by 1.5
      size = size + size/2 + 1; //weird go with it
      int *B;
      B = new int[size];
      for(int i = 0; i  n; i++){
         B[i] = A[i];
      }
      delete[]A;
      A = B;
   }
   //add values to the array
   A[n] = x;
   n++;
}

int& Vector::operator[](int i){
   if(i < 0 || i >= n){
      cout << "fucking nopety nope!!!"; //fucking nopety nope
      exit(1);
   }
   return A[i];
}

/** new cpp file **/

#include <vector>
Vector<data type> name;

vector <int> v(5,0);
v.push_back(5);
v.pop_back(); //return 5
v[2] = 3;



/*** nodes ***/

Struct node{
	 int val;
	Node* next;
}

Node *P = new node;
P -> next = new node;

/** other node? **/

node *P = new node;
node *q = new node{
   q->val = 1;
   P->next = q
}
node *r = new node{
   r-> val = 2;
   q->next = r;
}
/** wtf **/

node * s = new node;
s->val = 4;
r->next = s;

//arrow -> i follow the arrow to pointer 

/*** here's a "better way" ***/

node * con(int x, node *p){
   node *q = new node;
   q->val = x;
   q->next = p;
   return q;
}

node * P = con(3,NULL);


/** write a function that returns the length of his list **/
//returns int and passed a node pointer?

int len(node*p){
   int n = 0;
   while(p!=NULL){
      n++;
      p = p->next;
   }
   return n;
}

//Javier's code 

int getLinkListLen(int n, node*p);
int getLinkListLen(node*p){
   int n = 1;
   if(p->next == NULL){
      return n;
   }else{
      return getLinkListLen(n+1,p->next);
   }
}



/*** REMOVING ***/
//yea remove my presence from this room

//tada isn't it cute

node * remove(int x, node*p){
   if(p == x){
      delete;
   }else{
      p->p = next;
   }
}