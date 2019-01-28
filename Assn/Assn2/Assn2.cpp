//~ Kristen Foong
//~ Assn 2: Birthday Paradox
//~ Estimates probability P that if N people are in a room, at least two will have the same birthday

#include <iostream>
#include <ctime>
using namespace std;

int trials(int trials, int bdays[], const int SIZE);
void bdayMonths(int day[], int month[], const int SIZE);
void bdayDays(int day[], int month[], const int SIZE);

//input: user input
//output: the user given number of trials
//asks the user for a number of trials, minimum 3000
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
//output: the user given number of people
//asks the user for a minimum number of people, at least 2
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

//input: user input
//output: the user given step range
//asks the user for a step range of persons
int stepRange(){
   int r;
   cout << "Enter the step for the range of persons:" <<endl;
   cin >> r;
   while(r<0){
      cout << "Range must be positive." << endl;
      cin >> r;
   }
   return r;
}

//inputs: the month array and the number of people
//outputs: none
//puts a random number month into the month array
void bdayMonths(int day[], int month[], const int SIZE){
   for(int i = 0; i < SIZE; i++){
      int r = rand() % 13;
      month[i] = r;
   }
}

//inputs: the day array and the number of people
//outputs: none
//puts a random day into the day array. Ensures that the month & amount of days matches up so we don't have 31 days in february.
void bdayDays(int day[], int month[], const int SIZE){
   bdayMonths(day, month, SIZE);
   for(int i = 0; i < SIZE; i++){
      // if birthday falls in first half of year & is odd
      if((month[i]<=7) && ((month[i])%2==1)){
         int r = 1+ rand() % 32;
         day[i] = r;
      }
      //if birthday is in february
      else if(month[i]==2){
         int r = 1 + rand() % 28;
         day[i] = r;
      }
      //if birthday falls in first half of year & is even and IS NOT february
      else if((month[i]<=7) && ((month[i])%2==0) && ((month[i])!=2)){
         int r = 1 + rand() % 31;
         day[i] = r;
      }
      //if birthday falls in latter half of year & is even
      else if((month[i]>7) && ((month[i]%2)==0)){
         int r = 1 + rand() % 32;
         day[i] = r;
      }
      //if birthday falls in latter half of year & is odd
      else if((month[i]>7) && ((month[i]%2)==1)){
         int r = 1 + rand() % 31;
         day[i] = r;
      }
   }
}

int trials(int day[], int month[], const int SIZE){
   bdayMonths(day, month, SIZE);
   int count=0;
   for(int i=0; i < SIZE; i++){
      for(int j = 0; j < SIZE; j++){
         if((month[i]==month[j]) && (day[i]==day[j])){
            count++;
         }
      }
   }
   return count;
}

int main(){
   int t = getTrials();
   int n = getPeople();
   int r = stepRange();
   const int SIZE = n;
   int month[SIZE], day[SIZE];
   srand(time(0));
   int count = trials(day,month,SIZE);
   cout << count;
}