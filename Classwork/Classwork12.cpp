// Collin Li
// Data Structures H
// 11/5/2020
// Classwork 12    
/*
Modify the Date class so that it
updates properly. Program a
conversion operator for the Date
class so that it converts the date it
holds into a unique integer.
*/

// also contains postfix increment and decrement
#include <iostream>
using namespace std;
#include <sstream> // new include for ostringstream
class Date {
	private:
		int day, month, year;
		int dayInMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // HAS AN EXTRA VALUE --> stores the days in a month starting from index 1-Jan to index 12-Dec 
		void addDay() { // adds a day
			++day;
			if(day > dayInMonth[month]) { // check if new month
				day = 1;
				month++; 
				if(month > 12) { // check if new year
					month = 1;
					year++;
				}
			}
		}
		void subtractDay() { // subtracts a day
			--day;
			if(day < 1) { // check if going back a month
				month--; // check if going back a year
				if(month < 1) {
				year--;
				month = 12;
				}
				day = dayInMonth[month];
			}
		}
		int monthsToDays(int m) { // returns the number of days based on month in (not including that month)
			int total = 0;
			for(int i = 1; i < m; i++) { // does not include the current month
				total += dayInMonth[i];
			}
			return total;
		}
	public:
 		Date (int inMonth, int inDay, int inYear): month (inMonth), day(inDay), year (inYear) { };
		Date& operator ++ () { // prefix increment
			addDay();
			return *this;
		}
		Date& operator -- () {// prefix decrement
			subtractDay();			
			return *this;
		}
		Date operator ++ (int) { // postfix increment
			Date copy(month, day, year);
			addDay();
			return copy;
		}
		Date operator -- (int) { // postfix decrement
			Date copy(month, day, year);
		 	subtractDay();
		 	return copy;
		}
		Date operator + (int daysToAdd) { // binary addition
			Date copy(month, day, year);
			copy += daysToAdd;
			return copy;
		}
		Date operator - (int daysToSub) { // binary subtraction
			Date copy(month, day, year);
			copy -= daysToSub;
			return copy;
		}
		void operator += (int daysToAdd) { // addition assignment
			if(daysToAdd < 0) { (*this)-=(daysToAdd*-1); }
			for(int i = 0; i < daysToAdd; i++) { addDay(); }
		}
		void operator -= (int daysToSub) { // subtraction assignment
			if(daysToSub < 0) { (*this)+=(daysToSub*-1); }
			for(int i = 0; i < daysToSub; i++) { subtractDay(); }
		}
		void DisplayDate() { cout << month << " / " << day << " / " << year << endl; } // displays the date
		operator const int () { return year*365 + monthsToDays(month) + day; } // converts the date to total amount of days & returns the nth day (including the current day)
		/*
		bool operator == (const Date& compareTo) { return ((day == compareTo.day) && (month == compareTo.month) && (year == compareTo.year)); }
		bool operator != (const Date& compareTo) { return !(this->operator==(compareTo)); }
		bool operator < (const Date& compareTo) {
			if (year < compareTo.year) { return true; }
			else if ((year == compareTo.year) && (month < compareTo.month)) { return true; }
			else if ((year == compareTo.year) && (month == compareTo.month) && (day < compareTo.day)) { return true; }
			else { return false; }
				
		}
		bool operator <= (const Date& compareTo) {
			if (this->operator == (compareTo)) { return true; }
			else { return this->operator < (compareTo); }
		}
		bool operator > (const Date& compareTo) { return !(this->operator <= (compareTo)); }
		bool operator >= (const Date& compareTo) {
			if(this->operator == (compareTo))
				return true;
			else
				return this->operator > (compareTo);
		}
		*/
};

int main () { // testing code
	Date holiday (12, 25, 2016); // Dec 25, 2016
	
	cout << "The date object is initialized to: ";
	holiday.DisplayDate ();
	
	++holiday; // move date ahead by a day
	cout << "Date after prefix-increment is: ";
	holiday.DisplayDate ();
	
	--holiday; // move date backwards by a day
	cout << "Date after a prefix-decrement is: ";
	holiday.DisplayDate ();

	/*
	Date d1= Date(12,31,2020);
	d1+=-512;
	d1.DisplayDate();
	d1++;
	d1.DisplayDate();
	Date d2= d1;
	d2.DisplayDate();
	d2=d2+1000;
	d2.DisplayDate();
	
	
	
	Date d3= Date(11,1,2020);
	d3.DisplayDate();
	d3--;
	d3.DisplayDate();
	++d3;
	d3.DisplayDate();
	--d3;
	d3.DisplayDate();
	d3=d3-1000;
	d3.DisplayDate();
	d3+=20;
	d3.DisplayDate();
	d3-=20;
	d3.DisplayDate();
	cout<<d3<<endl;
	
	cout << endl << endl;
	
	
	d1 = Date(12,31,0);
	d1.DisplayDate();
	d1++;
	d1.DisplayDate();
	
	Date hh (1, 5, 1);
	hh++;
	hh.DisplayDate ();
	++hh;
	hh.DisplayDate ();
	hh--;
	hh.DisplayDate ();
	--hh;
	hh.DisplayDate ();
	hh += -10;
	hh.DisplayDate ();
	hh +=20;
	hh.DisplayDate ();
	Date hh2 (1, 5, 1);
	cout << (hh==hh2) << endl;
	cout << (hh!=hh2) << endl;
	hh2 += 10;
	cout << (hh==hh2) << endl;
	*/
	return 0;
}
