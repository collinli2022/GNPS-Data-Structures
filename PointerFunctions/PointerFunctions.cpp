// Collin Li
// Data Structures H
// 10/01/2020
// MiniProject PointerFunctions    

// Preprocessor directive
#include <iostream>
#include <string>
using namespace std;


// This function swaps two integers using pointers.
void swap(int* a, int* b){
	int* temp1 = a;
	int* temp2 = b;
	// swap the two integers
	*a = *temp2;
	*b = *temp1;
	
}

/*
This function counts the number of both vowels and consonants in a given string. The input string will
contain no spaces and only capital letters. You MUST use a character pointer in this function instead of
using string or array notation.
*/
void letterCount(string s, int* numVowels, int* numConsonants) {
	// recomended to zero out
    *numVowels = 0;
    *numConsonants=0;
	char* charPointer = &s.at(0); // gets memory location of first letter
	for (int i = 0; i < s.size(); i++) { // loop through the string
		if(*(charPointer+i)=='A' || *(charPointer+i)=='E' || *(charPointer+i)=='I' || *(charPointer+i)=='O' || *(charPointer+i)=='U') { // check if he current char is a vowel or not
			*(numVowels)=*(numVowels)+1;
		} else {
			*(numConsonants)=*(numConsonants)+1;
		}
	}
}

/*
This function accepts a pointer that refers to the first element of an array of length elements. This
function will display each element and its memory location. The information for each element must be
on a new line.
*/
void arrayInfo(int* arrPtr, int length) {
	// loop through the array
	for (int i = 0; i < length; i++) {
		cout << "Index: " << i << " - Element: " << *(arrPtr + i) << " - Memory Location: " << (arrPtr+i) << endl; // Display element and memory location
	}
}


/*
In your main function, display a menu to ask the user for their desired task. Their options are listed below.
Once the user chooses a task, ask them for the input required for the function (and only for that function). When
the process is complete, ask the user if they want to do it again.
*/
int main () {
	bool again = 0;
	do {
		cout << "Which fucntion would you like to use?" << endl;
		cout << "1 - swap" << endl;
		cout << "2 - letterCount" << endl;
		cout << "3 - arrayInfo" << endl;
		int choice = -1;
		cin >> choice;
		if (choice == 1) { // Swap 
			int a=-1, b=-1;
			// need int a
			cout << "Enter int a: ";
			cin >> a;
			// need int b
			cout << "Enter int b: ";
			cin >> b;
			
			cout << "You entered: a-" << a << " and b-" << b << endl;
			swap(a, b);
			cout << "Swaped:      a-" << a << " and b-" << b << endl;
		} else if (choice == 2) { // Letter Count
			string s = "";
			int numVowels = 0, numConstants = 0;
			// need string
			cout << "Enter a string with no spaces and CAPITAL Letters only: ";
			cin >> s;
			// need pointer for numVowels
			// need pointer for numConstants
			letterCount(s, &numVowels, &numConstants);
			cout << "There are " << numVowels << " vowels and " << numConstants << " constants in the word: " << s << endl;
		} else if (choice == 3) { // Array Info
			// need array length
			int length = -1;
			cout << "Enter array length: ";
			cin >> length;
			// need array pointer
			int array[length] = {};
			cout << "Enter ints to fill the array seperated by *spaces* or *new line*" << endl;
			for (int i = 0; i < length; i++) {
				cin >> array[i];
			}
			// print array
			cout << "You entered the array: {";
			for (int i = 0; i < length; i++) {
				if (i==(length-1)) {
					cout << array[i] << "}" << endl;
				} else { 
					cout << array[i] << ", ";
				}
			}
			// call method
			int* arrayPtr = array;
			arrayInfo(arrayPtr, length);
		} else {
			cout << "That's not a valid choice" << endl;
		}
		
		// Ask if they want to do it agian
		cout << "Would you like to use the program again? 0-no, 1-yes: ";
		cin >> again;
	} while (again);
	return 0;
}
