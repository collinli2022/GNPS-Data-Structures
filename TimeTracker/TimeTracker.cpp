// Collin Li
// Data Structures
// 10/13/2020
// MiniProject TimeTracker  

// Preprocessor directive
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/*
Create a class called Time inside of your program. Your class must contain private attributes for the hours,
minutes, and seconds for a given Time object. You must also create constructors that take seconds only and
take hours, minutes, and seconds to create your objects. Your class must also contain the following methods, as
well as any relevant accessor and mutator methods.
*/
class Time {
	private:
		int hours = 0, minutes = 0, seconds = 0; // store the hours, minutes, seconds
		int sign = 1; // positive number means positive, negative number means negative
		void setSec(int s) { // helper method - converts/sets seconds to HH:MM:SS format
			int totalSec = s;
			// *simplify* time into HH:MM:SS format
			int extraMin = totalSec / 60;
			hours = extraMin / 60;
			extraMin %= 60;
			minutes = extraMin;
			seconds = totalSec % 60;
			format();
		}		
		void format() { // used to make sure hours, minutes, and seconds are positive
			hours = abs(hours);
			minutes = abs(minutes);
			seconds = abs(seconds);
		}
	public:
		// Constructors
		Time(int s) {
			if(s < 0) { // According to Mrs.Zinn, just add the negative sign in front
				sign *= -1;
				s=abs(s);
			}
			setSec(s); // reformat to HH:MM:SS
			format();
		}
		Time(int h, int m, int s) {
			if(h < 0 || m < 0 || s < 0) { // According to Mrs.Zinn, just add the negative sign in front
				sign *= -1;
				h=abs(h);
				m=abs(m);
				s=abs(s);
			}
			setSec(totalSeconds(h, m, s)); // convert to seconds and then reformat back to HH:MM:SS
			format();
			
		}
		// This method adds two Time objects and returns a new object.
		Time add(Time other) {
			int secondsCombined = totalSeconds() + other.totalSeconds();
			Time temp(secondsCombined);
			return temp;
		}
		// This method subtracts two Time objects and returns a new object.
		Time subtract(Time other) {
			int secondsCombined = totalSeconds() - other.totalSeconds();
			Time temp(secondsCombined);
			return temp;
		}
		// This method increases the Time object by the given arguments and returns a new object.
		Time increaseBy(int h, int m, int s) {
			Time temp(h, m, s); // much more organized
			temp = add(temp); // we are calling the add method of *this* class
			// replace this object's hour, mintues, time
			hours = temp.getHours();
			minutes = temp.getMinutes();
			seconds = temp.getSeconds();
			sign = temp.getSign();
			return temp;
		}
		// This method increases the Time object by the given argument and returns a new object.
		Time increaseBy(int s) {
			Time temp(s); // much more organized
			temp = add(temp); // we are calling the add method of *this* class
			// replace this object's hour, mintues, time
			hours = temp.getHours();
			minutes = temp.getMinutes();
			seconds = temp.getSeconds();
			sign = temp.getSign();
			return temp;
		}
		
		int totalSeconds() { // helper method - returns total seconds
			int totalSeconds = 0;
			totalSeconds += abs(hours * 60 * 60);
			totalSeconds += abs(minutes * 60);
			totalSeconds += abs(seconds);
			totalSeconds *= sign;
			return totalSeconds;
		}
		
		int totalSeconds(int h, int m, int s) { // helper method - returns total seconds
			int totalSeconds = 0;
			totalSeconds += abs(h * 60 * 60);
			totalSeconds += abs(m * 60);
			totalSeconds += abs(s);
			totalSeconds *= sign;
			return totalSeconds;
		}
		
		// Getters
		int getHours() { return hours; }
		int getMinutes() { return minutes; }		
		int getSeconds() { return seconds; }
		int getSign() { return sign; }
		void print() { // helper method - prints out the time
			if(sign < 0) { // According to Mrs.Zinn, just add the negative sign in front
				printf("-%02d:%02d:%02d\n", abs(hours), abs(minutes), abs(seconds));
			} else {
				printf("%02d:%02d:%02d\n", abs(hours), abs(minutes), abs(seconds));
			}
		}
		void debug() { // debugging purposes
			printf("DEBUG: %02d:%02d:%02d\n", hours, minutes, seconds);
		}
		// Destructer
		~Time() {}
};



/*
In your main function, display a menu to ask the user for their desired task. They are to first choose their
operation and then enter the values required. Their options are listed below. When the process is complete, ask
the user if they want to do it again. When displaying a Time object, you must display it in proper HH:MM:SS
form, using exactly 2 digits for the minutes and seconds and at least 2 for the hours (in other words, 01 instead
of 1). The value for MM and SS can be no larger than 59. In addition, the values must be separated by a single
colon.
*/
int main() {
	bool again = false; // to tell if the user wants to do it again
	Time time(0, 0, 0);
	do {
		cout << "Choose your option by entering the corresponding number:" << endl;
		cout << "\t0. set time (if this step is skipped then the time will be set to 00:00:00)" << endl;
		cout << "\t1. add" << endl;
		cout << "\t2. subtract"	<< endl;
		cout << "\t3. increaseBy (hr, min, sec)" << endl;
		cout << "\t4. increaseBy (sec)" << endl;
		cout << "\t5. show time" << endl;
		int choice = -1;
		cin >> choice; // get choice
		if(choice == 0) { // set time
			int internalChoice = -1;
			int h = 0, m = 0, s = 0;
			cout << "would you just like to set seconds? (1-yes, 0-no)" << endl;
			cin >> internalChoice;
			if(internalChoice == 1) { // only set time with seconds
					cout << "Enter the number of seconds" << endl;
					cin >> s;
					time = Time(s);
					cout << "The time is now set: "; // print out the time
					time.print();
			} else { // set time with hours, minutes, seconds
				cout << "Enter the number of hours, then minutes, then seconds (seperated by spaces)" << endl;
				cin >> h;
				cin >> m;
				cin >> s;
				time = Time(h, m, s);
				cout << "The time is now set: "; // print out the time
				time.print();
			}
		} else if(choice == 1) { // add
			int h = 0, m = 0, s = 0;
			cout << "Enter the number of hours, then minutes, then seconds (seperated by spaces) for add" << endl;
			cin >> h;
			cin >> m;
			cin >> s;
			Time temp(h, m, s);
			cout << "The time you entered is: ";
			temp.print();
			cout << "The original time is: ";
			time.print();
			cout << "The outputed time is: ";
			time.add(temp).print(); // call add method and print time out
		} else if(choice == 2) { // subtract
			int h = 0, m = 0, s = 0;
			cout << "Enter the number of hours, then minutes, then seconds (seperated by spaces) for subtract" << endl;
			cin >> h;
			cin >> m;
			cin >> s;
			Time temp(h, m, s);
			cout << "The time you entered is: ";
			temp.print();
			cout << "The original time is: ";
			time.print();
			cout << "The outputed time is: ";
			time.subtract(temp).print(); // call subtract method and print time out
		} else if(choice == 3) { // increase by
			int h = 0, m = 0, s = 0;
			cout << "Enter the number of hours, then minutes, then seconds (seperated by spaces) to increase by" << endl;
			cin >> h;
			cin >> m;
			cin >> s;
			cout << "The time you entered is: ";
			Time temp(h, m, s);
			temp.print();
			cout << "The original time is: ";
			time.print();
			cout << "The outputed time is: ";
			time.increaseBy(h, m, s).print(); // call increaseBy method and print time out
		} else if(choice == 4) { // increase by (seconds only)
			cout << "Enter the number of seconds (seperated by spaces) to increase by" << endl;
			int s = 0;
			cin >> s;
			cout << "The time you entered is: ";
			Time temp(s);
			temp.print();
			cout << "The original time is: ";
			time.print();
			cout << "The outputed time is: ";
			time.increaseBy(s).print(); // call increaseBy method and print time out
		} else if(choice == 5) { // display time
				cout << "The time is: ";
				time.print(); // print out the time
		} else {
			cout << "Your choice is invalid" << endl;
		}
		cout << endl << "Would you like to continue (1-yes, 0-no): ";
		cin >> again;
	} while(again);
	return 0;
}
