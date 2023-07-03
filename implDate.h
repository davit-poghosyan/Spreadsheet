void Day::setDay(int num)
{	
	 if (num >= 0 && num <= 31) {
		 day = num;
		 return;
	 }	else { 
	//	 throw ("undefined behavior");
	 std::cout << "Day error\n";
	 }
}

unsigned int Day::getDay() const
{
	return day;
}

bool Day::operator==(const Day& rhs)
{
	if (day == rhs.day) {
		return true;
	}
	return false;
}

/*
bool operator==(Day& first, Day& second)
{
	first.operator==(second);
}
*/

void Month::setMonth(int num)
{
	if (num >= 0 && num <= 12) {
		month = num;
	} else {
	//	throw ("undefined behavior");
	 std::cout << "Month error\n";
	 }
	}

unsigned int Month::getMonth() const
{
	return month;
}

bool Month::operator==(const Month& rhs)
{
	if (month == rhs.month) {
		return true;
	}
	return false;
}	



void Year::setYear(int num)
{
	if(num > 0) {
		year = num;
	} else { 
	//	throw ("undefined behavior");
	 std::cout << "Year error\n";
	 }
	}

unsigned int Year::getYear() const
{
	return year;
}


bool Year::operator==(const Year& rhs)
{
	if (year == rhs.year) {
		return true;
	}
	return false;
}


void Date::setDate(Day d, Month m, Year y) 
{
	day = d;
	month = m;
	year = y;
}

Day Date::Date_getDay() const
{
	return day;
}

Month Date::Date_getMonth() const
{
	return month;
}

Year Date::Date_getYear() const
{
	return year;
}
/*
bool Date::operator==(Date& rhs)
{
	if (day == rhs.day && month == rhs.month && year == rhs.year) {
		return true;
	}
		return false;
}
*/


bool operator==(Date& first, Date& second)
{

	if (first.day == second.day && first.month == second.month && first.year == second.year) {
		return true;
	}
		return false;
}
