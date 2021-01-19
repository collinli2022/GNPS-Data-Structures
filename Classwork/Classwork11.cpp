// Collin Li
// Data Structures
// 10/29/2020
// Classwork 11

/*
Create the special quadrilaterals as a
sequence of Base and Derived
classes, being sure to solve any
multiple inheritance issues.
*/

// Preprocessor directive
#include <iostream>
#include <string>
using namespace std;

class Quadrilateral {
	public:
		Quadrilateral() { // Default Constructor
			cout << "I am a Quadrilateral" << endl;
		}
		~Quadrilateral() { } // Destructor
};
class Kite: public virtual Quadrilateral { // Inheritance 
	public:
		Kite() { // Default Constructor
			cout << "I am a Kite" << endl;
		}
		~Kite() { } // Destructor
};
class Trapezoid: public virtual Quadrilateral { // Inheritance 
	public:
		Trapezoid() { // Default Constructor
			cout << "I am a Trapezoid" << endl;
		}
		~Trapezoid() { } // Destructor
};
class Parallelogram: public virtual Trapezoid { // Inheritance 
	public:
		Parallelogram() { // Default Constructor
			cout << "I am a Parallelogram" << endl;
		}
		~Parallelogram() { } // Destructor
};
class IsoscelesTrapezoid: public virtual Trapezoid { // Inheritance 
	public:
		IsoscelesTrapezoid() { // Default Constructor
			cout << "I am an Isosceles Trapezoid" << endl;
		}
		~IsoscelesTrapezoid() {	} // Destructor
};
class Rhombus: public virtual Kite, public virtual Parallelogram { // Inheritance 
	public:
		Rhombus() { // Default Constructor
			cout << "I am a Rhombus" << endl;
		}
		~Rhombus() { } // Destructor
};
class Rectangle: public virtual IsoscelesTrapezoid, public virtual Parallelogram { // Inheritance 
	public:
		Rectangle() { // Default Constructor
			cout << "I am a Rectangle" << endl;
		}
		~Rectangle() { } // Destructor
};
class Square final: public virtual Rectangle, public virtual Rhombus { // Inheritance 
	public:
		Square() { // Default Constructor
			cout << "I am a Square" << endl;
		}
		~Square() {	} // Destructor
};
int main() {
	cout << "1" << endl;
	Quadrilateral a = Quadrilateral(); // Object created
	cout << endl << "2" << endl;
	Kite b = Kite(); // Object created
	cout << endl << "3" << endl;
	Trapezoid c = Trapezoid(); // Object created
	cout << endl << "4" << endl;
	Parallelogram d = Parallelogram(); // Object created
	cout << endl << "5" << endl;
	IsoscelesTrapezoid e = IsoscelesTrapezoid(); // Object created
	cout << endl << "6" << endl;
	Rhombus f = Rhombus(); // Object created
	cout << endl << "7" << endl;
	Rectangle g = Rectangle(); // Object created
	cout << endl << "8" << endl;
	Square h = Square(); // Object created
	return 0;
}
