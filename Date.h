#ifndef DATE_H
#define DATE_H
class Day 
{
	private:
		unsigned int day;
	public:
		void setDay(int num);
		unsigned int getDay() const;
		bool operator==(const Day& rhs);
};

class Month
{ 
	private:
		unsigned int month;
	public:
		void setMonth(int num);
		unsigned int getMonth() const;
		bool operator==(const Month& rhs);
};

class Year
{
	private:
		unsigned int year;
	public:
		void setYear(int num);
		unsigned int getYear() const;
		bool operator==(const Year& rhs);
};


class Date 
{
	private:
		Day day;
		Month month;
		Year year;
	public:
		void setDate(Day d, Month m, Year y);
		Day Date_getDay() const;
		Month Date_getMonth() const;
		Year Date_getYear() const;
	//	bool operator==(Date& rhs);
		friend bool operator==(Date& firts, Date& second);
};

bool operator==(const Date& firts, const Date& second);
#include <iostream>
#include "impl_Date.h"
#endif
