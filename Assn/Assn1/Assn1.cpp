/*
Name: Kristen Foong
Assn1
Puts user given values into equation and returns the expanded form
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

//inputs: the default values for a, b, c, and d (which is 0)
//output: asks user for numbers. no return value, but will pass by reference the user given values of a, b, c, and d
//asks the user to give four numbers to put into the equation
void getCoefficients(int&a, int&b, int&c, int&d) {
	cout << "Give the a, b, c and d for (ax + by)*(cx + dy)" << endl;
	cin >> a >> b >> c >> d;
}

//inputs: the values of a, b, c, and d given by the user
//output: no return value, but will pass by reference the calculated values of the new coefficients
//calculates the new coefficients
void newCoefficients(int&a, int&b, int&c, int&d) {
   int a1, b1, c1;
   a1 = a*c;
   b1 = a*d + b*c;
   c1 = b*d;
   a = a1;
   b = b1;
   c = c1;
}

//input: the values of the new coefficients
//output: prints out the equation. does not return anything.
//displays the new equation
void displayEquation(int a, int b, int c) {
   if(a == 0 && b == 0 && c == 0){
      cout << "0" << endl;
   }else{
      //checks the a coefficient
      if(a == 0){
         cout << "";
      }else if(a == 1){
         cout << "x^2";
         if(b > 0){
            cout << "+";
         }
      }else if(a == -1){
         cout << "-x^2";
         if(b > 0){
            cout << "+";
         }
      }else{
         cout << a << "x^2";
         if(b > 0){
            cout << "+";
         }
      }
      //checks the b coefficient
      if(b == 0){
         cout << "";
      }else if(b == 1){
         cout << "xy";
         if(c > 0){
            cout << "+ ";
         }
      }else if(b == -1){
         cout << "-xy";
         if(c > 0){
            cout << "+ ";
         }
      }else{
         cout << b << "xy";
         if(c > 0){
            cout << "+";
         }
      }
      //checks the c coefficient
      if(c == 0){
         cout << "" << endl;
      }else if(c == 1){
         cout << "y^2" << endl;
      }else if(c == -1){
         cout << "-y^2" << endl;
      }else{
         cout << c << "y^2" << endl;
      }
   }
}

//input: none
//output: asks the user if they would like to continue. if yes, continue. if no, end.
//repeats the program until the user answers something other than "y"
void tryAgain() {
   string again;
   cout << "Continue? y/n";
   cin >> again;
   if(again == "y"){
      int a, b, c, d = 0;
      getCoefficients(a,b,c,d);
      newCoefficients(a,b,c,d);
      displayEquation(a,b,c);
      tryAgain();
   }
}

//calls the other functions, then calls the tryAgain function to see if the user would like to play again
int main() {
	int a, b, c, d = 0;
	getCoefficients(a,b,c,d);
   newCoefficients(a,b,c,d);
   displayEquation(a,b,c);
   tryAgain();
}
