#include <iostream>
using namespace std;

/****SORTING****/
/* non-descending order
eg. 1,1,2,3,4,6 
no where does it descend. 1-1 does not ascend. */

/*** Selection Sort ***/
/* iteratively
for(int i = 0; i < n-1; i++){
   m = i;
   for(int k = i+1; k < n; k++){
      if(A[k] < A[m]){
         m = k;
      }      
      swap(A,m,i);      
   }
}

swap(int A[], int i, int j){
   int temp = A[i];
   A[i] = A[j];
   A[j] = temp;
}
 */
 
 /****ANALYSIS****/
/* (n-1)(n-2)(n-3)(n-4)(n-5)...
summation! Sigma.
E (sigma) as i = 0 and goes to n-1, which = n(n-1)/2
*/

/****RECURSIVELY****/
//How can we do recursive search?
 /* My try
 void recursiveSearch(int A[], int i){
    for(int k = i+1; k < n; k++){
       if(A[k]<A[i]){
          i=k;
       }
       int temp = A[k];
       A[k] = A[i];
       A[i] = temp;
    }
    recursiveSearch(A, i+1);
 } */
 
 /* The Actual Thing
 void recSel(intA[], int n){
   if(n==1){
      return;
   }
   int m = 0;
   for(int i = 1; i < n; i++){
      if(A[i] > A[m]){
         m = i;
      }
   }
   swap(A,m,n-1);
   recSel(A,n-1); // DONT USE N-- because it'll pass n AND THEN SUBTRACT. it makes life generally not good for you
} */

/****ANALYSIS****/
/* recSel(A,n-1);
T(1)= 0; //base case
T(n)= T(n-1) + n-1;
T(n) = T(n-2) + n-2 + n-1
T(n) = T(n-3) + n-3 + n-2 + n-1
...
T(2) + T(1) + 1 + 2...n-1
0...n-1 */

/****INSERTION SORT****/
//slightly faster sometimes
/* void insertionSort(int A[], int n){
   if(n==1){
      return;
   }
   int i;
   int temp = A[n-1];
   for(int i = n-1; i > 0 && A[i-1]>temp ; i--){
      A[i] = A[i-1];
   }
   A[i] = temp;
   insertionSort(A,n);
} 


Worst Case (Array is backwards)
T(1) = 0;
T(n)=T(n-1)+ n-1
T(n) = T(n-2) + n-2 + n-1
...
n(n-1)/2


Best Case! (just for fun. Array is already Sorted)
T(1) = 0
T(n) = T(n-1)+1
T(n) = T(n-2) + 1 + 1
...
T(n-n-1) + 1 + 1 + 1...
n-1


My try at iteratively

for(int i = 0; i < n-1; i++){
   for(int k = 1; k < n; k++){
      if(n==1){
         return;
      }
      int temp = A[i];
      for(i = n-1; i > 0 && A[i-1]>temp; i--){
         A[i] = A[i]-1;
      }
      A[i] = temp;
   }
}


The Actual Stuff

int i, j, temp;
for(i = 1; i < n; i++){
   temp = A[i];
   for(j = i-1; j>0 && A[j]>temp;j--){
      A[j+1] = A[j];
   }
   A[j+1] = temp;
}

*/


/****BIG O****/
//refers to worst case run time of an algorithm
/* n(n-1)/2 --> O(n^2)
O(log(n))
O(n)

BinarySearch
T(1) = 1
T(n) = T(n/2)+1
         = T(n/4) + 1 = 1
         = T(n/8) + 1 + 1 + 1
         ...
         T(n/(2^k))+k
         
2^k = n
2^logn = n;

log is usually  base logn n n^2

 */