// Collin Li   
// Data Structures H
// 9/23/2020
// Classwork 6
/*
Write a program that adds
corresponding elements in two
same-sized arrays in reverse order
so that the sum of the last two
elements is first, etc.
{1,3,5,8} + {2,2,4,12} = {20,9,5,3}
*/

// Preprocessor directive
#include <iostream>
#include <string>
using namespace std;


// Start of program
int main() {
	
	int arrayLen = 4;
	// Two arrays
	int array1[arrayLen] = {}; // = {1, 3, 5, 8};
	int array2[arrayLen] = {}; // = {2, 2, 4, 12};
	// Final Array
	int arrayFinal[arrayLen] = {};
	
	// Get array length
	cout << "Array length: ";
	cin >> arrayLen;
	// Get inputs
	cout << "Give array1 values seperated by a space" << endl;
	for(int i = 0; i < arrayLen; i++) {
		cin >> array1[i];
	}
	cout << "Give array2 values seperated by a space" << endl;
	for(int i = 0; i < arrayLen; i++) {
		cin >> array2[i];
	}
	
	// Print out the inputed 2 arrays
	cout << endl;
	cout << "{";
	for(int i = 0; i < arrayLen; i++) {
		// to not print out an extra ,
		if(i == arrayLen - 1) {
			cout << array1[i];
		} else {
			cout << array1[i] << ",";
		}
	}
	cout << "}";
	cout << " + {";
	// Display arrays entered
	for(int i = 0; i < arrayLen; i++) {
		// to not print out an extra ,
		if(i == arrayLen - 1) {
			cout << array2[i];
		} else {
			cout << array2[i] << ",";
		}
	}
	cout << "}";
	// Do math time...	
	// Add in reversed order
	for(int i = 0; i < arrayLen; i++) {
		// arrayLen-1-i will make it go from end to front
		// and i goes from 0 --> arraylen-1
		arrayFinal[arrayLen - 1 - i] = array1[i] + array2[i];
	}	
	cout << " = {";
	// Print array
	for(int i = 0; i < arrayLen; i++) {
		// to not print out an extra ,
		if(i == arrayLen - 1) {
			cout << arrayFinal[i];
		} else {
			cout << arrayFinal[i] << ",";
		}
	}
	cout << "}";
	cout << endl; 
	
	return 0;	
}
