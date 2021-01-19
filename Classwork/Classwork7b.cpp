// Collin Li
// Data Structures H
// 9/24/2020
// Classwork 7b
/*
Write overloaded functions that
calculate the volume of a sphere
and a cylinder.
*/

// Preprocessor directive
#include <iostream>
using namespace std;

// I like Pie... 
const double Pi = 3.14159;

// Calculate Volume of Sphere
double Volume (double radius) {
	return ((double)4)/3*Pi*radius*radius*radius;
}

// Overloaded function
// Calculate area of cylinder
double Volume (double radius, double height) {
	return Pi*radius*radius*height;
}

// Start of the program
int main() {
	
	// Ask for choice
	cout << "Choose choice 1 or 2:" << endl;
	cout << "\t 1: Calculate Volume of Sphere" << endl;
	cout << "\t 2: Calculate Volume of Cylinder" << endl;
	
	int choice = 0;
	cin >> choice;
	
	double radius = 0;
	double height = 0;
	
	if (choice == 1) { // Sphere
		// Ask for radius
		cout << "Enter radius: ";
		cin >> radius;
		
		cout << "The Volume of the Sphere is: "<< Volume(radius) << endl; // Return Volume
	} else if (choice == 2) { // Cylinder
		// Ask for radius
		cout << "Enter radius: ";
		cin >> radius;
		// Ask for height
		cout << "Enter height: ";
		cin >> height;
		
		cout << "The Volume of the Cylinder is: " << Volume(radius, height) << endl; // Return Volume of Cylinder
	} else {
		cout << "Invalid Choice!";
	}
	
	return 0;	
}

