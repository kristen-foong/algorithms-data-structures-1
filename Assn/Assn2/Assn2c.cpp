//~ Kristen Foong
//~ Assn 2: Birthday Paradox
//~ Estimates probability P that if N people are in a room, at least two will have the same birthday

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int trials(int trials, int bdays[], const int SIZE);
void bdays(int bdays[], const int SIZE);

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
void bdays(int bday[], const int SIZE){
   for(int i = 0; i < SIZE; i++){
      bday[i] = 1 + ( rand() % 365 );
   }
}


//input: the day array, month array, and min number of people
//output: the number of trials where at least 2 people with the same birthdays
//counts the number of trials where at least 2 people have the same birthday
int trials(int bday[], const int SIZE, int t){
   int count=0;
   for (int k=0; k<t; k++){
      bdays(bday, SIZE);
      for(int i=0; i < (SIZE-1); i++){
         for(int j=i+1; j < SIZE; j++)
         {
            if((bday[i] == bday[j])){
               count++;
               i = SIZE;
               break;
            }
         }
      }
   }
   return count;
}

//input: day and month arrays, the step range, the minimum number of persons, the number of trials
//output: prints out the probability
//gets the number of times people have the same birthday, then computes the probability and prints it out
void getProbability(int bday[], int r, const int SIZE, int t){
   int count = 0;
   double p = 0.0;
   cout << "People Probability" << endl;
   for(int i = SIZE; i <= (SIZE+r); i++){
      count = trials(bday, i, t);
      p = (double) count/t;
      cout << i << "\t" << p << endl;
   }
}

//gets the user input for number of trials, people, and the step range, then calls the probability function
int main(){
   int t = getTrials();
   const int SIZE = getPeople();
   int r = stepRange();
   int bday[SIZE];
   srand(2);
   getProbability(bday,r,SIZE,t);
}