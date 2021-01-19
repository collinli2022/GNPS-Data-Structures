// Collin Li
// Data Structures
// 12/8/2020 
// ComplexNumber Header File  

// Preprocessor directive
#include <iostream>
#include <string>
#include <cmath>
#include <sstream> // new include for ostringstream
using namespace std;

// header guards
#ifndef COMPLEXNUMBERS_H
#define COMPLEXNUMBERS_H

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
		Complex() { } // Default constructor
		Complex(double aa, double bb);
		Complex conjugate();
		double norm();
		double real();
		double imag();
		double dotProduct(Complex other);
		Complex scalarProduct(double value);
		double angleBetween(Complex other);
		Complex operator + (Complex other);
		Complex operator - (Complex other);
		Complex operator * (Complex other);
		Complex operator / (Complex other);
		bool operator == (Complex other);
		operator const char*();
		~Complex () { } // Destructor
};

Complex::Complex(double aa, double bb) { // Constructor to set values
	a = aa;
	b = bb;
}
Complex Complex::conjugate() { // This method returns the complex conjugate for the Complex.
	Complex copy(a, -1*b);
	return copy;
}
double Complex::norm() { // This method returns the norm of the Complex.
	return sqrt(pow(a, 2)+pow(b, 2));
}
double Complex::real() { // This method returns the real part of the Complex.
	return a;
}
double Complex::imag() { // This method returns the imaginary part of the Complex.
	return b;
}
double Complex::dotProduct(Complex other) { // This method returns the dot product of the Complex and the parameter.
	return a * other.real() + b * other.imag();
}
Complex Complex::scalarProduct(double value) { // This method returns the scalar product of the Complex and the parameter.
	Complex copy(a*value, b*value);
	return copy;
}
double Complex::angleBetween(Complex other) { // This method returns the angle between the Complex and the parameter (in degrees) going COUNTERCLOCKWISE ONLY starting from THIS Complex number
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
Complex Complex::operator + (Complex other) { // addition
	Complex copy(a+other.real(), b+other.imag()); // add
	return copy;
}
Complex Complex::operator - (Complex other) { // subtraction
	Complex copy(a-other.real(), b-other.imag()); // just stubtract
	return copy;
}
Complex Complex::operator * (Complex other) { // multipliction 
	Complex copy((a * other.real()) - (b * other.imag()), (a * other.imag()) + (b * other.real())); // distribute!
	return copy;
}
Complex Complex::operator / (Complex other) { // division assignment
	double real = ( (a*other.real())+(b*other.imag()) ) / (pow(other.real(),2)+pow(other.imag(),2)); // math!
	double imag = ( (other.real()*b)-(a*(other.imag())) ) / ( pow(other.real(),2)+pow(other.imag(),2) );
	Complex copy(real, imag);
	return copy;
}
bool Complex::operator == (Complex other) {
	return (a-other.real()) + (b-other.imag()) < pow(0.1, 4);
}
Complex::operator const char*() {
	ostringstream formattedNum; // assists easy string construction
	formattedNum << a << " + " << b << "i";
	string temp = formattedNum.str();
	return temp.c_str();
}
#endif
