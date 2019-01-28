/*
Kristen Foong
CPSC 1160
Polynomials Assignment
*/
#include <iostream>
#include <cstdlib>
#include "Polynomial.h"

using namespace std;

//input: constant c
//output: none
//creates the constant Polynomial c
Polynomial::Polynomial(int c){
   Term* term = new Term;
   term->coeff = c;
   term->degree = 0;
   Node* poly = new Node;
   poly->term = term;
}

//input: constant c, degree n
//output: none
//creates a Polynomial with one term c*x^n
Polynomial::Polynomial(int c, int n){
   Polynomial(c);
   poly->term->degree = n;
}

//input: none
//output: the degree of the polynomial
//degree() returns the degree of the polynomial
int Polynomial::degree() const{
   Node* temp = poly;
   int highDeg = 0;
   while(temp->next != nullptr){
      temp = temp->next;
   }
   int deg = temp->term->degree;
   if(deg > highDeg){
      highDeg = deg;
   }
   return highDeg;
}

//input: degree n
//output: the coefficient of the term of degree n
//returns the coefficient of the "term of degree n" of a polynomial p
int Polynomial::coeff(int n) const{
   Node* temp = poly;
   while(temp->term->degree != n){
      temp = temp->next;
   }
   int co = temp->term->coeff;
   return co;
}

//input: none
//output: none
//deletes every term in the polynomial and returns the memory to the freestore
void Polynomial::deletePoly(){
   while(poly->next != nullptr){
      delete poly->term;
      Node* temp = poly;
      poly = poly->next;
      delete temp;
   }
}

//input: none
//output: none
//reads in a polynomial
friend const Polynomial::Polynomial readPoly(){
   Node* temp = poly;
}

//input: none
//ouput: prints out polynomial
//prints out polynomial
friend void Polynomial::printPoly(){
   Node* temp = poly;
   while(temp->next != nullptr){
      cout << temp->coeff << "*x^" << temp->degree << "+";
   }
   cout << temp->next->coeff << "*x^" << temp->next->degree;
}

//input: two polynomials
//output: the sum of the two polynomials
//computes the sum a+b
friend const Polynomial::Polynomial operator + (const Polynomial& a, const Polynomial& b){
   int co;
   Node* newPoly;
   while(a->next != nullptr && b->next != nullptr){
      int adeg = a->term->degree;
      int bdeg = b->term->degree;
      if(adeg == bdeg){
         int co1 = a->term->coeff;
         int co2 = b->term->coeff;
         co = co1 + co2;
         newPoly->term = a->term;
         newPoly->term->coeff = co;
         newPoly->term->coeff = a->deg;
         a = a->next;
         b = b->next;
         newPoly = newPoly->next;
      }else if(adeg < bdeg){
         newPoly->term = a->term;
         newPoly->term->coeff = a->coeff;
         newPoly->term->degree = a->degree;
         a = a->next;
         newPoly = newPoly->next;
      }else{
         newPoly->term = b->term;
         newPoly->term->coeff = b->coeff;
         newPoly->term->degree = b->degree;
         b = b->next;
         newPoly = newPoly->next;
      }
   }
   return newPoly;
}

//input: two polynomials
//output: the product of the two polynomials
//computes the sum a*b
friend const Polynomial::Polynomial operator * (const Polynomial& a, const Polynomial& b){
   Node* first;
   Node* second;
   while(a->next != nullptr){
      if(b->next == nullptr){
         break;
      }
      int co1 = a->poly->term->coeff;
      int co2 = b->poly->term->coeff;
      int co = co1*co2;
      int deg1 = a->poly->term->deg;
      int deg2 = b->poly->term->deg;
      int deg = deg1*deg2;
      first->poly->term->coeff = co1;
      first->poly->term->deg = deg2;
      a = a->next;
   }
}

//input: none
//output: none
//prints out polynomial
friend std::ostream& operator>> (std::ostream&, const Polynomial&){
   printPoly();
   return outputstream;
}

//input: none
//output: none
//reads in polynomial
friend std::istream& operator<< (std::istream&, const Polynomial&){
   readPoly();
   return inputstream;
}