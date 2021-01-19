// Collin Li
// Data Structures
// 11/9/2020
// Complex Numbers           

// Preprocessor directive
#include <iostream>
#include <string>
#include <cmath>
#include <sstream> // new include for ostringstream
#include <math.h> // atan
using namespace std;

/*
Create a class called Complex inside of your program.
Your class must contain private attributes for the a and b values for a given Complex object.
You must also create a constructor to set the values for your object.
*/
class Complex {
	private:
		double a;
		double b;
	public:
		Complex() { }
		Complex(double aa, double bb) {
			a = aa;
			b = bb;
		}
		
		Complex conjugate() { // This method returns the complex conjugate for the Complex.
			Complex copy(a, -1*b);
			return copy;
		}
		double norm() { // This method returns the norm of the Complex.
			return sqrt(pow(a, 2)+pow(b, 2));
		}
		double real() { // This method returns the real part of the Complex.
			return a;
		}
		double imag() { // This method returns the imaginary part of the Complex.
			return b;
		}
		double dotProduct(Complex other) { // This method returns the dot product of the Complex and the parameter.
			return a * other.real() + b * other.imag();
		}
		Complex scalarProduct(double value) { // This method returns the scalar product of the Complex and the parameter.
			Complex copy(a*value, b*value);
			return copy;
		}
		double angleBetween(Complex other) { // This method returns the angle between the Complex and the parameter (in degrees) going COUNTERCLOCKWISE ONLY starting from THIS Complex number
			double angle1 = atan2 (b,a) * 180 / M_PI, angle2 = atan2 (other.b,other.a) * 180 / M_PI; // trig!
			while(angle1 < 0) {	angle1 += 360; } // get angle between 0-360
			while(angle1 >= 360) { angle1 -= 360; }
			while(angle2 < 0) { angle2 += 360; }
			while(angle2 >= 360) { angle2 -= 360; }
			double answer = angle2 - angle1; // this is calculating the COUNTERCLOCKWISE angle starting from THIS Complex number
			while(answer < 0) { answer += 360; }
			while(answer >= 360) { answer -= 360; }
			return answer;
		}
		Complex operator + (Complex other) { // addition
			Complex copy(a+other.real(), b+other.imag()); // add
			return copy;
		}
		Complex operator - (Complex other) { // subtraction
			Complex copy(a-other.real(), b-other.imag()); // just stubtract
			return copy;
		}
		Complex operator * (Complex other) { // multipliction 
			Complex copy((a * other.real()) - (b * other.imag()), (a * other.imag()) + (b * other.real())); // distribute!
			return copy;
		}
		Complex operator / (Complex other) { // division assignment
			double real = ( (a*other.real())+(b*other.imag()) ) / (pow(other.real(),2)+pow(other.imag(),2)); // math!
			double imag = ( (other.real()*b)-(a*(other.imag())) ) / ( pow(other.real(),2)+pow(other.imag(),2) );
			Complex copy(real, imag);
			return copy;
		}
		bool operator == (Complex other) {
			return a == other.real() && b == other.imag();
		}
		operator const char*() {
			ostringstream formattedNum; // assists easy string construction
			formattedNum << a << " + " << b << "i";
			string temp = formattedNum.str();
			return temp.c_str();
		}
		~Complex () { }
};

// helper function
Complex getComplexNumber() {
	double r1 = -1, c1 = -1;
	cout << "Real: ";
	cin >> r1;
	cout << "Complex: ";
	cin >> c1;
	Complex copy(r1, c1);
	return copy;
}

/*
In your main function, display a menu to ask the user for their desired task. They are to first choose their
operation and then enter the values required. Their options are listed below. When the process is complete, ask
the user if they want to do it again.
*/
int main() {
	int again = 0;
	do {
		// ask the user for their desired task
		cout << "Choose your task:" << endl;
		cout << "\t1. Conjugate" << endl;
		cout << "\t2. Norm" << endl;
		cout << "\t3. DotProduct" << endl;
		cout << "\t4. ScalarProduct" << endl;
		cout << "\t5. AngleBetween" << endl;
		cout << "\t6. Addition" << endl;
		cout << "\t7. Subtraction" << endl;
		cout << "\t8. Multiplication" << endl;
		cout << "\t9. Division" << endl;
		cout << "\t10. Equality (Compare)" << endl;
		int input = -1; // first choose their operation... and then enter the values required
		cin >> input;
		Complex num1 = Complex();
		Complex num2 = Complex();
		
		if(input == 1) {
			cout << "Enter 1 complex number" << endl;
			num1 = getComplexNumber();
			cout << "Conjugate of " << num1;
			cout << " is " << num1.conjugate() << endl;
		} else if(input == 2) {
			cout << "Enter 1 complex number" << endl;
			num1 = getComplexNumber();
			cout << "Norm of " << num1 << " is ";
			cout << num1.norm() << endl;
		} else if(input == 3) {
			cout << "Enter 2 complex numbers" << endl;
			num1 = getComplexNumber();
			num2 = getComplexNumber();
			cout << "DotProduct of " << num1 << " and ";
			cout << num2 << " is ";
			cout << (num1.dotProduct(num2)) << endl;
		} else if(input == 4) {
			cout << "Enter 1 complex number" << endl;
			num1 = getComplexNumber();
			cout << "Enter a value to multiply" << endl;
			double value = -1;
			cin >> value;
			cout << "Scalar Product of " << num1;
			cout << " and " << value << " is " << num1.scalarProduct(value) << endl;
		} else if(input == 5) {
			cout << "Enter 2 complex numbers" << endl;
			num1 = getComplexNumber();
			num2 = getComplexNumber();
			cout << "The angle between " << num1;
			cout << " and " << num2;
			cout << " is: " << num1.angleBetween(num2) << endl;
		} else if(input == 6) {
			cout << "Enter 2 complex numbers" << endl;
			num1 = getComplexNumber();
			num2 = getComplexNumber();
			cout << num1 << " + ";
			cout << num2;
			cout << " = " << (num1+num2) << endl;
		} else if(input == 7) {
			cout << "Enter 2 complex numbers" << endl;
			num1 = getComplexNumber();
			num2 = getComplexNumber();
			cout << "(" << num1 << ") - (";
			cout << num2 << ")";
			cout << " = " << (num1-num2) << endl;
		} else if(input == 8) {
			cout << "Enter 2 complex numbers" << endl;
			num1 = getComplexNumber();
			num2 = getComplexNumber();
			cout << "(" << num1 << ") * (";
			cout << num2 << ")";
			cout << " = " << (num1*num2) << endl;
		} else if(input == 9) {
			cout << "Enter 2 complex numbers" << endl;
			num1 = getComplexNumber();
			num2 = getComplexNumber();
			cout << "(" << num1 << ") / (";
			cout << num2 << ")"; 
			cout << " = " << (num1/num2) << endl;
		} else if(input == 10) {
			cout << "Enter 2 complex numbers" << endl;
			num1 = getComplexNumber();
			num2 = getComplexNumber();
			cout << "(" << num1 << ") == (";
			cout << num2 << ")";
			cout << " -- " << (num1 == num2) << endl;
		}
		cout << "Again? (yes-1, no-0)" << endl;
		cin >> again;
	} while(again==1);
	return 0;
}
