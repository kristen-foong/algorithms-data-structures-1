#include <iostream>
#include <cstdlib>

using namespace std;

Static Memory
- main
- globals

Stack Memory
- for parameters
- on the side

Freestore Heap (aka Dynamic Memory)
- stored in a heap
- anytime we use "new", take a chunk of memory
- limited amount of space/memory

delete
- go to freestore manager
- wipes it and turns it all to 0
- moves on



int *p, *q;
p = new int;
q = new int;
*p = 13; // points to something that has 13
*q = 42; // points to something that has 42
q = p; // this will cause a problem!!!
*q = 42; // now q will change the 13 to 42

so what can we do?
   
delete p; // deletes the pointer
p = nullptr; // no longer pointing!

still causes problems because now q is pointing to ??? we dont know what is in there anymore ahaha.

// what happens if we do this:

cout << *p;

//CRASH AHAHAHAHAHA


//Exercise
int a, *p, *q;
a = 3;
p = &a;
q = p;
*p = 6;
cout << *p << " " << *q << " " << a;
// output is: 6 6 6

int a, b, *p;
int &q = b; //always points q to b
a = 5;
b = 7;
p = &a;//p points to a
q = 100; // points q to 100 and dereferences
*p += 3; // changes a tp 8
q += 3; // changes q to 103

They did it to make code a lot cleaner



/*****  ( using a * ) ******/

void swap(int *a, int *b){
   int t;
   t = *a;
   *a = *b;
   *b = t;
}
swap(&x,&y);


/*** ( using & ) ***/

void swap(){
   int t;
   t = a;
   a = b;
   b = t;
}
swap(x,y);


gee which one looks better???


/*** passing a reference to a pointer ***/

//objective: create a function that deletes something

void deleteSetNullptr(int * &p){
   //passing a reference to a pointer
   //allows us to change the pointer ... outside of the function?
   delete p; //deletes
   p = nullptr; //sets to null pointer
}

// made q, sent it to deleteSetNull, delete it, clears the memory, makes the variable useless again.
int main(){
   int *q = new int(3);
   deleteSetNullptr(q);
   return;
}




//we want
int n;
cin >> n;
int A[n];
//but can't

int n, *A;
cout << "Enter number: ";
cin >> n;
A = new int[n];

A[0] = 0;
*(A+1) = 1;
cout << A[1]; // = 1
cout << A[3]; //  = 3

//if we did *(A+2) would go 2 memory blocks over aka 2 indeces over

//Setting A to be the numbers between 0 and n
int *p = A;
for(int i = 0; i < n; i++){
   *p = i+1;
   p++;
}


// what if you wanna delete your array?
delete []A;
A = nullptr;

int *p;
if(!p) <=> if(p == nullptr)
   
int*p, *q;
if(p == q) // do they point to the same spot/location?
if(*p == *q) // are the values they're pointing to equal?
   

/**** 2D arrays ****/

int n = 4, m = 5;
int **A; //a pointer to pointers
A = new int*[n]; // a whole bunch of pointer arrays
for(int i = 0; i < n; i++){
   A[i] = new int[m];
}
// 5 rows, 4 columns
//now to delete it
for(int i = 0; i < n; i++){
   delete[]A[i]; //delete each row
}
delete[]A; //delete each column