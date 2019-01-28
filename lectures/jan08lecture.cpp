/** JAN 8 LECTURE **/

#include <ctime>
#include <iostream>

#include <cstdlib>

#include <cctype> //can now use character stuff: isdigit(ch), isalpha(ch), isalnum(ch), islower isupper toupper tolower etc.
#include <cmath> // now lets you do the mathy stuff like PI and pow

using namespace std;

int power(int a, int b) {
	return pow(a,b);
}

/* we can also define a variable so it's always the same value
	
	int power(int a, int b = 2) {
		int r;
		for(int i = 0; i < b; i++){
			r*=a;
		}
		return r;
	}
	
	however you cannot declare a value and have an undeclared value after. don't make no sense.
	default values come at THE END
	
*/

/* overloading: same as methods, the program will choose the list of parameters which best fit what we're looking for
*/

// Prototype Function -- super handy!
/*int max(int num1, int num2);
double max(double num1, double num2);
double max(double num1, double num2, double num3);*/

int celsFar(double num);

int main() {
	
	/* <-- erase this comment mark thingy to make stuff show up as actual code. also erase this comment LOL
	srand(time(0));
	cout << rand() << endl;
	
	//coin flip code
	for (int i = 0; i < 100; i++) {
		int t = 0 + rand()%2;
		if (t%2 == 1) {
			cout << "heads" << endl;
		}else {
			cout << "tails" << endl;
		}
	}
	
	//information on a bunch of libararies on pg. 131 & 132 --> GET THE BOOK if i get in the course duh lol oops
	
	string s1 = "Hello";
	string s2 = "world";
	string s3 = s1 + s2;
	cout << s3 << endl;
	
	cout << s3.length() << endl;
	
	s3[0]; // this returns the letter 'h' from s3's 'Helloworld'
	s3[11]; //is an ERROR
	
	string str;
	cin >> str; // allows only ONE word. So how to get a phrase?
	getline(cin,str); //allows user to put in spaces and will wait until the enter key is used
	//can also use getline(cin,s1,'\n') if you want. the \n functions as a limiter
	
	//Comparing strings
	"hello" == "Hello"; // = F
	"hello" != "Hello"; // = T
	
	str[0] = 'h';
	cout << str << endl; //this will change the H to h and print out 'helloworld' instead of Helloworld
	
	//THIS DOESNT WORK IDK MAN
	for (int i = 0; i < str.length(); i++){
		cout << toupper(str[i]) << endl;
	}
	
	//page 118-119 about math stuff
	//ceiling, floor, max, min, abs
	/*
		max(4,5) = 5
		will return the type given!!!
		max(4.6,5.5) = 5.5
	*/
	/* To round up/down:
		floor(5.1+0.5) = 5 
		floor(5.6+0.5) = 6
	*/
	
	/* Functions == Methods in C++
	we use int main() we can now make new things 
	
		int sum(int i1, int j1){
			int sum = 0;
			for(int i = i1; i <= j1; i++){
				sum+=i;
			}
			return sum;
		}
		int main() {
			cout << sum(1,10) << endl;
		}
	
	*****NOTE THAT THE MAIN METHOD IS AT THE BOTTOM*****
	*****marks will be given for this!!!*****
	keep functions as short and neat as possible
	--> idk man he just said do camel case functions sO DO THEM THROUGHOUT THIS COURSE HAHAHA
	
	work same as java but without public static void merp
	
	can return void to return nothing
	
	*/
	
	/* Say you want to end a function NOT in main (DUN USE)
		must import the <cstdlib>
		#include <cstdlib>
		this will let you use exit
		exit(1); will kill ur program. DONT USE IT AHAHA
	*/
	
	/* 
	int a = 3;
	int b = 2;
	cout << power(a,b) << endl;
	*/
	
	/* Prototype function invocation 
	cout << "max between 3 & 4" << max(3,4) << endl;
	cout << "max between 3.0 & 4.6 is" << max(3.0,4.6) << endl; */
	
	// Cels to Fahr function
	double p;
	cin >> p;
	cout << "Celsius to Fahrenheit Conversion: " << p << " is " << celsFar(p) << " in Fahrenheit" << endl;
	
	/* Pass By Reference -- NEAT AND HANDY AND IN ASSIGNMENTS AND IMPORTANT
		
		int& x; // This is now a reference to a variable. stores a location of something.
		
		int& x;
		int y = 5;
		x = y; // This isn't 5. This is equal to a position in memory that is 5...
		
		void minMax(int a, int b, int& max, int& min) {
			if(a > b){
				max = a;
				min = b;
			}else {
				max = b;
				min = a;
			}
		}
		
		int a = 5, b = 7;
		int min, max;
		minMax(a, b, max, min);
	
	*/
	
}

int celsFar(double num) {
	double f = (num*(9/5))+32;
	return f;
}
