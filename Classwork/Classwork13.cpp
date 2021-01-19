// Collin Li
// Data Structures
// 12/2/2020
// Classwork 13
/*
Write a program that simulates
rolling a pair of 6-sided dice using
static_cast. The numeric distribution
should be standard. Then, loop it
10,000 times and display the
percentage of each result.
*/

// Preprocessor directive
#include <iostream>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <ctime>
using namespace std;

int main() {
	int again = 0;
	srand(time(NULL)); // random seed (not really "random" but...)
	do {
		// possible numbers: 2 3 4 5 6 7 8 9 10 11 12
		int occurances[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // store the number of occurences
		int total = 10000;
		for(int i = 0; i < total; i++) { // roll 10,000 times
			int diceRoll = rand() % 6 + rand() % 6; // simulate dice roll
			occurances[diceRoll] = occurances[diceRoll] + 1; // count the roll
		}
		//double test = 0; // used to make sure all values add up to 100
		for(int i = 0; i < 11; i++) {
			cout << i+2 << ": " << static_cast<double>(occurances[i])/total*100 << "%" << endl; // display percentages
			//test += static_cast<double>(occurances[i])/static_cast<double>(total)*100;
		}
		//cout << test << endl;
		cout << "Do again? (1-yes, 0-no): ";
		cin >> again;
	} while (again == 1);
	return 0;
}
