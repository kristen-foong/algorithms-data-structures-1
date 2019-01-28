//T530 is the room for the midterm
//find it
//be there @ same time as class
//it's on the 5th floor

#include <iostream>
#include <cstdlib>

using namespace std;

/*
Stacks
queues
sets
graphs
*/

//stack: first in, last out
//queues: first in, first out
//sets: {10,2,4} (trying to add 4 won't work). It's a group of unique things.
//graphs: graph. looks like a graph. idk man.

function
   isEmpty <= if the stack is empty
   peek <= looks at the top item
   pop <= remove and return top item
   push <= adds to the top of the stack
//need the top four to make a stack.
//NEED I SAY, NEED
maybe size <= return stack size
   
int main(){
   Stack s;
   s.push(2); //stack: 2
   s.push(4); // stack: 4 | 2
   s.peek(); // 4
   s.peek(); // 4
   s.pop(); // stack: 2
   s.peek(); // 2
   s.push(16); //stack: 16 | 2
   s.push(2); // stack: 2 | 16 | 2
   s.pop(); // stack: 16 | 2
   s.pop(); //stack: 2
   s.pop(); // stack: --
   s.pop(); // ERROR
   s.peek(); // ERROR
}

struct stack{
   int top[100];
   int n = 0;
   int pop(){
      n--;
      if(n==-1){
         cout << "NOPE";
         exit(1);
      }
      return top[n];
   }
   int peek(){
      return top[n-1];
   }
   void push(int x){
      if(n == 100){
         cout << "NOPE";
         exit(1);
      }
      top[n] == x;
      n++;
   }
   bool isEmpty(){
      return n == 0;
   }
   int size(){
      return n;
   }
}

int main(){
   Stack s;
   s.push(x);
}


pop_back <= remove last item
back <= return last item
push_back <= add to end of the vector



#include <vector>
Vector<data type> name;

vector <int> v(5,0);
v.push_back(5);
v.pop_back(); //return 5
v[2] = 3;



#include <iostream>
#include <vector>
using namespace std;
struct Stack{
   vector<int> top;
   int pop(){
      int retVal = top.back();//there's more shit idk
      
   }
}



/* header file */
class Stack{
   public:
      Stack();
      bool isEmpty() const;
      void push(int x);
      int pop();
      int peek() const;
   private:
      struct Node{
         int item;
         Node* next;
      }
      Node* top;
      Node* cons(int x, Node* p);
}

/* cpp file*/
Stack::Node* Stack::cons(int x, Node*p){
   return new Node{x,p};
}
Stack::Stack(){
   top = nullptr;
   //n = 0;
}
bool Stack::isEmpty(){
   return top == nullptr;
}
void Stack::push(int x){
   top == cons(x,top);
}
int Stack::peek(){
   if(isEmpty()){
      exit(1);
   }else{
      return top->item;
   }
}
int Stack::pop(){
   if(isEmpty()){
      exit(1);
   }
   int x->top->item;
   Npde*discard = top;
   top = top->next;
   delete discard;
   //n--
   return x;
}