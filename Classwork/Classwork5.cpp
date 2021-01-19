// Collin Li
// Data Structures H
// 9/15/2020
// Classwork 5
/*
Write a program that asks the user
to input two Boolean values and
demonstrates the result of various
bitwise operators on them.
*/

// Preprocessor directive
#include <iostream>
using namespace std;

// Start of program
int main() {
	
	// Declare boolean
	bool a; // former
	bool b; // latter
	
	cout << "Enter 2 booleans: " << endl;
	
	// Get input
	cin >> a;
	cin >> b;
	
	cout << "You entered: " << a << " and " << b << endl << endl;
	
	// Test various bitwise operators
	
	// &
	cout << "a & b: " << (a & b) << endl;
	
	// |
	cout << "a | b: " << (a | b) << endl;
	
	//^
	cout << "a ^ b: " << (a ^ b) << endl;
	
	//~
	cout << "~a: " << (~a) << endl;
	cout << "~b: " << (~b) << endl;
	
	return 0;
	
}
