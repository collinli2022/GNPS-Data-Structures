// Collin Li
// Data Structures
// 10/8/2020
// Classwork 9
/*
Write a class called Circle that
computes the area and
circumference using the radius that
is supplied to the class as a
parameter at the time of
instantiation. Pi should be contained
in a constant private member that
cannot be accessed from outside the
circle. Your main function must
create and display the information
on a minimum of 3 circles
*/

// Preprocessor directive
#include <iostream>
#include <string>
using namespace std;

// Class
class Circle {
	private:
		// I like Pie... 
		double Pi = 3.14159;
		double radius = 0;
		
	public:
		Circle(double r) { // Constructor
			radius = r;
		}
		double getArea() { // computes the area
			return Pi * radius * radius;
		}
		double getCircumference() { // computes the circumference
			return Pi * 2 * radius;
		}
		~Circle() {
		}
};

int main() {
	// Ask for radius of 3 circles
	int r1=0, r2=0, r3=0;
	cout << "Please enter 3 radii seperated by *spaces*" << endl;
	cin >> r1;
	cin >> r2;
	cin >> r3;
	
	Circle circle1(r1), circle2(r2), circle3(r3); // Circle instances
		
	// print out info
	cout << "The circle with raidus " << r1 << " has a area of " << circle1.getArea() << " and a circumference of " << circle1.getCircumference() << endl;
	cout << "The circle with raidus " << r2 << " has a area of " << circle2.getArea() << " and a circumference of " << circle2.getCircumference() << endl;
	cout << "The circle with raidus " << r3 << " has a area of " << circle3.getArea() << " and a circumference of " << circle3.getCircumference() << endl;
	
	return 0;
}
