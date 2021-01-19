// Collin Li
// Data Structures
// 11/23/2020 
// Duration   

// Preprocessor directive
#include <iostream>
#include <string>
#include <cmath>
#include <sstream> // include for ostringstream
#include <sstream>
#include <iomanip>
#include <stdlib.h>
#include <ctime>
using namespace std;

class Duration {
	private:
		int hours, minutes, seconds; // private attributes for hr, min, sec
		// helper methods
		void format(double h, double m, double s) { // formats the hrs, mins, secs
			seconds = h * 3600 + m * 60 + s; // will represent total seconds (for now)
			seconds = (int) seconds; // truncate
			if(seconds >= 0) {
				int extra = seconds / 3600; // see how many hours
				hours = extra;
				seconds -= extra*3600; // subtract the hours
				extra = seconds / 60;
				minutes = extra;
				seconds -= extra*60; // subtract the minutes
			} else { // if negative time, then set time to 00:00:00
				hours = 0;
				minutes = 0;
				seconds = 0;
			}
		}
		int toSeconds() { // gets total amount of seconds
			int total = 0;
			total += seconds;
			total += minutes * 60;
			total += hours * 3600;
			return total;
		}
	public:
		// If no values or less than 3 values are passed in, the default of 0 must be set.
		Duration(double h = 0, double m = 0, double s = 0) {
			format(h, m, s);
		}
		// getters and setters
		int getHours() {return hours;}
		int getMinutes() {return minutes;}
		int getSeconds() {return seconds;}
		void setHours(int h) {hours = h;}
		void setMinutes(int m) {minutes = m;}
		void setSeconds(int s) {seconds = s;}
		/* // Adding two Duration objects together returns a Duration representing the sum. */
		Duration operator + (Duration other) {
			Duration copy(hours+other.getHours(), minutes+other.getMinutes(), seconds+other.getSeconds());
			return copy;
		}
		/*
		Subtracting two Duration objects returns a Duration representing the difference. If the difference is
		negative, the result should be 00:00:00.
		*/
		Duration operator - (Duration other) { // subtraction
			Duration copy(hours-other.getHours(), minutes-other.getMinutes(), seconds-other.getSeconds());
			return copy;
		}
		/* Multiplying a Duration by a constant returns a Duration representing the product. */
		Duration operator * (double constant) { // multipliction 
			Duration copy(hours*constant, minutes*constant, seconds*constant);
			return copy;
		}
		/*
		Dividing a Duration by a constant returns a Duration representing the quotient, rounded down to the
		nearest second.
		*/
		Duration operator / (double constant) { // division
			Duration copy(hours/constant, minutes/constant, seconds/constant);
			return copy;
		}
		/* Dividing a Duration by another returns a double representing the ratio of the first Duration to the second. */
		double operator / (Duration other) { // division
			return (double)toSeconds()/(double)other.toSeconds();
		}
		/* Printing a Duration operator using cout &lt;&lt; should display in proper HH:MM:SS form. */
		operator const char*() {
			ostringstream formattedNum; // assists easy string construction
			format(hours, minutes, seconds); // makes sure values are formatted and mins/secs are not larger than 59
			// makes sure that there are always 2 digits (for the hrs, mins, secs)
			formattedNum << setw(2) << setfill('0') << abs((int)hours) << ":";
			formattedNum << setw(2) << setfill('0') << abs((int)minutes) << ":";
			formattedNum << setw(2) << setfill('0') << abs((int)seconds);
			
			string temp = formattedNum.str();
			return temp.c_str();
		}
		void randomize() {
			srand( time( NULL ) );
			hours = rand() % 24;
			minutes = rand() % 60;
			seconds = rand() % 60;
		}
};

// helper function (Mrs Zinn allowed user-input as long as there is no user-input in the methods in the class)
Duration getComplexNumber() {
	cout << "Choose your input mode: " << endl; // ask for input method
	cout << "\t1. Just Hours" << endl;
	cout << "\t2. Hours, Minutes" << endl;
	cout << "\t3. Hours, Minutes, Seconds" << endl;
	Duration copy;
	int choice;
	cin >> choice;
	double h, m, s;
	if(choice == 1) { // just hours
		cout << "\tHours: ";
		cin >> h;
		copy = Duration(h);
	} else if (choice == 2) { // hours, minutes
		cout << "\tHours: ";
		cin >> h;
		cout << "\tMinutes: ";
		cin >> m;
		copy = Duration(h, m);
	} else if (choice == 3) { // hours minutes seconds
		cout << "\tHours: ";
		cin >> h;
		cout << "\tMinutes: ";
		cin >> m;
		cout << "\tSeconds: ";
		cin >> s;
		copy = Duration(h, m, s);
	} else {
		cout << "Invalid choice, do again" << endl;
		return getComplexNumber(); // recursion to do again
	}
	
	
	return copy;
}

/*
In your main function, display a menu to ask the user for their desired task. They are to first choose their
operation and then enter the values required. Their options are listed below. When the process is complete, ask
the user if they want to do it again. When displaying a Duration object, you must display it in proper
HH:MM:SS form, using exactly 2 digits for the minutes and seconds and at least 2 for the hours (in other words,
01 instead of 1). The value for MM and SS can be no larger than 59. In addition, the values must be separated
by a single colon.
*/
int main() {
	int again = 0;
	do {
		// ask the user for their desired task
		cout << "Choose your task:" << endl;
		cout << "\t1. Addition" << endl;
		cout << "\t2. Subtraction" << endl;
		cout << "\t3. Multiplication (by constant)" << endl;
		cout << "\t4. Division (by constant)" << endl;
		cout << "\t5. Division (by anther Duration object)" << endl;
		cout << "\t6. Randomize" << endl;
		int input = -1; // first choose their operation... and then enter the values required
		cin >> input;
		Duration num1 = Duration();
		Duration num2 = Duration();
		
		if(input == 1) {
			// ask for values
			cout << "Follow the directions to enter values for 2 Duration objects" << endl;
			cout << "Duration1:" << endl;
			num1 = getComplexNumber();
			cout << "Duraction2:" << endl;
			num2 = getComplexNumber();
			// display operation and output
			cout << num1 << " + ";
			cout << num2 << " = ";
			cout << num1+num2 << endl;
		} else if(input == 2) {
			// ask for values
			cout << "Follow the directions to enter values for 2 Duration objects" << endl;
			cout << "Duration1:" << endl;
			num1 = getComplexNumber();
			cout << "Duraction2:" << endl;
			num2 = getComplexNumber();
			// display operation and output
			cout << num1 << " - ";
			cout << num2 << " = ";
			cout << num1-num2 << endl;
		} else if(input == 3) {
			// ask for values
			cout << "Follow the directions to enter values for 1 Duration object" << endl;
			cout << "Duration1:" << endl;
			num1 = getComplexNumber();
			cout << "Now enter the constant you are multiplying the Duration object with: ";
			double temp;
			cin >> temp;
			// display operation and output
			cout << num1 << " * " << temp << " = ";
			cout << num1*temp << endl;
		} else if(input == 4) {
			// ask for values
			cout << "Follow the directions to enter values for 2 Duration objects" << endl;
			cout << "Duration1:" << endl;
			num1 = getComplexNumber();
			cout << "Now enter the constant you are dividing the Duration object with: ";
			double temp;
			cin >> temp;
			// display operation and output
			cout << num1 << " / " << temp << " = ";
			cout << num1/temp << endl;
		} else if(input == 5) {
			// ask for values
			cout << "Follow the directions to enter values for 2 Duration objects" << endl;
			cout << "Duration1:" << endl;
			num1 = getComplexNumber();
			cout << "Duraction2:" << endl;
			num2 = getComplexNumber();
			// display operation and output
			cout << num1 << " / ";
			cout << num2 << " = ";
			cout << num1/num2 << endl;
		} else if(input == 6) {
			num1.randomize();
			cout << "Your random duration (less than a day) is: " << num1 << endl;
		} else {
			cout << "Invalid choice ;(" << endl;
		}
		cout << "Again? (yes-1, no-0)" << endl;
		cin >> again;
	} while(again==1);
	return 0;
}
