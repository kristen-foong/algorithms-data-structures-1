#include <iostream>
using namespace std;

//linear search
//array, element to search for
//return position if found, -1 if not

/*
int main() {
   int a;
   int[] arr = new arr[10];
   cout << "Enter the number to search for:";
   cin >> a;
   
   int index = 0;
   for(int i = 0; i < arr.length; i++){
      if(arr[i] == a){
         index = i
         return index;
      }else{
         return -1;
      }
   }
   
   cout << index;
   
}
*/

/* Two Dimensional Arrays
elementType name[ROW][COL]
       
const int MCOL = 5;
void printM(const int M[][MCOL], int ROW, int COL){
   for(int r = 0; r < ROW, r++){
      for(int c = 0; c < COL, c++){
         cout << M[r][c];
      }
      cout << endl;
   }
}

// NOTE YOU NEED TO PASS IN A NUMBER THE SECOND DIMENSION 
// or use a global variable
   
int arr[] = {1,2,3};
int m[][]= 
{1,2,3,4},
{5,6,7,8};
*/

/* Bit Operators
   unsigned short= 010101110111011
   left --> x << 3 --> 10111011011000
   cont --> x >> 3 --> 000 something
   Bitwise &
   1011&1111 = 1011 (adds? Makes everything like .... 0)
   
   & ---> returns a 1 iff there are both ones eg.
   
   1011
   1111
   ------
   1011
   
   1100 | 0110 = 1110
   ^ xor --> is only one if only one  one is one? god help me
   
   | ---> returns a 1 iff there is at least a single one eg.
   
   1100
   0110
   ------
   1110
   
   int w
   cin >> w
   if((w&0x1) ==0){
      cout << "odd"; 
   }else{
      cout << "even"; //is even if odd (therefore, 1)
   }
   
   101101100
   &000000001
   & --> anywhere it has a one and a one, returns a 0
   
   in c++, 0 is FALSE. everything else is TRUE. or something
*/

//WHEN RANDOM ISNT GOOD ENOUGH
/*
int betterRand(){
   int x = rand();
   int y = rand();
   int z = (x << 15)|y;
   return z;
}
// this random is now a lot longer than before
*/

/*RECURSION

function(){
   if(base case(s)){
   }else{
      recursive call;
   }
}

*/

/*the fibonnaci fail. DONT DO THIS

int fib(int n){
   if(n ==0){
      return 0;
   }if(n ==1){
      return 1;
   }else{
      return fib(n-1) + fib(n-2);
   }
}
*/

/*FACTORIAL

int fact(n){
   if(n==0){
      return 1;
   }else{
      return fact(n-1)*n;
   }
}

fact(6)
fact(5)*6
fact(4)*5*6
fact(3)*4*5*6
fact(2)*3*4*5*6
fact(1)*2*3*4*5*6
fact(0)*1*2*3*4*5*6
1*1*2*3*4*5*6

*/


/*
int sum(const int a[], SIZE){
   if(SIZE == 0){
      return 1;
   }else{
      return sum(a, SIZE-1)*a[SIZE];
   }
}*/

/* bad code
void f(double n){
   if(n!=0){
      cout << n;
      f(n/10);
   }
}
int main(){
   f(123456);
   return c;
}
*/

//end note, doubles are weird man.