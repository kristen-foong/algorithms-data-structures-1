/*
Assn 5
Kristen Foong
CPSC 1160
Use Selection sort, Quick sort, and Merge sort
*/


#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void selectionSort(int A[], int n);
void quickSort(int A[], int n);
void mergeSort(int A[], int W[], int n);

void selectionSort(int A[], int n){
   int min;
   for(int i = 0; i < n-1; i++){
      for(int j = i+1; j < n; j++){
         if(A[i] > A[j]){
            min = j;
         }
      }
      int temp = A[i];
      A[i] = A[min];
      A[min] = temp;
   }
}

int part(int A[], int low, int high){
   int mid = (low+high)/2;
   int p = A[mid];
   A[mid] = A[low];
   while(low < high){
      while(A[high] >= p){
         high--;
      }
      A[low] = A[high];
      while(A[low] < p){
         low++;
      }
      A[high] = A[low];
   }
   A[low] = p;
   return low;
}

void quickSort(int A[], int low, int n){
   if(low == n){
      return;
   }
   if(low+1 == n){
      if(A[low] > A[n]){
         int temp = A[low];
         A[low] = A[n];
         A[n] = temp;
      }
      return;
   }
   int mid = part(A,low,n);
   quickSort(A,low,mid);
   quickSort(A,mid+1,n);
   return;
}

void quickSort(int A[], int n){
   quickSort(A, 0, n-1);
}

/* void mergeSort(int A[], int W[], int n){
   
} */

int main(){
   int A[5] = {5,4,3,2,1}; 
   quickSort(A,5);
   for(int i = 0; i < 5; i++){
      cout << A[i];
   }
}