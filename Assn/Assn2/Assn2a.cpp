//~ Kristen Foong
//~ Assn 2: Birthday Paradox
//~ Estimates probability P that if N people are in a room, at least two will have the same birthday

#include <iostream>
#include <ctime>
using namespace std;

int trials(int trials,int n);
int bdayMonths();
int bdayDays(int month);

//input: user input
//output: the number of trials to run
//asks the user for the number of trials to run, minimum 3000
int getTrials(){
   int t;
   cout << "Enter the number of trials: " << endl;
   cin >> t;
   while(t < 3000){
      cout << "Number of trials should be at least 3000" << endl;
      cin >> t;
   }
   return t;
}

//input: user input
//output: the number of people
//asks the user for the minimum number of people
int getPeople(){
   int n;
   cout << "Enter the minimum number of people: " << endl;
   cin >> n;
   while(n < 2){
      cout << "Minimum number of people should be at least 2" << endl;
      cin >> n;
   }
   return n;
}

//inputs: none
//outputs: none
//puts a random number month into the month array
int bdayMonths(){
   int month = 1 + rand() % 13;
   return month;
}

//inputs: the day array and the number of people
//outputs: none
//puts a random day into the day array. Ensures that the month & amount of days matches up so we don't have 31 days in february.
int bdayDays(int month){
   int day;
   // if birthday falls in first half of year & is odd
   if((month<=7) && ((month)%2==1)){
      day = 1+ rand() % 32;
   }
   //if birthday is in february
   else if(month==2){
      day = 1 + rand() % 28;
   }
   //if birthday falls in first half of year & is even and IS NOT february
   else if((month<=7) && ((month)%2==0) && ((month)!=2)){
      day = 1 + rand() % 31;
   }
   //if birthday falls in latter half of year & is even
   else if((month>7) && ((month%2)==0)){
      day = 1 + rand() % 32;
   }
   //if birthday falls in latter half of year & is odd
   else if ((month>7) && ((month%2)==1)){
      day = 1 + rand() % 31;
   }
   return day;
}

//input: number of trials and people
//output: number of people with the same birthday
//counts the number of times the same people have the same birthday
int trials(int trials,int n){
   int count = 0;
   for(int t = 0; t < trials; t++){
      for(int i = 0; i < n; i++){
         int month = bdayMonths();
         int day = bdayDays(month);
         int month2 = bdayMonths();
         int day2 = bdayDays(month2);
         if((month == month2) && (day == day2)){
            count++;
         }
      }
   }
   return count;
}

int main(){
   int t = getTrials();
   int n = getPeople();
   srand(time(0));
   int p = (trials(t,n))/t;
   cout << p;
}