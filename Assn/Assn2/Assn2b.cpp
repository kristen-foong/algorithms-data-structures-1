//~ Kristen Foong
//~ Assn 2: Birthday Paradox
//~ Estimates probability P that if N people are in a room, at least two will have the same birthday

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int trials(int trials, int bdays[], const int SIZE);
void bdayMonths(int month[], const int SIZE);
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
void bdayMonths(int month[], const int SIZE){
   for(int i = 0; i < SIZE; i++){
      int r = 1 + rand() % 12;
      month[i] = r;
   }
}

//inputs: the day array and the number of people
//outputs: none
//puts a random day into the day array. Ensures that the month & amount of days matches up so we don't have 31 days in february.
void bdayDays(int day[], int month[], const int SIZE){
   bdayMonths(month, SIZE);
   for(int i = 0; i < SIZE; i++){
      // if birthday falls in first half of year & is odd
      if((month[i]<=7) && ((month[i])%2==1)){
         int r = 1 + rand() % 32;
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

//input: the day array, month array, and min number of people
//output: the number of trials where at least 2 people with the same birthdays
//counts the number of trials where at least 2 people have the same birthday
int trials(int day[], int month[], const int SIZE, double t){
   bdayDays(day, month, SIZE);
   int count=1;
   for(int i=0; i < SIZE; i++){
      for(int j = 1; j < SIZE; j++){
         if((month[i]==month[j]) && (day[i]==day[j])){
            count++;
         }
      }
   }
   return count;
}

//input: day and month arrays, the step range, the minimum number of persons, the number of trials
//output: prints out the probability
//gets the number of times people have the same birthday, then computes the probability and prints it out
void getProbability(int day[], int month[], int r, const int SIZE, double t){
   int count;
   double p;
   cout << "People Probability" << endl;
   for(int i = SIZE; i <= (SIZE+r); i++){
      count = trials(day,month,i,t);
      p = count/t;
      cout << i << "\t" << count << "\t" << p << endl;
   }
}

//gets the user input for number of trials, people, and the step range, then calls the probability function
int main(){
   double t = getTrials();
   const int SIZE = getPeople();
   int r = stepRange();
   int month[SIZE], day[SIZE];
   srand(time(0));
   getProbability(day,month,r,SIZE,t);
}