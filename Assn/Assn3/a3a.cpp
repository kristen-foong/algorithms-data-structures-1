#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <stdio.h>
#include <ctype.h>
#include <string>
using namespace std;

void checkStuff(char string[], int num[], char alphaU[], char alphaL[], bool check[]);
void newString(char stuff[], bool check[], int num[], char alphaU[], int index);

void checkStuff(char string[], int num[], char alphaU[], char alphaL[], bool check[], int index, int j){
   if(string[index] == num[j]){
      check[j] == true;
   }else if(string[index] == alphaU[j] || string[index] == alphaL[j]){
      check[j+9] == true;
   }else{
      checkStuff(string,num,alphaU,alphaL,check,index+1,j+1);
   }
}

void newString(char stuff[], bool check[], int num[], char alphaU[], int index){
   if(index < 1000){
      if(check[index] == true){
         if(index < 10){
            stuff[index] = num[index];
         }else{
            stuff[index] = alphaU[index-9];
         }
      }
      newString(stuff,check,num,alphaU,index+1);
   }
}

int main(){
   char string[1000];
   char stuff[1000];
   char alphaU[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
   char alphaL[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
   int num[10] = {'0','1','2','3','4','5','6','7','8','9'};
   bool check[36] = {false};
   cout << "Enter a string" << endl;
   cin >> string;
   checkStuff(string,num,alphaU,alphaL,check,0,0);
   newString(stuff,check,num,alphaU,0);
   cout << stuff;
}