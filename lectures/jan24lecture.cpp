#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
/* 
can run A3 in linear. NO LOOPS. 
Quiz next class, on recursion.
Week after next is midterm.
Section 1 is like .... when? idk man.
*/

/* 
A = n^2
B = 50n
which is better? 
as long as n < 50, A is faster.
n > 50, B is faster.
*/
/* How many additions?

int fun(const int A[], int n){
   if(n==1){
      return A[0] + A[0] + A[0] + A[0];
   }else{
      return A[n-1] + A[n-1] + fun(A,n-1);
   }
} 

say n is 5
A[4] + A[4] + fun(A,4) --> 2
A[3] + A[3] + fun(A,3) --> 2
A[2] + A[2] + fun(A,2) --> 2
A[1] + A[1] + fun(A,1) --> 2
A[0]*4 --> 3

2 (n-1) + 3
2n - 2 + 3
2n + 1
2(4) + 3
= 11 

T(1) = 3
T(2) = 2 + T(n-1)

*/

/********Quick Sort**********/
/* 
pivot points! We break the array into two and sort it 
choosing the mean is said to be the better way of doing it.
We break the array into more arrays and then sort those smaller arrays.
Average case is nlog(n)
Big O is n^2
*/

/*
void quickSort(int A[], int low, int high){
   int mid, temp;
   if(low==high){
      return;
   }
   if(low+1 == high){
      if(A[low] > A[high]){
         temp = A[low];
         A[low] = A[high];
         A[high] = temp;
      }
      return;
   }
   mid = partition(A,low,high,0); //this calls another function to find the mid point. we assume the mid point is SORTED
   quickSort(A,low,mid-1); //breaks array and takes lower half
   quickSort(A,mid+1,high);//breaks array and takes upper half
   return;
}

//finds the mid point
int partition(int A[], int low, int high){
   int mid = (low+high) / 2; //finds mid point
   int pivot = A[low]; // makes pivot the low value.
   A[mid] = A[low]; // sets mid value to equal low value.
   while(low < high){
      //while highest index is greater than pivot = A[low] 
      while(low < high && A[high] >= pivot){
         //minus from high
         high--;
      }
      A[low] = A[high]; //sets low value to equal high value, which should be now less than the pivot.
      //while A[low], which is the high value, is less than the pivot, which is the A[low] value
      while(low < high && A[low] <= pivot){
         //adds to low
         low++;
      }
      A[high] = A[low]; // sets high value to equal the low value
   }
   A[low] = pivot;//sets the low value to equal the pivot
   return low;
} */

/* 
Analysis on an iterative solution

int A(int A[], int n, int x){
   int i, j, c;
   for(i=0;i<n;i++){
      A[i] = A[i]*x;
   }
   c = 0;
   for(i=0;i< n-1;i++){
      for(j=0;j<n;j++){
         if(A[i]>A[j]){
            c = c+1;
         }
      }
   }
   return c;
} 

cost
(we don't care about constants but we're adding them so idk)
c1n + c2 + c3(n-1)n + c4 +c5(n-1)
c1n + c2 + c3n^2 - c3n + c4 + c5n - c5
c6 = c1 - c3 + c5
c7 = c2 + c4 - c5
c3n^2 + c6n + c7 

*/

void g(int x) {if (x == 0)cout << x;else if (x == 1)cout << x;else {g(x / 2);cout << x % 2;}}
int main(){
   g(19);
}
