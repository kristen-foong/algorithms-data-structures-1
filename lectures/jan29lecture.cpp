#include <cstdlib>
#include <iostream>

using namespace std;

/* Merge Sort */
/* 
splits array into two
takes that first half  and breaks it into two as well

{1,3,23,19,2,6,10,12,4}                                           //array
{1,2,23,19}     {2,6,10,12,4}                                   //splits in half
{1,3}    {23,19}    {2,6,10,12,4}                              //splits first half in half again
{1}   {3}   {23,19}    {2,6,10,12,4}                          //splits the first portion into half
{1}   {3}   {23}  {19}   {2,6,10,12,4}                           //splits second portion into half
{1}   {3}   {19}  {23}   {2,6,10,12,4}                           //merges it back sorted
{1,3,19,23}     {2,6}     {10,12,4}                                 //splits like in first half
{1,3,19,23}     {2}    {6}      {10,12,4}
{1,3,19,23}     {2}    {6}     {10}     {12,4}
{1,3,19,23}     {2}    {6}     {10}     {12}     {4}
{1,3,19,23}     {2,4,6,10,12}
{1,3,19,23,2,4,6,10,12}
compare 1 and 2  (first index & midpoint
compare 3 and 2
compare 3 and 4
compare 19 and 4
etc.
{1,2,3,4,6,10,12,19,23}


*/


void merge(int A[], int a_start, int a_end, int b_start, int b_end, int W[]){
   int i,j,k;
   i = a_start;
   j = b_start;
   k = a_start;
   while(i < a_end && j < b_end){
      if(A[i] < A[j]){
         W[k++] = A[i++];
      }
      else if(A[i] > A[j]){
         W[k++] = A[j++];
      }else{
         W[k++] = A[j++];
         W[k++] = A[i++];
      }
   }
   //checks both arrays just to make sure they're done
   while(i <= a_end){
      W[k++] = A[i++];
   }
   while(j <= b_end){
      W[k++] = A[j++];
   }
   //take stuff & shove it into A
   for(i = a_start; i < a_end; i++){
      A[i] = W[i];
   }
}

void mergeSort(int A[], int low, int high, int W[]){
   if(low==high){
      return;
   }
   int mid = (high+low)/2;
   mergeSort(A,low,mid,W);
   mergeSort(A,mid+1,high,W);
   //the actual merge part
   merge(A,low,mid,mid+1,high,W);
}

int main(){
   int A[5] = {5,4,3,2,1};
   int W[5] = {0,0,0,0,0};
   mergeSort(A,0,4,W);
   for (int i = 0; i < 5;i++){
      cout << W[i] << endl;
   }
}

/*  Analysis

T(1) = 0
T(n) = 2(T(n/2)) + (n-1)
     = 2(2(T(n/2)) + n/2 + 2) + (n-1)
     = 4T(n/4) + n-2 + n-1
     = 4(2T(n/8) + n/4 -1) + n-2 + n-1
     = 8(T(n/8) + n-4 + n-2 + n-1

T(0) n-2^(k-1)

nlogn - n+1 // number of operations it will take for worst case
O(nlogn) 

assuming n = 2 

yeah 

*/

/****Bucket Sort****/
/* 
{1,2,3,1,4,9,9,9,7,2,1,1,4,7,8,4,3}

Bucket: 
[ 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 ]
|||| ||  ||  |||             ||  |   ||| 

tallies up numbers:
1: 4
2: 2
3: 2
4: 3
5: 0 
6: 0
7: 2
8: 1
9: 3 

Unfortunately you need to know exactly what's inside. Don't need to know the length
O(n+t), where t is the number of buckets

*/

/****Radix Sort****/

/*
331, 454, 230, 34, 343, 45, 59, 453, 345, 231, 9
// look at last digit of all nums and put them in proper buckets.

[ 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 ]

0: 230,
1: 331, 231, 
2:
3: 453, 
4: 454, 34,
5: 45, 345,
6:
7:
8:
9: 59, 9

230,331, 231, 343, 453, 454, 34, 45, 345, 59, 9
Empties buckets and checks second position

0: 9
1: 
2: 
3: 230, 331, 231, 34
4: 343, 45
5: 453, 454, 59
6: 
7: 
8: 
9: 

9, 230, 331, 231, 34, 343, 45, 453, 454, 59
Does the same thing for the third position

0: 9, 34, 45, 59
1:  
2: 230, 231
3: 331, 343, 345
4: 453, 454
5: 
6: 
7: 
8: 
9: 

9, 34, 45, 59, 230, 231, 331, 343, 345, 453, 454


O(dn), where d is some unknown :/

*/