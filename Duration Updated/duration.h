// Collin Li
// Data Structures
// 12/7/2020 
// Duration Header File

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

// header guards
#ifndef DURATION_H
#define DURATION_H

class Duration {
	private:
		int hours, minutes, seconds; // private attributes for hr, min, sec
		// helper methods
		void format(double h, double m, double s);
		int toSeconds();
	public:
	    Duration(double h, double m, double s);
	    int getHours();
        int getMinutes();
        int getSeconds();
        void setHours(int h);
        void setMinutes(int m);
        void setSeconds(int s);
        Duration operator + (Duration other);
        Duration operator - (Duration other);
        Duration operator * (double constant);
        Duration operator / (double constant);
        double operator / (Duration other);
        void randomize();
        operator const char*();
		~Duration() { } // Destructor
};

void Duration::format(double h, double m, double s) { // formats the hrs, mins, secs
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
int Duration::toSeconds() { // gets total amount of seconds
			int total = 0;
			total += seconds;
			total += minutes * 60;
			total += hours * 3600;
			return total;
		}

// If no values or less than 3 values are passed in, the default of 0 must be set.
Duration::Duration(double h = 0, double m = 0, double s = 0) {
	format(h, m, s);
}
// getters and setters (setters not really needed)
int Duration::getHours() {return hours;}
int Duration::getMinutes() {return minutes;}
int Duration::getSeconds() {return seconds;}
void Duration::setHours(int h) {hours = h;}
void Duration::setMinutes(int m) {minutes = m;}
void Duration::setSeconds(int s) {seconds = s;}
/* // Adding two Duration objects together returns a Duration representing the sum. */
Duration Duration::operator + (Duration other) {
	Duration copy(hours+other.getHours(), minutes+other.getMinutes(), seconds+other.getSeconds());
	return copy;
}
/*
Subtracting two Duration objects returns a Duration representing the difference. If the difference is
negative, the result should be 00:00:00.
*/
Duration Duration::operator - (Duration other) { // subtraction
	Duration copy(hours-other.getHours(), minutes-other.getMinutes(), seconds-other.getSeconds());
	return copy;
}
/* Multiplying a Duration by a constant returns a Duration representing the product. */
Duration Duration::operator * (double constant) { // multipliction 
	Duration copy(hours*constant, minutes*constant, seconds*constant);
	return copy;
}
/*
Dividing a Duration by a constant returns a Duration representing the quotient, rounded down to the
nearest second.
*/
Duration Duration::operator / (double constant) { // division
	Duration copy(hours/constant, minutes/constant, seconds/constant);
	return copy;
}
/* Dividing a Duration by another returns a double representing the ratio of the first Duration to the second. */
double Duration::operator / (Duration other) { // division
	return (double)toSeconds()/(double)other.toSeconds();
}
/* Printing a Duration operator using cout &lt;&lt; should display in proper HH:MM:SS form. */
Duration::operator const char* () {
	ostringstream formattedNum; // assists easy string construction
	format(hours, minutes, seconds); // makes sure values are formatted and mins/secs are not larger than 59
	// makes sure that there are always 2 digits (for the hrs, mins, secs)
	formattedNum << setw(2) << setfill('0') << abs((int)hours) << ":";
	formattedNum << setw(2) << setfill('0') << abs((int)minutes) << ":";
	formattedNum << setw(2) << setfill('0') << abs((int)seconds);
	string temp = formattedNum.str();
	return temp.c_str();
}
void Duration::randomize() {
	hours = rand() % 24;
	minutes = rand() % 60;
	seconds = rand() % 60;
}

#endif
