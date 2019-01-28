#include <cstdlib>
#include <iostream>

using namespace std;

/* TREES */

// "this isn't biology"

/*
       o
   o/   \o
o/         \o
 
 */
 

struct TNode{
   TNode* left;
   int val;
   TNode* right;
};

//new TNode{ left, val, right}


class BST{
   public:
      BST(){ root = nullptr;}
      BST(int a[], int n){ root = sArr2BST(a,0,n-1); } //the function in here will be recursive? TO BE EXPLAINED LATER
      //all the bottom ones are to be over loaded
      void insert(int x);
      void inorder(); // print post or pre
      bool search(int x);
   private:
      TNode* root;
      bool search(int x, TNode* p);
      void inorder(TNode* p);
      void insert(int x, TNode* p);
      Node* makeLeaf(int x);
      TNode* sArr2BST(int a[], int e, int s);
};


/** cpp code **/

void BST::insert(int x){
   root = insert(x, root);
}

void BST::inorder(){
   inorder(root);
}

bool BST::search(int x){
   return search(x, root);
}

TNode* BST::makeLeaf(int x){
   return new TNode{nullptr, x, nullptr};
}

TNode* BST::insert(int x, TNode* p){
   if(p == nullptr){
      return makeLeaf(x);
   }else if(x < p->val){
      p->left = insert(x,p->left);
   }else{
      p->right = insert(x, p->right);
   }
   return p;
}

/*
inorder
go left
print
go right
*/

void BST::inorder(TNode* p){
   if(p == nullptr){
      return;
   }
   inorder(p->left);
   cout << p->val;
   inorder(p->right);
}

/*
preorder
print
go left
go right

postorder
go left
go right
print
*/

bool BST::search(int x, TNode* p){
   if(p == nullptr){
      return false;
   }
   if(p->val == x){
      return true;
   }
   if(x > p->val){
      return search(x, p->right);
   }else{
      return search(x, p->left);
   }
}

TNode* BST::sArr2BST(int a[], int s, int e){
   if(s > e){
      return nullptr;
   }
   int mid = (e+s)/2;
   TNode* r = makeLeaf(a[mid]);
   r->left = sArr2BST(a, s, mid-1);
   r->right = sArr2BST(a, id+1, e);
   return r;
}

//log time bc its a balanced tree