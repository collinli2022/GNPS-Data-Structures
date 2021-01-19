// Collin Li
// Data Structures
// 10/20/2020
// Classwork 10

/*
Create classes Polygon, Triangle,
and Shape using proper inheritance
protocols. Have methods in each
that relate to the classes themselves.
Create an object in your main
function to test the implementation.
*/

// Preprocessor directive
#include <iostream>
#include <string>
using namespace std;

// Class Shape
class Shape {
	private:
		int sides = 0;
		bool isCircle = false;
	public:
		Shape(bool issCircle) { // Shape Constructor
			isCircle = issCircle;
			sides = 0;
		}
		Shape(int ssides, bool issCircle) { // Shape Constructor
			sides = ssides;
			isCircle = issCircle;
		}
		int getSides() { // getter
			return sides;
		}
		~Shape() { }
};

// Class Polygon
class Polygon : public Shape { // inherit Shape class
	public:
		Polygon(): Shape(false) { } // Polygon Constructor
		Polygon(int sides): Shape(sides, false) { } // Polygon Constructor
		int sumOfAngles() { // method to get sum of angles
			if(getSides() <= 0) {
				return 0;
			}
			return (getSides()-2)*180;
		}
		~Polygon() { }
};

// Class Triangle
class Triangle : public Polygon { // inherit Polygon class
	private:
		int height = 0;
		int base = 0;
	public:
		Triangle(): Polygon(3) { } // Triangle Constructor
		Triangle(int h, int b): Polygon(3) { // Triangle Constructor
			height = h;
			base = b;
		}
		double getArea() { // method to get area
			return 0.5*base*height;
		}
		int getHeight() { // getter
			return height;
		}
		int getBase() { // getter
			return base;
		}
		~Triangle() { }
};

int main() {
	// Test shape class
	Shape aCircle = Shape(true);
	Shape aOctagon = Shape(8, false);
	cout << "A Circle has " << aCircle.getSides() << " sides" << endl;
	cout << "A Octagon has " << aOctagon.getSides() << " sides" << endl;
	
	// Test polygon class
	Polygon bNotCircle = Polygon();
	Polygon bPentagon = Polygon(5);
	cout << "A Non-circle has " << bNotCircle.getSides() << " sides and a angle sum of " << bNotCircle.sumOfAngles() << " degrees" << endl;
	cout << "A Pentagon has " << bPentagon.getSides() << " sides and a angle sum of " << bPentagon.sumOfAngles() << " degrees" << endl;
	
	// Test triangle class
	Triangle cTriangle1 = Triangle();
	Triangle cTriangle2 = Triangle(9, 6);
	cout << "Triangle1 has a area of " << cTriangle1.getArea() << endl; 
	cout << "Triangle2 has a area of " << cTriangle2.getArea() << endl;
	
	return 0;
}
