/*
Assn 5
Kristen Foong
CPSC 1160
Use Selection sort, Quick sort, and Merge sort
*/


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <math.h>

using namespace std;

void selectionSort(int A[], int n);
void quickSort(int A[], int n);
void mergeSort(int A[], int W[], int n);

//Input: initial array and array size
//Output: none
// does selection sort
void selectionSort(int A[], int n){
   int min = 0;
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

//input: initial array, first index, last index
//output: the partition
//finds out the partition, swaps 
int part(int A[], int low, int high){
   int p = A[high];
   int i = low-1; 
   for(int j = low; j < high; j++){
      if(A[j] <= p){
         i++;
         int temp = A[i];
         A[i] = A[j];
         A[j] = temp;
      }
   }
   int temp = A[i+1];
   A[i+1] = A[high];
   A[high] = temp;
   return i+1;
}

//input: initial array, first index, second index
//output: none
// does quick sort
void quickSort(int A[], int low, int n){
   if(low >= n){
      return;
   }
   int mid = part(A,low,n);
   quickSort(A,low,mid-1);
   quickSort(A,mid+1,n);
}

//input: initial array, array size - 1
//output: none
//overloads this and references quickSort above
void quickSort(int A[], int n){
   quickSort(A, 0, n-1);
}

//input: initial array, second array, first index, middle index, last index
//output: none
//merges the arrays, prints back values from W to A
void yuGiOhFusion(int A[], int W[], int low, int mid, int high){
   int i = low;
   int j = mid+1;
   int win = low;
   while(i <= mid && j <= high){
      if(A[i] <= A[j]){
         W[win] = A[i];
         win++;
         i++;
      }else{
         W[win] = A[j];
         win++;
         j++;
      }
   }
   while(i <= mid){
      W[win] = A[i];
      win++;
      i++;
   }
   while(j <= high){
      W[win] = A[j];
      win++;
      j++;
   }
   for(i = low; i <= high; i++){
      A[i] = W[i];
   }
}

//input: initial array, second array, first index, last index
//output:none
//does merge sort and merges them together
void mergeSort(int A[], int W[], int low, int high){
   if(low < high){
      int mid = (low+high)/2;
      mergeSort(A,W,low,mid);
      mergeSort(A,W,mid+1,high);
      yuGiOhFusion(A,W,low,mid,high);
   }
}

//input: initial array, second array, length of array
//output: none
// overloads mergeSort and references above
void mergeSort(int A[], int W[], int n){
   mergeSort(A, W, 0, n-1);
} 

//input: initial array, array size
//output: none
// assigns random numbers to array
void makeArrays(int A[], int size){
   for(int i = 0; i < size; i++){
      A[i] = rand();
   }
}

//input: 32000 size array, second array (for Merge Sort)
//output: none
//prints out the times. change the sort and the array size to corresponding sizes and sorts
void timer(int ttt[], int W[]){
   unsigned start;
   unsigned stop;
   double time = 0;
   
   for(int m = 0; m <= 1000; m++){
      makeArrays(ttt,32000);
      start = clock();
      mergeSort(ttt,W,32000);
      stop = clock();
      time += stop-start;
   }
   cout << endl;
   cout << time/1000;
}

//input: time, number of elements
//output: prints out the answer
//calculates the amount of time for selection Sort
void calcSelecSort(double time, int n){
   double ans = time/(n*n);
   cout << ans;
}

//input: time, number of elements
//output: prints out answer
//calculates the amount of time for quickSort and mergeSort
void calcSort(double time, int n){
   double ans = time/(n * log2 (n));
   cout << ans;
}

//initializes random, creates a 32000 size array and secondary array
//commented out what I used to calculate times
int main(){
   srand(2);
   int ttt[32000] = {0};
   int W[32000] = {0};
   
   //timer(ttt, W);
   //calcSelecSort(3342.08,32000);
   //calcSort(9.009,32000);
}