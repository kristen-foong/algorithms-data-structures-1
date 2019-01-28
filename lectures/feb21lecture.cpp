#include <iostream>
#include <ctime>

using namespace std;

int main(){
   unsigned start = clock();
   int k;
   for(int i = 0; i < 10; i++){
      for(int j = 0; j < 1000000000; j++){
         k = i;
      }
      cerr << i << ",";
   }
   unsigned stop = clock();
   cout << stop-start;
}

// Shifts over x by 15 places so gives you the 1.098e-1608 or w/e
// int x = rand();
// x = (x << 15) | rand();




struct money {
   unsigned d;
   unsigned c;
};

money operator + (money m1, money m2){
   unsigned c = m1.c + m2.c;
   unsigned d = m1.d + m2.d + c/100;
   return money {d,c%100};
}

void operator++(money& m1, int){ //post (the variable ++). The int is a dummy variable.
   unsigned c = m1.c + 5;
   m1.c = c%100;
   m1.d = m1.d + c/100;
}

void operator++(money& m1){
   m1.d = m1.d + 1;
}

int main() {
   money m1 {1,50};
   money m2 = {5,60};
   money m3 = m1 + m2;
   cout << "$" << m3.d << "." << m3.c << endl;
   ++m3;
   cout << "$" << m3.d << "." << m3.c << endl;
   m3++;
}

//exercise:write a header, write a cpp
// see money.h and money.cpp




