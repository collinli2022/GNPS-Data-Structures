// Collin Li
// 9/11/2020
// Data Structures
// Classwork 3a
/*
Write a program that
demonstrates that the size of an
unsigned integer and a normal
integer are the same, and that
both are smaller in size than a
long integer (and long long if
you’d like).
*/

// Preprocessor directive
#include <iostream>
using namespace std;


// Start of Program
int main() {
	
	// See size
	cout << "Printing out byte size of unsigned int, int, and long int (in that order respectfully)" << endl;
	cout << sizeof(unsigned int) << endl; // prints out 4
	cout << sizeof(int) << endl; // prints out 4
	cout << sizeof(long int) << endl; // on my computer it prints out 4 for a long int
	cout << sizeof(long long int) << endl; // prints out 8 for a long long int
	
	// Compare (1 = true, 0 = false)
	cout << "Comparing unsigned integer, normal int, and long int" << endl;
	cout << "unsigned integer == normal int: " << (sizeof(unsigned int) == sizeof(int)) << endl;
	cout << "unsigned int == long int: " << (sizeof(unsigned int) == sizeof(long int)) << endl;
	cout << "int == long int: " << (sizeof(int) == sizeof(long int)) << endl;
	cout << "int == long long int: " << (sizeof(int) == sizeof(long long int)) << endl;
	
	
	return 0;
}
