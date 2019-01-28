#include <iostream>
using namespace std;

void forward(int n);
void backward(int n);
int sumR(int n);
int sumDigits(int n);

void forward(int n){
   if(n != -1){
      cout << n << ", ";
      n--;
      forward(n);
   }
}

void backward(int n){
   if(n != 0){
      backward(n-1);
   }
   cout << n << ", ";
}

int sumR(int n){
   if(n > 1){
      n += sumR(n-1);
   }
   return n;
}

int sumDigits(int n){
   if(n > 9){
      n = sumDigits(n/10) + n%10;
   }
   return n;
}

int main(){
   int n;
   cout <<"Enter an positive integer:";
   cin >> n;
   forward(n);
   cout <<endl;
   backward(n);
   cout << endl; 
   cout << sumR(n) << endl;
   cout <<"Enter an positive integer:";
   cin >> n;
   cout << sumDigits(n) << endl;
   return 0;
}