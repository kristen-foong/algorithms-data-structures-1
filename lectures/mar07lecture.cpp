#include <cstdlib>
#include <iostream>

using namespace std;

struct node{
   int val;
   node* next;
}

node*cons(int x, node*p){
   return new node{x,p};
}

node*p = nullptr;
p = cons(3,p);
p = cons(9,p);
p = cons(3,p);
p = cons(6,p);
p = cons(5,p);

// this builds a linked list that looks like
// 5 -> 6 -> 3 -> 9 -> 3


/** doubly linked list **/

struct node{
   int val;
   node* next;
   node* prev;
}

Node* cons(int x, node *p){
	Node*q = new node {x,p};
	P->prev = q;
	Return q;
}

r->next = p->next;
r->prev = p;
p->next->prev=r;
p->next = r;

//work on next first, then previous on assn

// Mar 19, Monday Midterm



/** circular linked list **/

// Dummy
//creates a dummy node, whose previous is the last element of the list and its next is the first



/* Removing */

//recursively removing

node*remove(int x, node*p){
   if(p==NULL){
      return p;
   }
   if(x == p->val){
      return p->next;
      node*w = p->next;
      delete p;
      return q;
      //but how to delete p??
   }
   p->next = remove(x,p->next);
   return p;
}


//iterative solution


node*removeI(int x, node*p){
   if(p == nullptr){
      return p;
   }
   node*curr = p;
   node*prev = nullptr;
   while(curr!= nullptr && x!=curr->val){
      prev = curr;
      curr = curr->next;
   }
   if(nullptr == prev){
      node*q = curr->next;
      delete curr;
      return q;
   }
   if(curr!= null){
      node*q = cur->next;
      delete curr;
      prev->next = q;
   }
   return p;
}


/** append **/

node*append(int x, node*p){
   if(p==nullptr){
      return cons(x,nullptr);
   }
   node *q = p;
   while(q->next != nullptr){
      q=q->next;
   }
   q->next = cons(x,nullptr);
   return p;
}


//recursive
node*appendR(int x, node*p){
   if(p == nullptr){
      return con(x,p);
   }
   p->next = appendR(x,p->next);
   return p;
}

/** NOTE: NULL really means nullptr change that in notes lmfao **/


// assume we have an ordered linked list
//want to insert stuff

node*insert(int x,node*p){
   if(p == nullptr){
      return con(x,p);
   }
   if(p->next > x){
      p->val = x;
      p->next = appendR(x,p->next);
   }      
   return p;
}

node*insert(int x, node*p){
   if(p==nullptr || x <= p->val){
      return cons(x,p);
   }
   p->next = insert(x,p->next);
   return p;
}
