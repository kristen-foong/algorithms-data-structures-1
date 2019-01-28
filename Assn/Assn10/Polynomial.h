/*
Kristen Foong
CPSC 1160
Polynomials Assignment
*/
#include <iostream>
#include <cstdlib>

using namespace std;

struct Term{
   int coeff;
   int degree;   
};

struct Node{
   Term* term;
   Node* next;
};

class Polynomial{
   public:
      //creates the constant Polynomial c
      Polynomial(int c);
   
      //creates a Polynomial with one term c*x^n
      Polynomial(int c, int n);
   
      //add others if you want
      
      //degree() returns the degree of the polynomial
      int degree() const;
   
      //returns the coefficient of the "term of degree n" of a polynomial p
      //eg. p.coeff(5) is 4 and p.coeff(4) is 0
      int coeff(int n) const;
   
      //reads in the terms of a polynomial from standard input
      friend const Polynomial readPoly();
      //or as a member function readPoly
      //or as an overloaded operator >> reading from an inputstream
      
      //prints the polynomial using the default print variable
      friend void printPoly(const Polynomial& p);
      //or as a member function printPoly
      //or as an overloaded operator << for output stream
      
      //deletes every term in the polynomial and returns the memory to the freestore
      //also sets the private linked list poly to nullptr
      void deletePoly();
      
      //computes the sum a+b
      friend const Polynomial operator + (const Polynomial& a, const Polynomial& b);
      
      //computes the product a*b
      friend const Polynomial operator * (const Polynomial& a, const Polynomial& b);
      
      friend std::ostream& operator<< (std::ostream&, const Polynomial&);
      
      friend std::istream& operator<< (std::istream&, const Polynomial&);
      
   private:
      Node* poly;
};