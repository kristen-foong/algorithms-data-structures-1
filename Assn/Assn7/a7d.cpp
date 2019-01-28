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
   p = p->next;
   while(p->val != INT_MIN){
      n++;
      p = p->next;
   }
   return n;
}

//input: p
//output: the linked list printed forward
//prints the linked list forward
void printList(node*p){
   p = p->prev;
   while(p->val != INT_MIN){
      cout << p->val << " ";
      p = p->prev;
   }
}

//input: p
//output: the linked list printed backward
//prints the linked list backward
void printBackwards(node*p){
   p = p->next;
   while(p->val != INT_MIN){
      int val = p->val;
      cout << val << " ";
      p = p->next;
   }
}

//input: integer x, node p
//output: none
//adds a node to the end of the list
void push(int x, node*p){
   p = p->next;
   while(p->val != INT_MIN){
      p = p->next;
   }
   node*c = new node;
   c->val = x;
   c->next = p->next;
   c->prev = p;
   p->next->prev = c;
   p->next = c;
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
   if(p->val == INT_MIN){
      node* beginning = new node;
      beginning->val = x;
      beginning->next = p->next; 
      beginning->prev = p;
      p->next->prev = beginning; 
      p->next = beginning;
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
   int first = length(p);
   int sec = length(q);
   if(first > sec){
      return true;
   }else{
      return false;
   }
}

//input: node p and a node to look for
//output: the ith node or null if it's null
//return the ith node or null if the value is null
node* ithNode(node*p, int x){
   node*b = p;
   if(x > length(p)){
      return NULL;
   }
   for(int i = 0; i < x; i++){
      b = b->prev;
   }
   return b;
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
   q = q->prev;
   while(q->val != INT_MIN){
      push(q->val,p);
      q = q->prev;
   }
   return p;
}

//input: an array and its size
//output: none
//turns the array into a list
node* arrayToList(int arr[], int x){
   node* k = makeDummy(); //make dummy node
   for(int i = 0; i < x; i++){
      push(arr[i],k);
   }
   return k;
}

//input: p
//output: true if the list is null or only if there is the dummy node
//returns true if the list is null or only has the dummy node
bool isEmpty(node*p){
   if(p->val == INT_MIN && length(p) > 1){
      if(p->next->val == INT_MIN){
         return true;   
      }
   }
   if(length(p) == 1 && p->val == INT_MIN){
      return true;
   }
   return false;
}

int main(){
   node* s = makeDummy(); //makes dummy node
   cout << "check isEmpty: " << isEmpty(s) << endl;
   add(5,s);//add
   add(7,s);//add
   add(3,s);//add
   add(9,s);//add
   
   cout << "check add: ";
   printList(s); // check Add
   cout << endl;
   
   add(12,s);
   printList(s);
   cout << endl;
   
   push(42,s); //push
   push(12,s);//push
   pop(s); //pop
   remove(s);//remove node at front
   remove(5,s); //remove
   remove(90,s);//check remove for smth that doesn't exist
   
   int arr[3] = {0,1,2};
   cout << "check arrayToList: ";
   node* k = arrayToList(arr,3); //check arrayToList
   printList(k); //check k
   cout << endl;
   
   cout << "check isLonger: "; //check isLonger
   cout << isLonger(s,k);
   cout << endl;
   
   cout << "check mergeTwoLists: ";
   node* m = mergeTwoLists(s,k); // check Merge
   printList(m);
   cout << endl;
   
   cout << "check ithNode: ";
   node*n = makeDummy();
   push(0,n);
   push(1,n);
   push(2,n);
   push(3,n);
   push(2,n);
   node* u = ithNode(n,1);
   cout << u->val;
   cout << endl;
   
   cout << "check deleteList: ";
   deleteList(n);
   printList(n);
   cout << endl;
   
   cout << "check printList: ";
   printList(s);//prints the list
   cout<< endl; 
   cout << "check printBackwards: ";
   printBackwards(s);//prints the list
   cout<< endl; 
}