/*
Kristen Foong
Assignment 8
March 20, 2018
*/

#include <cstdlib>
#include <iostream>
#include <climits>
#include <cstring>
#include "Stack.cpp"

using namespace std;

void checkBrackets(Stack b, string s){
   for(unsigned i = 0; i < s.length(); i++){
      if(s[i] == '(' || s[i] == '<' || s[i] == '[' || s[i] == '{'){
         b.push(s[i]);
         cout << "pushed" << endl;
      }
      if(s[i] == ')' || s[i] == '>' || s[i] == ']' || s[i] == '}'){
         if(s[i] == ')' && b.peek() == '('){
            b.pop();
            cout << "popped" << endl;
         }
         if(s[i] == '>' && b.peek() == '<'){
            b.pop();
            cout << "popped" << endl;
         }
         if(s[i] == '}' && b.peek() == '{'){
            b.pop();
            cout << "popped" << endl;
         }
         if(s[i] == ']' && b.peek() == '['){
            b.pop();
            cout << "popped" << endl;
         }
      }
   }
   if(b.isEmpty()){
      cout << "Good brackets";
   }else{
      cout << "Bad brackets";
   }
}

int main(){
   string s;
   Stack b;
   cout << "Enter a string: " << endl;
   cin >> s;
   checkBrackets(b,s);
}

