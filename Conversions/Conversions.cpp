// Collin Li
// Data Structures H
// 9/18/2020
// Conversions

// Preprocessor directive
#include <iostream>
#include <string>
using namespace std;


// Personal function
int charToInt(char c) {
    if (c >= '0' && c <= '9') { // a number
    	return (int)c - '0'; 
	} else if(c >= 'a' && c <= 'z') { // a lowercase letter
		return (int)c + 10 - 'a';
	} else { // a uppercase letter
		return (int)c + 10 - 'A'; 
	}
} 

// Converts the argument integer from base 10 to the argument base (base <= 9)
// Positie numbers only
string toBase(int decimal, int base) {
	string reversed = "";
	string result = "";
	do {
		// using char since easy to convert to string
		char digit = decimal % base;
		digit += '0';
		reversed += digit; // going to be reversed 
		decimal = decimal / base; 
	} while (decimal > 0); // do until equal (or less than) 0
    // reverse order
    for(int i = reversed.size()-1; i >= 0; i--) {
    	result += reversed[i];
    }
    return result;
}
	
// Converts the argument integer from base 10 to base 16.
string toBase16(int decimal) {
	int base = 16; // declare the base we are converting to
    string reversed = ""; 
    string result = "";
    do {
        char digit = decimal % base;
        // Convert to correct base char
        // 0-9
        if(digit < 10) {
        	digit += '0'; // a number (ascii chart)
		} else {
			digit = digit - 10 + 'A'; // (going to be) a letter between A-F
		}
        // Append digit to string (in reversed order)
        reversed += digit;
        decimal = decimal / base;
    } while (decimal > 0); // do until equal (or less than) 0
    // reverse order
    for(int i = reversed.size()-1; i >= 0; i--) {
    	result += reversed[i];
    }
    return result;
}

//  Converts the argument string from the argument base to base 10.
int toInteger(string number, int base) {
	int len = number.size(); 
    int result = 0;  // result 
    int power = 1;
  
  	// go from end to front
    for (int i = len - 1; i >= 0; i--) {
    	// charToInt is a self-written function that changes a char to an int
        if (charToInt(number[i]) >= base) { // digit should never be greater than or equal to base
           cout << ("Invalid Number") << endl; 
           return -1; 
        } 
        result += charToInt(number[i]) * power; 
        power = power * base; 
    } 
    return result; 
}

// Converts the argument string from base 16 to base 10.
int toInteger16(string number) {
	int base = 16; // string number is in base 16
	int len = number.size(); 
    int result = 0;  // result 
    int power = 1;
  
  	// go from end to front
    for (int i = len - 1; i >= 0; i--) {
    	if (charToInt(number[i]) >= base) { // digit should never be greater than or equal to base (needs to be between 0 - F (including))
           cout << ("Invalid Number") << endl; 
           return -1; 
        } 
    	// charToInt is a self-written function that changes a char to an int  
        result += charToInt(number[i]) * power; 
        power = power * base; 
    } 
    return result; 
}
	


// Start of program
int main() {
	
	bool next = 0;
	
	do {
		// **Get number**
		cout << "Enter a base10 number to convert to a different base: ";
		int base10num = 0;
		cin >> base10num;
		
		cout << endl;
		cout << "Base : Output" << endl;	
		// **convert from base10 --> other base**
		for (int i = 2; i <= 9; i++) { // do every base from 2-9
			cout << i << " : " << toBase(base10num, i) << endl;		
		}
		cout << 16 << " : " << toBase16(base10num) << endl;	
		
		// **convert other base --> base10**
		cout << endl;
		cout << "Enter a number to convert to base10: ";
		string otherBasenum = "";
		cin >> otherBasenum;
		cout << "Enter the base that number is: ";
		int otherBase = 0;
		cin >> otherBase;
		
		cout << "The base" << otherBase << " number " << otherBasenum << " converted to base10 is: " << endl;
		if (otherBase == 16) { // From base16 to base10
			cout << "\t" << toInteger16(otherBasenum);
		} else { // From a base <=9 to base10
			cout << "\t" << toInteger(otherBasenum, otherBase);
		}
		
		cout << endl << endl; // extra spacing
		// **Ask to do again**
		cout << "Enter 1 to redo/restart and 0 to stop: ";
		cin >> next;
		cout << endl;
	} while(next);

	return 0;	
}
