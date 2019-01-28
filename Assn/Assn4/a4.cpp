#include <iostream>
#include <ctime>

using namespace std;

void sort(int A[], int n){
   int start = 0;
   int end = n-1;
   //int count = 0;
   bool check = true;
   while(check == true){
      check = false;
      for(int i = start; i < end; i++){
         if(A[i+1] < A[i]){
            int temp = A[i];
            A[i] = A[i+1];
            A[i+1] = temp;
            check = true;
            //count++;
         }
      }
      if(check == false){
         break;
      }
      end = end-1;
      check = false;
      for(int j = end; j > 0; j--){
         if(A[j] < A[j-1]){
            int temp = A[j-1];
            A[j-1] = A[j];
            A[j] = temp;
            check = true;
            //count++;
         }
      }
      start = start+1;
   }
   //cout << "Count: " << count << endl;
}

void recSort(int A[], int start, int end, bool check){
   while(check == true){
      check = false;
      for(int i = start; i < end; i++){
         if(A[i] > A[i+1]){
            int temp = A[i];
            A[i] = A[i+1];
            A[i+1] = temp;
            check = true;
         }
      }
      if(check == false){
         break;
      }
      end = end-1;
      check = false;
      for(int j = end; j > 0; j--){
         if(A[j] < A[j-1]){
            int temp = A[j-1];
            A[j-1] = A[j];
            A[j] = temp;
            check = true;
         }
      }
      recSort(A, start+1,end-1,check);
   }
}



/* 
void sortRec(int A[], int n, int index, int start, int end, bool check){
   if(end <= start){
      return;
   }
   if(check){
      if(A[index-1] > A[index]){
         //swap
      }
      if(index-1 <= start){
         check = false;
         start = start+1;
         index--;
      }
   }else{
      if(A[index] > A[index+1]){
         //swap
      }
      if(index+1 >= end){
         check = true;
         end = end-1;
         index++;
      }
   }
   
   if(check){
      sortRec(A,n,index-1,start,end,check);
   }else{
      sortRec(A,n,index+1,start,end,check);
   }
}
 */
 

int main(){
   srand(time(0));
  int A[] = {9,8,7,6,5,4,3,2,1,0}; 
  sort(A, 10);
  for(int i = 0; i < 10; i++){
     cout << A[i] << " ";
  }
  cout << endl;
  
  //create Random Array
  int B[17];
  for(int j = 0; j < 17; j++){
     B[j] = rand()%17;
     cout << B[j] << " ";
  }
  cout << endl;
  sort(B,17);
  for(int k = 0; k < 17; k++){
     cout << B[k] << " ";
  }
  cout << endl;
  recSort(B,0,16,true);
  for(int b = 0; b < 17; b++){
     cout << B[b] << " ";
  }
}
