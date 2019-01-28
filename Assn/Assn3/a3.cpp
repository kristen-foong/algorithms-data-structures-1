#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

void checkChars(char str[], char stuff[], int isTrue[], int i, int n);
void getStr(char str2[], char stuff[], int isTrue, int i, int length);
void sort(char str2[], char stuff[], int isTrue, int i, int length);

void checkChars(char str[], char stuff[], int isTrue[], int i, int n){
   if(str[i] == stuff[n]){
      isTrue[i] = 1;
   }else{
      isTrue[i] = 0;
      checkChars(str,stuff,isTrue,i,n-1);
   }
}

void getStr(char str2[], char stuff[], int isTrue, int i){
   if(isTrue[i] == 1){
      str2[i] = stuff[i];
   }
   getStr(str2,stuff,isTrue,i);
}

void sort(char str[], char str2[], char stuff[], int isTrue, int i, int length){
   if(i < length){
      checkChars(str,stuff,isTrue,i,length);
   }
   getStr(str2,stuff,isTrue,i);
} 

int main(){
   char string;
   char str[1000];
   char str2[1000];
   int isTrue[36];
   char stuff[36] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
   cout << "Enter a string: " << endl;
   cin >> string >> str;
   int length = string.length();
   int i = 0;
   sort(str,str2,stuff,isTrue,i,length);
   cout << str2;
}