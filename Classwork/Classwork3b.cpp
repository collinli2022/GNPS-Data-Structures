// Collin Li
// Data Structures H
// 9/10/2020
// Classwork 3b
/*
Write a program to calculate the
area and circumference of a
circle, where the user supplies
the radius.
*/

// Preprocessor directive
#include <iostream>
#include <string>
#include <cmath>
using namespace std;


// Start of the program
int main() {

	// Directions    
    cout << "We are going to calculate the area and circumference of a circle." << endl;
    cout << "You will enter the radius: ";
    
    // Declare variables to store an integer
    double radius = 0;

    cin >> radius;
    
    // Print out the "answer"
    cout << "Doing math...\n";
    
    // Equation for radius is 2*r*pi
    cout << "The radius is: ";
    cout << 2 * radius << "pi or about ";
    cout << 2 * radius * M_PI << endl;
    
    // Equation for area is pi*r*r
    cout << "The area is: ";
	cout << radius * radius << "pi or about ";
	cout << (double) radius * radius * M_PI << endl;
    
    return 0;
}
