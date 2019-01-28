#include <iostream>
#include <cstring>
#include <cmath>
// #ifndef POINTS_H
// #define POINTS_H
// #include "Points.h" include header file

using namespace std;

class Employ{
   public:
      Employ(string f, string l, unsigned short eN, unsigned short w);
      string getName();
      void raise(unsigned short r);
      double pay(unsigned short hours); //1.5*wage for over time
      void nameChange(string f, string l);
   private:
      string first;
      string last;
      unsigned short eNum;
      unsigned short wage;
};

// #endif

Employ::Employ(string f, string l, unsigned short eN, unsigned short w){
   first = f;
   last = l;
   eNum = eN;
   wage = w;
}

string Employ::getName(){
   return first + " " + last;
}

void Employ::raise(unsigned short r){
   wage = wage+r;
}

double Employ::pay(unsigned short hours){
   if(hours >= 40){
      return wage*hours + (wage*1.5*(hours-40));
   }else{
      return wage*hours;
   }
}

void Employ::nameChange(string f, string l){
   first = f;
   last = l;
}

/* int main(){
   //cin.ignore(2); //ignores the extra 2 characters of given input
} */

/*****MAKE FILES*****/

/* 
VERSION = -std=c++11
CFLAGS = -pedantic -wall -wextra $(VERSION) $(DEBUG)
LFLAGS = -wall $(VERSION) $(DEBUG)
INCS = Points.h
SRCS = Points.cpp \
   GoCode.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = funTimes

all: $(SRCS) $(EXEC)

// To make an object from source
// .cpp.o:
%.o:%.cpp $(INCS)
   $(CXX) $(CFLAGS) -c $< -o $@

$(EXEC): $(OBJS)
//theres more i can't see it'll be posted on d2l anyway
*/



/**** OVERLOADING OPERATORS ****/

class Time{
   public:
      //though not checked for, h should be <24, m should be <60, s should be <60
      Time(int h, int m, int s);
      //
      Time();
      //initializes time to s seconds after midnight
      Time(int s);
      // set the time to h hours, m minutes, s seconds
      void setTime(int h, int m, int s);
      //read from cin, read 3 integers
      void readTime();
      //output to standard output with the format m:h:s
      void printTime() const;
      
      //accessor functions
      int hours() const {return hrs;}
      int minutes() const {return mins;}
      int seconds() const {return secs;}
      
   private:
      int hrs, mins, secs;
};

//standalone operator functions
bool operator == (const Time& t1, const Time& t2);
bool operator != (const Time& t1, const Time& t2);
const Time operator + (const Time& t1, const Time& t2);

#endif

//Time.cpp code, link Time.h code

// #include "Time.h"

Time::Time(int h, int m, int s): hrs(h), mins(m), secs(s) {
   //empty
}

//initialize to midnight with 0 0 0 
Time::Time(): hrs(0), mins(0), secs(0) {
   //empty
}

Time::Time(int s): hrs(0), mins(0), secs(s){
}

void Time::setTime(int h, int m, int s){
   hrs = h;
   mins = m;
   secs = s;
}

void Time::readTime(){
   //could have included error checking
   cin >> hrs >> mins >> secs;
}

void Time::printTime() const {
   cout << hrs << ":" << mins << ":" << secs;
   
}

//standalone operator function not a member function
bool operator == (const Time& t1, const Time& t2){
   return (t1.hours() == t2.hours() &&
   t1.minutes() == t2.minutes() &&
   t1.seconds() == t2.minutes() );
}

//standalone operator function, not a member function
bool operator != (const Time& t1, const Time& t2){
   return( t1.hours() != t2.hours() || t1.minutes() != t2.minutes() || t1.seconds() != t2.seconds() );
}

const Time operator + (const Time& t1, const Time& t2){
   int carry = 0;
   int s = t1.seconds() + t2.seconds();
   if(s >= 60){
      s -= 60;
      carry = 1;
   }
   int m = t1.minutes() + t2.minutes() + carry;
   if(m >= 60){
      m -= 60;
      carry = 1;
   }else {
      carry = 0;
   }
   int hours = t1.hours() + t2.hours() + carry;
   h %= 24;
   return Time(h, m, s);
}



/****** MEMBER OPERATORS *******/

// take the code above, then add in
//NOTE: MISSING A LOT

// member operator functions
const Time operator - (const Time& t2);
//divide the time by a factor
const Time operator / (int factor) const;
bool operator != (const Time& t2);

//overload >> for input
// the expected input is three integers corresponding to the hours, the minutes, and the seconds
// the values should be described above with hours <24, minutes <60, seconds <60
// NOTE: no error checking is done in this code
//precondition:
//the input stream is open
friend std::istream& operator >> (std::istream& inputStream, Time&);

//overload << for output
// the time is printed in the form (hours:minutes:seconds)
// precondition: 
// the output stream is open
friend std::ostream& operator << (std::ostream& outputStream, const Time&);

//the friend thing makes private things not private

private:
   int hrs, mins, secs;

};

//cont'd on Feb 21 but it doesn't quite look the same? idk 
const Time Time::operator - (const Time& t2){
   int borrow = 0;
   int s = seconds - t2.seconds();
   if(s < 0) {
      s += 60;
      borrow = 1;
   }
   int m = minutes - t2.minutes() - borrow;
   if(m < 0) {
      m += 60;
      borrow = 1;
   }
   else {
      borrow = 0;
   }
   int h = hours - t2.hours() - borrow;
   if( h < 0){
      h += 24;
   }
   return Time(h,m,s);
}

//as a member function, divide the time by a factor
const Time Time::operator / (int factor) const {
   //calculate the total number of seconds and store in x
   int x = hrs * 3600 + mins * 60 + secs;
   //divide by the factor
   x /= factor;
   //convert x into hours, minutes, and seconds
   int h = x / (3600);
   x %= 3600;
   int m = x/60;
   x %= 60;
   int s = x;
   Time tmp = Time(h,m,s);
   return tmp;
}

//as a member function
bool Time::operator != (const Time& t2) {
   return (hrs); //dunno there's more
}

// haha fuck there's a lot missing right here
//where is this shit
//idek if the rest goes under here or not

Time::Time(int h, int m, int s): hrs(h), mins(m), secs(s) {
}

//initialize to midnight with 0 0 0
Time::Time(): hrs(0), mins(0), secs(0){
}

void Time::readTime(){
   //could have included error checking
   cin >> hrs >> mins >> secs;
}

void Time::printTime() const {
   cout << hrs << ":" << mins << ":" << secs;
}

ostream& operator << (ostream& outputStream, const Time& t) {
   outputStream << "  (" << t.hrs << ":" << t.mins;
   outputStream << ":" << t.secs << ")";
   return outputStream;
} //what is a friend??????

istream& operator >> (istream& inputStream; Time& t) {
   inputStream >> t.hrs >> t.mins >> t.secs;
   return inputStream;
}




//randommain idk why

int main() {
   Time labStart(16,30,0);
   Time labEnd(18,20,0);
   
   //more fuckery here
   
   cout << "\nlabStart is " << labStart << "\n";
   Time noon;
   cout << "give me the time for noon: ";
   cin >> noon;
   cout << "noon was" << noon << "\n";
   
   Time g, h;
   //legal
   h = h.operator-(g);
   //more natural
   h = h - g;
   return 0;
}

/* 
MONDAY QUIZ
get a header
write the cpp
*/