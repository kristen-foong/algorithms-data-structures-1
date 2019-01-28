//~ Kristen Foong
//~ Assn 3: Sorted Character List
//~ Gets a user input string of characters, then sorts and prints them out in alphanumeric order, in all caps

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cstring>
#include <stdio.h>
#include <ctype.h>
#include <string>
using namespace std;

string upperCases(string stuff, int end);
void printString(bool check[], int index);
void sortString(string stuff, bool check[], int end);

//input: the user string and the length of the string
//output: the string in uppercase format
//checks if the char is a letter, then puts it to uppercase
string upperCases(string stuff, int end){
   if(end < 0){
      return 0;
   }else{
      if(isalpha(stuff[end])){
         stuff[end] = toupper(stuff[end]);
      }
      return upperCases(stuff, end-1);
   }
}

//input: the boolean array and the index
//output: prints out the list of sorted characters
//gets the boolean array and uses it to print out digits or letters (according to ASCI values)
void printString(bool check[], int index){
   if(index < 0){
      return;
   }
   else{
      printString(check, index-1);
      if(check[index] == true){
         if((index >= 0) && (index <= 9)){
            cout << index;
         }else{
            char letter = (index-10) + 65;
            cout << letter;
         }
      }
   }
}

//input: the user string, the boolean array, and the length of the string
//output: none
//gets the string array and changes the boolean array values to match whether it is a number or a letter.
void sortString(string stuff, bool check[], int end){
   if(end < 0){
      printString(check, 36);
   }else{
      if(isdigit(stuff[end])){
         int num = (int) stuff[end];
         if(check[num] == false){
            check[num] = true;
         }
      }else{
         if(isalpha(stuff[end])){
            int alpha = (int) stuff[end];
            int asci = (alpha % 65) + 10;
            if(check[asci] == false){
               check[asci] = true;
            }
         }
      }
      sortString(stuff,check,end-1);
   }
}

//gets user input for a string of characters
//calls the upperCases function to make letters uppercase
//calls the sortString function to change the boolean array variables, then print out the string of ordered characters
int main(){
   string stuff = "";
   bool check[36] = {false};
   cout << "Enter a string: " << endl;
   cin >> stuff;
   int end = stuff.length()-1;
   upperCases(stuff, end);
   sortString(stuff, check, end);
}