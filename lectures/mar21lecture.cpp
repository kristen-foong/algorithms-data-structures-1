#include <iostream>
#include <cstdlib>
using namespace std;

char*A = new char[10];
//for assignment:
//push opening brackets onto stack
//when you see a closing bracket, POP IT
//muhaha

Queue - First in, First out
A queue is useful when simulating things eg. traffic light intersection

functions
   enqueue // insert to the end
   dequeue // removing from front
   isEmpty()
   front //look at the front
   size()
   
   
struct Queue{
   int Q[10];
   int front = -1;
   int back = 0;
};

bool isEmpty(){
   if(front = -1 && back = 0){
      return true;
   }      
   return false;
}

void enqueue(){
   
}

int dequeue(){
   if(back == front || )
}


//i missed the code smh
//ask for him to send it?
//took pics
//booyeah

using a singly linked list for a queue is BAD
   dequeue O(1)
   enqueue O(n)

but what about a doubly linked list?
// have a pointer for both head & tail

struct Node{
   int val;
   node* next;
};

node* cons(int x, Node* p){
   return new node(x,p);
}

class Queue{
   private:
      Node* head, *tail;
   public
      Queue(){ head = nullptr; tail = nullptr;}
      bool isEmpty() {return head==nullptr;}
      void enqueue(int x);
      int dequeue();
};

void Queue::enqueue(int x){
   if(tail == nullptr){
      tail = cons(x,nullptr);
      head = tail;
   }else{
      tail->next = cons(x, nullptr);
      tail = tail->next;
   }
}

int Queue::dequeue(){
   if(head == nullptr){
      exit(1);
   }
   int x = head->val;
   Node* discard = head;
   head = head->next;
   delete discard;
   if(head == nullptr){
      tail == nullptr;
   }
   return x;
}





