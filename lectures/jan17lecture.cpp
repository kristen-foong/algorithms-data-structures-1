#include <iostream>

/*
"If you have an array ... boop! ... and the array has some sort of values."

int arr[] = { 58, 13, 12, 5, 6. 71, 42};

And we want to add up the sum of all numbers? (idk)

We can write codes in parallel and use recursion.
We can take an array and split it into two arrays. And then split those arrays into two arrays each. And then split those into two arrays.

{58, 13, 12, 5} , {6, 71, 42}
{58, 13} , {12, 5} , {6, 71} , {42}

If length = 1, then return that number. If two, add the two together.

{58, 13, 12, 5} , {6, 71, 42}
{58, 13} , {12, 5} , {6, 71} , {42}
71 , 17, 77, 42 //returns
88, 119 //returns
207 //returns
*/

/* #i tried it sucked
int sumAllNums(int arr[], int SIZE, int start, int end, int sum){
   if(end != start || end != start+1){
      sumAllNums(arr, SIZE, start, end/2);
   }else{
      sum = arr[start]+arr[end];
      if(end < SIZE){
         sumAllNums(arr, SIZE, start+2, SIZE);
      }
   }
}

int main(){
   int arr[] = {58, 13, 12, 5, 6, 71, 42};
   int SIZE = 7;
   int sum = 0;
   int start = 0;
   int end = arr.length;
   cout << sumAllNums(arr, SIZE, start, end, sum);
}
*/

/* THIS ONE WORKS 
float add(const float A[], int low, int high){
   // return the same number
   if(low == high){
      return A[low];
   }
   //return the sum of the two numbers
   if((high-low) == 1){
      return A[low] + A[high];
   }
   int mid = (low/2 + high/2);
   return add(A, low, mid) + add(A, mid+1, high);
}

int main(){
   float A[] = {1,2,3,4,5};
   float low = 0;
   float high = 5;
   cout << add(A, low, high);
}
*/

/*** THERE IS NO A.LENGTH OR ANYTHING you need SIZE ***/

/* Say you have a loop and you want to change it into recursion.

   int findMax(const int A[], SIZE){
      int max = A[0];
      for(int i = 1; i < SIZE, i++){
         if(max < A[i]){
            max = A[i];
         }
      }
      return max;
   }

*/

/* Ryan's code but idk it don't work 
float findMax(const float arr[], int pos){
   if(pos == 1){
      return arr[0];
   }
   //~ int max = findMax(arr, pos-1);
   //~ if(max > arr[pos-1]){
      //~ return max;
   //~ }else{
      //~ return arr[pos-1];
   //~ }
   return std::max(findMax(arr,pos-1)); //idk there's something wrong here.
}

int main(){
   float arr[] = {51,4,2,6,23,1,71};
   std::cout << findMax(arr, 7);
}
*/

//if you're finding the max to something, just use std::max because it's lovely and beautiful and you save yourself a whole bunch of lines of code.

/* Binary Search  
{1,2,3,4,5,6,7}
{X,X,X,X,X,6,7} 
*/

/*  BINARY SEARCH but with ordered elements

//we are looking for x

int binarySearch(const int A[], int left, int right, int x){
   //base case
   if(right < left){
      return -1;
   }
   int mid = (left/2 + right/2);
   //base case if we find it
   if(A[mid]==x){
      return mid;
   }else if(x < A[mid]){
      return binarySearch(A, left, mid-1, x);
   }else{
      return binarySearch(A, mid+1, right, x);
   }
} 
*/

//Stacks: last in, first out

/* me trying to write bindary search iteratively = terrible
int iterativeBinary(const int A[], int left, int right, int x){
   for(left < right){
      if(right < left){
         return -1;
      }
      int mid = (left%2 + right%2);
      if(A[mid] == x){
         return mid;
      }else if (x < A[mid]){
         while(mid != 1){
            mid = (left%2 + right%2);
         }
      }
   }
}
*/



/* The true iterative binary search
int itBin(allthestuff){
   while(l <= r){
      int mid = l/2 + r/2;
      if(A[mid] = k){
         return mid;
      }
      if(x<A[mid]){
         r = mid-1;
      }else{
         l = mid+1;
      }
   }return -1;
} */

/* Helper Methods (overloading methods)
float add(const float A[], int l, int h){
}

float add(const float A[], int h){
   return add(A,0,h);
} */