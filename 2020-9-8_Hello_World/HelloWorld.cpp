// Collin Li
// Data Structures H
// 9/10/2020
// Classwork 2

// Preprocessor directive
#include <iostream>
#include <string>
using namespace std;

// Start of the program
int main() {

	// Directions    
    cout << "We are going to play a fun game\n";
    cout << "You will enter 3 integers and I will \"math\" them\n";
    
    // Declare variables to store an integer
    int inputNumber1 = 0;
    int inputNumber2 = 0;
    int inputNumber3 = 0;
    
    // Get the integers
    cout << "Enter integer1: ";
    cin >> inputNumber1;
    
    cout << "Enter integer2: ";
    cin >> inputNumber2;
    
    cout << "Enter integer3: ";
    cin >> inputNumber3;
    
    // The same with text (string) data
    cout << "Enter your name: ";
    string inputName = "";
    cin >> inputName;
    
    // Help confirm and debug
    cout << inputName << " entered " << inputNumber1 << ", " << inputNumber2 << ", " << inputNumber3 << endl;
    
    // Print out the "math"
    cout << "Doing math...\n";
    cout << inputNumber1 * inputNumber2 * inputNumber3;
    
    return 0;
}