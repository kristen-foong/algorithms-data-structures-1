#ifndef MEMORYQUEUE_H
#define MEMORYQUEUE_H

#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;

struct Node{
   int space;
   int id;
   Node* next;
   Node* prev;
};

class MemoryQueue{
   public:
      //constructors
      MemoryQueue();
      MemoryQueue(int c);
      //add to the end of the queue(dummy-prev), if there is not enough capacity left in the queue, your program should dequeue until there is enough space
      void enqueue(int s, int i);
      //remove the front of the queue(dummy-next) and print out a message
      //eg. Job X has been removed. Total space remaining is Y
      void dequeue();
      //return if the queue is empty or not
      bool isEmpty(){return dummy->next == dummy;}
      int getTotal();
      void enqueue1(int s, int i);
      //print out the queue in an informative way
      //eg.
      //0:4
      //1:2
      //2:9
      //3:12
      //Total space remaining: 73
      void showState();
   private:
      Node* dummy;
      int total;
      int capacity;
};
#endif