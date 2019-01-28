/*
Kristen Foong
CPSC 1160
Shows the number of jobs, and space allotted to those jobs
*/
#include <cstdlib>
#include <iostream>
#include <cstring>
#include "MemoryQueue.cpp"

using namespace std;

int main(){
   srand(0);
   int capacity;
   int total;
   int size;
   cout << "What is the memory capacity?" << endl;
   cin >> capacity;
   cout << "How many jobs to simulate?" << endl;
   cin >> total;
   cout << "What is the max size of a job?" << endl;
   cin >> size;
   
   MemoryQueue test(capacity);
   //~ for(int i = 0; i < total; i++){ 
      //~ int r = rand()%size + 1;
      //~ cout << "Add job " << i << " that uses " << r << " spaces" << endl;
      //~ test.enqueue(r, i);
      //~ test.showState();
   //~ }
   
   for(int i = 0; i < total; i++){
      int r = rand()%size + 1;
      if(test.getTotal() < capacity){
         test.enqueue1(r, i);
         cout << "Adding job " << i;
      }
      while(test.getTotal() > capacity){
         test.dequeue();
         cout << "here";
         if(test.getTotal() < capacity){
            test.enqueue1(r, i);
         }
      }
      
   }
   
}