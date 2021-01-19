// Collin Li
// Data Structures
// 10/22/2020    
// MiniProject Shapes    

// Preprocessor directive
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Output {
	public:
		Output() { } // default constructor
		void print() { cout << "Nothing here" << endl; }
		~Output() { }
};
/*
Create a class called Polygon inside of your program. Your class must contain protected attributes for the
length and width for a given Polygon object. You must also create a constructor to set the length and width
for your object. Your class must also contain the following methods, as well as any relevant accessor and
mutator methods.
*/
class Polygon : public Output {
	protected:
		int length = 0, width = 0, sides = 0;
	public:
		Polygon() {	} // default constructor
		Polygon(int s) { sides=s; } // constructor to set (number of) sides
		Polygon(int a, int b) { setValues(a, b); } // constructor to set length and width
		Polygon(int a, int b, int c) { // constructor to set length and width and (number of) sides
			setValues(a, b);
			sides = c;
		}
		// This method sets both the length and width for the Polygon
		void setValues(int a, int b) {
			length = a;
			width = b;
		}
		// Setters
		void setLength(int l) {	length=l; }
		void setWidth(int w) { width=w; }
		void setSides(int s) { sides=s; }
		// Getters
		int getLength() { return length; }
		int getWidth() { return width; }
		int getSides() { return sides; }
		void print() { // overriding method
			cout << "This polygon has a length of " << length << ", a width of " << width << ", and has " << sides << " sides." << endl;
		}
		~Polygon() { }
};
/*
You must also create at least two other derived classes that deal with specific types of Polygons, such as
Rectangle or Triangle.
*/
class Rectangle : public Output, public Polygon {
	public:
		Rectangle(): Polygon(4) { } // default constructor
		Rectangle(int a, int b): Polygon(a, b, 4) { } // constructor that sets length and width
		float area() { return getLength()*getWidth(); } // return area of rectangle
		void print() { // overriding method
			cout << "This rectangle has a length of " << getLength() << ", a width of " << getWidth() << ", has " << getSides() << " sides, and a area of " << area() << "." << endl;
		}
		~Rectangle() { }
};
class Triangle : public Output, public Polygon {
	public:
		Triangle(): Polygon(3) { } // default constructor
		Triangle(int a, int b): Polygon(a, b, 3) { } // constructor that sets length and width
		float area() { // return area of triangle
			return 0.5*getLength()*getWidth();
		}
		void print() { // overriding method
			cout << "This triangle has a length of " << getLength() << ", a width of " << getWidth() << ", has " << getSides() << " sides, and a area of " << area() << "." << endl;
		}
		~Triangle() { }
};
/*
In your main function, display a menu to ask the user for their desired task. They are to first choose their
operation and then enter the values required. Their options are listed below. When the process is complete, ask
the user if they want to do it again.
*/
int main() {
	int again = 0;
	do {
		// Ask for desired task
		cout << "Choose operation:" << endl;
		cout << "\t1. Polygon" << endl;
		cout << "\t2. Rectangle" << endl;
		cout << "\t3. Triangle" << endl;
		
		int choice = -1;
		cin >> choice;
		
		if(choice == 1) { // Polygon
			int length = 0, width = 0, sides = 0;
			// get length
			cout << "What is the length of the polygon: ";
			cin >> length;
			// get width
			cout << "What is the width of the polygon: ";
			cin >> width;
			// get number of sides
			cout << "How many sides does the polygon have: ";
			cin >> sides;
			
			Polygon temp = Polygon(length, width, sides);
			temp = Polygon();
			temp.setValues(length, width);
			temp.setLength(length);
			temp.setWidth(width);
			temp.setSides(sides);	
			temp.print();
		} else if (choice == 2) { // Rectangle
			int length = 0, width = 0;
			// get length
			cout << "What is the length of the rectangle: ";
			cin >> length;
			// get width
			cout << "What is the width of the rectangle: ";
			cin >> width;
			
			Rectangle temp = Rectangle(length, width);
			temp = Rectangle();
			temp.setValues(length, width);
			temp.setLength(length);
			temp.setWidth(width);
			temp.print();
		} else if (choice == 3) { // Triangle
			int length = 0, width = 0;
			// get length
			cout << "What is the length of the triangle: ";
			cin >> length;
			// get width
			cout << "What is the width of the triangle: ";
			cin >> width;
			
			Triangle temp = Triangle(length, width);
			temp = Triangle();
			temp.setValues(length, width);
			temp.setLength(length);
			temp.setWidth(width);
			temp.print();
		} else {
			cout << "That's not a valid choice :(" << endl;
		}
		cout << "Again? (1-yes, 0-no): "; // Ask if user if they want to do it again
		cin >> again;
	} while(again == 1);
	
	return 0;
}
