//Amaar Alwani 
//Classwork12.cpp
//Period 9 DSH
//Purpose of the program is to handle dates 
#include <iostream>
using namespace std;

class Date
{
    private:
       int day, month, year;
        int monthDay[12] = {31,28,31,30,31,30,31,31,30,31,30,31};//array that holds the number of days in each month
       
        int setDay(int d)//handles day to month wrap
        {
            if(d<=0)
            {
               while(d<=0)
               {
                   if(month>1)
                   {
                       d= d + monthDay[month-2];
                       setMonth(month-1);
                   }
                   else 
                   {
                       d= d + monthDay[11];
                       setMonth(month-1);  
                   }
               }
               day=d;
               return day;
               
            }
            else if(d>monthDay[month-1])
            {
                while(d>monthDay[month-1]) 
                {                
                    d=d-monthDay[month-1];
                    setMonth(month+1);
                }
                day=d;
               
                return day;
            }
            
            else 
            {
                day=d;
                return day;
            }
                  
               
        }
        
        
        int setMonth(int m)//handles month to year wrap
        {
            if(m>12)
            {
                while(m>12)
                {
                    m=m-12;
                    year++;
                }
                
            }
            
            else if(m<1)
            {
                while(m<1)
                {
                    m+=12;
                    year--;
                }

            }
  
            month=m;
            return month;
        }
        
        
    public:
       Date (int inMonth, int inDay, int inYear)
            : month (inMonth), day(inDay), year (inYear) {};
    
    //All the operators are virtually the same except that instead of modifying the variables directly they call the set methods which handles wrap
       Date& operator ++ () // prefix increment
       {
            setDay(day+1);
            return *this;
       }
    
       Date& operator -- () // prefix decrement
       {
          setDay(day-1);
          return *this;
       }
    
       Date operator ++ (int) // postfix increment
       {
          Date copy(month, day, year);
          setDay(day+1);
          return copy;
       }
    
       Date operator -- (int) // postfix decrement
       {
          Date copy(month, day, year);
          setDay(day-1);
          return copy;
       }
       
       Date operator + (int daysToAdd) // binary addition
       {
          Date newDate (month, day, year);
          newDate.setDay(day+daysToAdd);
          return newDate;
       }
       
       
    
       Date operator - (int daysToSub) // binary subtraction
       {
          Date newDate (month, day, year);
          newDate.setDay(day-daysToSub);
          return newDate;
       }
       
        void operator+= (int daysToAdd) // addition assignment
       {
          setDay(day+daysToAdd);
       }
    
       void operator-= (int daysToSub) // subtraction assignment
       {
          setDay(day-daysToSub);
       }
       
       bool operator< (const Date& compareTo)
       {
          if (year < compareTo.year)
             return true;
          else if ((year == compareTo.year) && (month < compareTo.month))
             return true;
          else if ((year == compareTo.year) && (month == compareTo.month) 
                   && (day < compareTo.day))
             return true;
          else
             return false;
       }
    
       bool operator<= (const Date& compareTo)
       {
          if (this->operator== (compareTo))
             return true;
          else
             return this->operator< (compareTo);
       }
    
       bool operator > (const Date& compareTo)
       {
          return !(this->operator<= (compareTo));
       }
    
       bool operator== (const Date& compareTo)
       {
          return ((day == compareTo.day)
             && (month == compareTo.month)
             && (year == compareTo.year));
       }
       
       
        bool operator!= (const Date& compareTo)
        {
            return !(this->operator==(compareTo));
        }
       
       bool operator>= (const Date& compareTo)
       {
          if(this->operator== (compareTo))
             return true;
          else
             return this->operator> (compareTo);
       }

    
       void DisplayDate()
       {
          cout << month << " / " << day << " / " << year << endl;
       }
       
    operator const int ()//returns number of days assuming all months are 31 as the unique integer
    {
        return year*365 + month*31 + day;
    }
};


int main()
{//random testing code

	cout << "BOB" << endl;
    Date d1= Date(12,31,2020);
    d1-=512;
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
	
	
	
	
	Date holiday (1, -4, 2016); // Dec 27, 2015
	cout << "The date object is initialized to: ";
	holiday.DisplayDate ();
	++holiday; // move date ahead by a day
	cout << "Date after prefix-increment is: ";
	holiday.DisplayDate ();
	holiday--; // move date backwards by a day
	cout << "Date after a prefix-decrement is: ";
	cout << (int)holiday << endl;
	
	holiday += 10;
	holiday.DisplayDate();
	return 0;
}






