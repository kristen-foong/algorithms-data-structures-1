#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;
void initializecards(int deck[], int size); 
void initializecards(int deck[], int size,int pos);
void shufflecards(int deck[], int size);
void shufflecards(int deck[], int size,int pos);
void printForwards(const int deck[],const string suits[] ,const string ranks[],int size);
void printForwards(const int deck[],const string suits[] ,const string ranks[],int size,int pos);
void printBackwards(const int deck[],const string suits[] ,const string ranks[],int size);
void printBackwards(const int deck[],const string suits[] ,const string ranks[],int size,int pos);

void initializecards(int deck[], int size){
   if(size!=0){         
      initializecards(deck,size,size-1);
   }
}

void initializecards(int deck[], int size, int pos){
   if(pos > -1){
      deck[pos] = pos;
   }
   initializecards(deck,size-1);
}

void shufflecards(int deck[], int size){
   shufflecards(deck,size,0);
}

void shufflecards(int deck[], int size, int pos){
   //~ int num  = rand() % 51;
   //~ if(pos > -1){
      //~ deck[pos] = num;
   //~ }
   //~ shufflecards(deck,size-1);
   //~ 
   
   if(pos < size){
      int random = rand() % 52;
      int num = deck[pos];
      deck[pos] = deck[random];
      deck[random]=num;
      shufflecards(deck,size,pos+1);
   }
   
}

void printForwards(const int deck[],const string suits[] ,const string ranks[],int size){
   printForwards(deck,suits,ranks,size,0);
}
   
void printForwards(const int deck[],const string suits[] ,const string ranks[],int size,int pos){
   if(pos < size){
      string theSuit = suits[(deck[pos])/13];
      string theRank = ranks[(deck[pos])%13];
      cout << "Card number " << pos << ": " <<  theRank << " of " << theSuit << endl;
      printForwards(deck,suits,ranks,size,pos+1);
   }
}

int main()
{
   const int NUMBER_OF_CARDS = 52;
   int deck[NUMBER_OF_CARDS];
	string suits[] = {"Spades", "Hearts", "Diamonds", "Clubs"};
   string ranks[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9",
      "10", "Jack", "Queen", "King"};

   //Initialize Cards
   initializecards(deck,NUMBER_OF_CARDS);
   
   // Shuffle the cards
   srand(time(0));
   shufflecards(deck,NUMBER_OF_CARDS);

   //Print deck Forward
   cout << "Forwards"<< endl;
   printForwards(deck,suits,ranks,NUMBER_OF_CARDS);

   //Print deck Backward
   //cout << "Backwards"<< endl;
   //printBackwards(deck,suits,ranks,NUMBER_OF_CARDS);
   return 0;
}