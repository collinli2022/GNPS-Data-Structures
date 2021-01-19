// Collin Li
// Data Structures H
// 9/24/2020
// Classwork 7a
/*
Write a function with a return
type of void that still helps the
caller calculate the area and
circumference of a circle when
supplied the radius. No print in
function.
*/

// Preprocessor directive
#include <iostream>
using namespace std;

// I like Pie... 
const double Pi = 3.14159;

// output parameter result by reference 
void Area(double radius, double& result) {
   result = Pi * radius * radius; // circle area formula
}

// output parameter result by reference 
void Circumfrence(double radius, double& result) {
	result = Pi * radius * 2; // circle circumfrence formula
}

// Start of the program
int main() {
	// Ask for radius
	cout << "Enter radius: ";
	double radius = 0;
	cin >> radius;
	
	double areaFetched = 0;
	Area(radius, areaFetched);
	
	double circumfrenceFetched = 0;
	Circumfrence(radius, circumfrenceFetched);
	
	cout << "The area is: " << areaFetched << endl;
	cout << "The circumfrence is: " << circumfrenceFetched << endl;
	return 0;
}

