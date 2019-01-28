#include <cstdlib>
#include <iostream>

using namespace std;


class Stack{
   public:
      Stack();
      bool isEmpty();
      void push(char x);
      char pop();
      char peek();
      void rs();
   private:
      int size;
      int index;
      char *ch;
};
