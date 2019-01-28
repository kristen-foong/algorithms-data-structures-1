/*
Kristen Foong
CPSC 1160
Polynomials Assignment
*/
#include <iostream>
#include <cstdlib>
#include "Polynomial.cpp"

using namespace std;

int main(){
   cout << "Enter number of terms for polynomial" << endl;
   Term *t1,*t2,*t3; 
   t1 = new Term; 
   cin >> t1->coeff;
   t1->coeff = 2;
   cin >> t1->degree;
   t1->degree = 0; 
   t2 = new Term{-3, 3};
   t3 = new Term{4, 5};
   Node * p, *q, *r; 
   p = new Node;
   p->term = t1;
   q = new Node;
   q->term = t2;
   r = new Node;
   r->term = t3;
   p->next = q;
   q->next= r; 
   r->next= nullptr;
}