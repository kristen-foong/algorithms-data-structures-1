/*
Kristen Foong
CPSC 1160
Shows the number of jobs, and space allotted to those jobs
*/
#include <cstdlib>
#include <climits>
#include <iostream>
#include "MemoryQueue.h"

using namespace std;

//input: none
//output: none
//constructor
MemoryQueue::MemoryQueue(){
   Node* dummy = new Node;
   dummy->next = dummy;
   dummy->prev = dummy;
   dummy->space = INT_MIN;
   dummy->id = INT_MIN;
}

//input: capacity
//output: none
//constructor
MemoryQueue::MemoryQueue(int c){
   capacity = c;
   total = 0;
   MemoryQueue();
}

//input: space, id
//output:none
//adds node to the end of the queue
void MemoryQueue::enqueue(int s, int i){
   cout << "enqueueing" << endl;
   if((total + s) > capacity){
      //cout << "enqueueing 1" << endl;
      dequeue();
   }else if(s > capacity){
      //cout << "enqueueing 2" << endl;
      cout << "Space is greater than capacity. Cannot enqueue." << endl;
      //exit(1) by rebecca
      dequeue();
   }else if(dummy->id == INT_MIN){
      //cout << "enqueueing 3" << endl;
      Node* p = new Node;
      p->next = dummy;
      p->prev = dummy->prev;
      dummy->prev->next = p;
      dummy->prev = p;
      p->id = i;
      p->space = s;
      total += s;
   }
   
}

int MemoryQueue::getTotal(){
   return total;
}

void MemoryQueue::enqueue1(int s, int i){
     Node* p = new Node;
      p->next = dummy;
      p->prev = dummy->prev;
      dummy->prev->next = p;
      dummy->prev = p;
      p->id = i;
      p->space = s;
      total += s;
}

//input: none
//output:none
//takes away the node at the front of the queue
void MemoryQueue::dequeue(){
   if(isEmpty()){
      cout << "Cannot dequeue. Queue is empty." << endl;
      exit(1);
   }
   Node* igotthis = dummy->next;
   igotthis -> next -> prev = dummy; 
   dummy -> next = igotthis -> next;
   int id = igotthis->id;
   cout << "Job " << id << " removed." << endl;
   delete igotthis;
}

//input: none
//output:none
//shows the remaining space in the queue
void MemoryQueue::showState(){
   int sc = 0;
   Node* current = dummy -> next;
   while(current->id != INT_MIN){
      int id = current->id;
      int space = current->space;
      cout << id << ":" << space << endl;
      sc += space;
      current = current->next;
   }
   cout << "Total space remaining: " << sc << endl;
   cout << "--------------------" << endl;
}