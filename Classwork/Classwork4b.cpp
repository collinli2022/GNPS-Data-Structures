// Collin Li
// Data Structures H
// 9/15/2020
// Classwork 4b
/*
Write a program that asks the user for
3 strings and creates a 2-dimensional
array, where each row contains the
given strings once. Then create a 2-
dimensional array, where each
column contains the given strings
once.
*/

// Preprocessor directive
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Prints out the array (duh again)
void printArr(string array[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
}

// Start of the program
int main() {
	
	// The 3 strings
	string a = "";
	string b = "";
	string c = "";
	cout << "Enter 3 strings:" << endl;
	
	// Using cin so cannot take in spaces 
	cin >> a;
	cin >> b;
	cin >> c;
	cout << endl; // and extra line to make it look better
	// Each row has the strings once
	string array1[3][3];
	for (int i = 0; i < 3; i++) {
		array1[i][0] = a;
		array1[i][1] = b;
		array1[i][2] = c;
	}
	printArr(array1);
	cout << endl; // and extra line to make it look better
	// Each col has the strings once
	string array2[3][3];
	for (int i = 0; i < 3; i++) {
		array2[0][i] = a;
		array2[1][i] = b;
		array2[2][i] = c;
	}
	printArr(array2);
	
	return 0;
}
