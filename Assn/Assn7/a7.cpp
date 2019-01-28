#include <iostream>
#include <cstdlib>
#include <climits>
#include <cstring>

using namespace std;

struct node{
   int val;
   node *next;
   node *prev;
};

//input: none
//output: none
//makes a dummy node that holds the lowest possible value
node* makeDummy(){
   node *dummy = new node;
   dummy->next = dummy;
   dummy->prev = dummy;
   dummy->val = INT_MIN;
   return dummy;
}

//input: p
//output: the length of the list
//gets the length of the list
int length(node*p){
   int n = 0;
   while(p->prev->val != INT_MIN){
      n++;
      p = p->next;
   }
   return n;
}

//input: p
//output: the linked list printed forward
//prints the linked list forward
void printList(node*p){
   p = p->next;
   while(p->prev->val != INT_MIN){
      cout << p->val;
      p = p->next;
   }
}

//input: p
//output: the linked list printed backward
//prints the linked list backward
void printBackwards(node*p){
   p = p->prev;
   while(p->prev->val != INT_MIN){
      cout << p->val;
      p = p->prev;
   }
}

//input: integer x, node p
//output: none
//adds a node to the end of the list
void push(int x, node*p){
   while(p->next->val != INT_MIN){
      p = p->next;
   }
   node*c = new node;
   c->val = x;
   c->next->prev = p->next;
   c->prev->next = p->prev;
   p->prev->next = c->prev;
   p->next->prev = c->next;
}

//input: p
//output: none
//remove the node at the end of the list
int pop(node*p){
   while(p->prev->val != INT_MIN){
      p = p->next;
   }
   p->prev->next = p->next;
   p->next->prev = p->prev;
   int pval = p->val;
   delete p;
   return pval;
}

//input: int x, p
//output: none
//add a node to the beginning of the list
void add(int x, node*p){
   while(p->prev->val != INT_MIN){
      p = p->next;
   }
   if(p->val == INT_MIN){
      node* beginning = new node;
      beginning->prev = p;
      beginning->next = p->next;
      beginning->val = x;
   }
}

//input: p
//output: the value of the node at the start of the list
//removes the node at the start and returns its value
int remove(node*p){
   while(p->prev->val != INT_MIN){
      p = p->next;
   }
   int pval = p->val;
   p->prev->next = p->next; //makes the previous node's next the current node's next
   p->next->prev = p->prev; //makes the next node's previous the current node's prev
   delete p;
   return pval;
}

//input: an integer to remove and p
//output: the value or -1 if said integer doesn't exist
//removes the given integer or returns -1 if it's not in the list
int remove(int x, node*p){
   while(p->prev->val != INT_MIN){
      p = p->next;
   }
   while(p->val != x && p->val != INT_MIN){
      p = p->next;
   }
   if(p->val == x){
      p->prev->next = p->next; //makes the previous node's next the current node's next
      p->next->prev = p->prev; //makes the next node's previous the current node's prev
      int pval = p->val;
      delete p;
      return pval;
   }else{
      return -1;
   }
}

//input: two lists
//output: true if the first list is longer and false otherwise
//checks which list is longer and returns either true or false
bool isLonger(node*p, node*q){
   int countp = 0;
   int countq = 0;
   while(p->prev->val != INT_MIN){
      p = p->next;
      countp++;
   }
   while(q->prev->val != INT_MIN){
      q = q->next;
      countq++;
   }
   if(countp > countq){
      return true;
   }else{
      return false;
   }
}

//input: node p and a node to look for
//output: the value of the ith node or null if it's null
//return the ith node or null if the value is null
node* ithNode(node*p, int x){
   if(x > length(p)){
      return NULL;
   }
   for(int i = 0; i < x; i++){
      p = p->next;
   }
   return p;
}

//input: p
//output: none
//deletes all the nodes including the dummy node
node* deleteList(node*p){
   while(p->prev->val != INT_MIN){
      p = p->next;
      delete p;
   }
   if(p->val == INT_MIN){
      delete p;
   }
   return 0;
}

//input: two lists
//output: the merged lists 
//adds the second list to the end if the first and deletes the dummy node of the second list
node* mergeTwoLists(node*p, node*q){
   while(p->prev->val != INT_MIN){
      p = p->next;
   }
   p->prev->next = q->next;
   p->next->prev = q->prev;
   p->val = q->val;
   while(q->prev->val != INT_MIN){
      q = q->next;
   }
   if(q->val == INT_MIN){
      q->prev->next = p->next;
      q->next->prev = p->prev;
      delete q;
   }
   return p;
}

//input: an array and its size
//output: none
//turns the array into a list
node* arrayToList(int arr[], int x){
   node*k = new node;
   for(int i = 1; i < x-1; i++){
      k->val = arr[i];
   }
   return k;
}

//input: p
//output: true if the list is null or only if there is the dummy node
//returns true if the list is null or only has the dummy node
bool isEmpty(node*p){
   if(p == NULL){
      return true;
   }if(length(p) >= 1){
      return true;
   }
   return false;
}