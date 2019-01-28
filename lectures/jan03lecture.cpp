#include <iostream>
using namespace std;
const double PI = 3.14159; //convention: when making constant, ALL CAPS
int main() {
	
	double r, area;
	
	//step 1: read in radius
	cout << "type in radius" << endl;
	cin >> r;
	
	/**
	* if you do not use using namespace std, you need to add std:: before the cout so it looks like 
	* std::cout << "type in radius" << endl
	**/
	
	//step 2: compute area
	area = r*r*PI;
	
	//step 3: display area
	cout << "Area is " << area << endl;
	
	
	/**extra lecture stuff not related to above program here**/
	
	int i = j = k = 0;
	
	/** Bytes
	
	short				2 bytes		-2^15 to 2^15-1
	unsigned short		2 bytes		0 to 2^10
	int					4 bytes		-2^2 to 2^31-1
	float				4 bytes		
	long 				4 bytes		
	long double			10 bytes	
	
	**/
	
	/** Operators
	
	* / - + % all operators are the same
	* brackets too
	
	**/
	
	//idk man he wrote INT_MAX and INT_MIN on the board but idk why
	
	//anything that isn't 0 is TRUE. 0 = FALSE.
	//while(1) will run forever!!!!!
	
	/** To Cast
	* To cast:
	* static_cast<type>var
	**/
	
	//If statements
	//remember brackets!! +10 neatness, +5 readability, +20 to not messing the fuck up
	/** 
	if(blergh) {
		stuff
	}else if(boolexp){
		more stuff
	}
	
	boolean expression is like
	==
	!=
	>= , <=
	> , <
	||
	&&
	**/
	
	//switch cases
	/** 
	jk i can't really see the board
	
	switch(var){
		case val: — block; break;
	}
	
	**/
	
	//while loop yippee
	/** =
	while(boolean expression){
		//codeblock
	}
	**/
	
	//do-while loop
	/** 
	do {
		//codeblock
	}while(blah);
	**/
	
	//for loop
	/** 
	for(int i = 0; boolean; i++){
		//codeblock
	}
	**/
	
	
	//FIZZBUZZ
	//divisible by 2, print fizz
	//divisible by 5, print buzz
	//divisible by both, print fizzbuzz
	
	for(int i = 1; i <=100; i++){
		if(i%2 == 0 && i%5 == 0){
			cout << "fizzbuzz" << endl;
		}else if (i%2 == 0 && i%5 != 0) {
			cout << "fizz" << endl;
		}else if (i%2 != 0 && i%5 == 0){
			cout << "buzz" << endl;
		}
	}
	
	/** Zier-Vogel's solution
	
	int i = 1;
	string out;
	while (i <= 100){
		out = to_string(i);
		if(i%2 == 0) {
			out = "fizz";
			if(i%5 == 0) {
				out = "buzz";
			}
		}else if (smth){
			idk man it was rando
		}
	}
	
	**/
	
	/** Take a number and turn it into a string example
	
	int i = 1;
	string out;
	out = to_string(i);
	
	**/

	//rand()
	/**
	
	to generate a number between a and b, do  a + rand() % b
	eg. 0 + rand() % 10 will generate a number between 0 and 10
	
	before doing a random,
	#include <ctime>
	int main() {
		srand(time(0));
		OR
		srand(1000);
		rand()
	}
	
	**/
	
	return 0;
}