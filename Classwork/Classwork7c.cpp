// Collin Li
// Data Structures H
// 9/29/2020
// Classwork 7 (part 2)
/*
Write a function that accepts a
nonnegative integer from the user
and displays true in main if the
integer is a perfect number. The
function has no return and no print.
*/

// Preprocessor directive
#include <iostream>
using namespace std;

// determines if a number is a perfect number or not
void isPerfect(int num, bool& isIt) {
	int sum = 0 ; // sum of numbers 
	int interval = 1; // interval
	if (num == 0) { // 0 is NOT a perfect number
		return;
	}
	while (interval < num) {
		if (num % interval == 0) { // looking for factors
			sum = sum + interval; // add factors
		}
       interval++; // increment by 1
	}
	isIt = (sum==num); // a pointer	
	// if the integer is a perfect number. The function has no return and no print.
}

int main() {
	int num = 0;
	bool isIt = 0;
	cout << "Enter a POSITIVE number to check if it is perfect number: ";
	cin >> num;
	if(num < 0) { // needs to be positive
		cout << "That is NOT a positive number ;(";
		return 0;
	}
	isPerfect(num, isIt); // call function
	if(isIt) { // true = perfect
		cout << num << " is a perfect number" << endl;
	} else { // else... not perfect
		cout << num << " is NOT a perfect number" << endl;
	}
	return 0;
}
