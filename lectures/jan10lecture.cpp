/*** JAN 10 LECTURE **/

/* what's expected in comments:

Name (Kristen Foong)
Name of program (eg. A1.cpp)
What the program does

before a function:
// state inputs
// state outputs
// what does it do?

*/

#include <iostream>
#include <time>
#include <cstdlib>
#include <string>
using namespace std;

/**
int f(int&y){
	y+=4;
	return 42;
}

int main() {
	int x= 0;
	f(x);
	cout << x;
}
**/

/*
int main() {
	int x = 4;
	int y = 6;
	swap(x,y);
	cout << swap(x,y) << endl;
}

void swap(int&x,int&y){
	int s = x;
	x = y;
	y = s;
}
*/

/*
int f(const int&x) {
	-= 4 <--- error
}
*/

/* Arrays
	type name[size]
	int arr[10];
	arr[11] => returns garbage 
	
	const int SIZE = 10;
	int arr[SIZE];
	can't assign a variable was a length eg. type name[Size]
	
	int arr[4] = {1,2,3,4};
	int arr[] = {1,2,3,4};
	
	7.2.4 in textbook
	Initializing arrays:
	
	//cout statement asking for values
	for(int i = 0; i < ARRAY_SIZE; i++){
		cin >> myList[i]
	}

	//rand values in array
	add rand value as cin kinda
	
	//printing arrays
	for(int i = 0; i < ARRAY_SIZE; i++){
		cout << myList[i] << " ";
	}
	
	//Copying Arrays
	Suppose you have two arrays, list and myList
	list = myList;
	THIS IS NOT ALLOWED
	so
	for(int i = 0; i < ARRAY_SIZE; i++) {
		cout for each index
	}
	
*/

/*
int main() {
	const int ARRAY_SIZE = 10;
	int myList[ARRAY_SIZE] = {1,2,3,4,5,6,7,8,9,10};
	int large = 0;
	for (int i = 0; i < ARRAY_SIZE; i++){
		if(myList[i] > large){
			large = myList[i];
		}
	}
	cout >> large >> endl;
}
*/

/* Gets array, prints it
	void arr(const int x[], int ARRAY_SIZE){
		for(int i = 0; i < ARRAY_SIZE; i++){
			cout << x[i] << endl;
		}
	}
note that the 'const' is a good idea. It's bad structure if you don't pass it as a constant.

passing multidimensional arrays:
void arr(const int x[][], int ROW, int COL){}

you CANNOT return arrays.

void copy(const int x[], int y[], int SIZE){
	for(int i = 0; i < SIZE; i++){
		y[i] = x[i];
	}
}
*/

int main() {
	const int SIZE = 10;
	int x[SIZE] = {1,2,3,4,5,6,7,8,9,10};
	int arr[SIZE];
	flip(x, arr, SIZE);
	return 0;
}

void flip(int x[],const int y[], int SIZE){
	int j = 0;
	for(int i = SIZE; i > 0; i--){
		y[i] = x[j];
		j++;
	}
}

