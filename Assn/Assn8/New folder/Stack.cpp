/*
Kristen Foong
Assignment 8
March 20, 2018
*/

#include <cstdlib>
#include <iostream>

#include "Stack.h"

using namespace std;

Stack::Stack(){
   size = 10;
   ch = new char[size];
   index = -1;
}

bool Stack::isEmpty(){
   if(size == 0 || index == -1){
      return true;
   }
   return false;
}

void Stack::rs(){
   char* n = new char[size*2];
   for(int i = 0; i < size; i++){
      n[i] = ch[i];
   }
   delete ch;
   ch = n;
}

void Stack::push(char x){
   if(index == size-1){
      rs();
   }
   char* n = new char[size+1];
   for(int i = 0; i < (size+1); i++){
      n[i] = ch[i+1];
   }
   delete ch;
   ch = n;
   ch[0] = x;
   index++;
}

char Stack::peek(){
   if(isEmpty()){
      return isEmpty();
   }
   return ch[0];
}

char Stack::pop(){
   if(isEmpty()){
      return isEmpty();
   }
   char temp = ch[0];
   char* n = new char[size-1];
   for(int i = 0; i < size; i++){
      n[i] = ch[i+1];
   }
   delete ch;
   ch = n;
   index--;
   return temp;
}
