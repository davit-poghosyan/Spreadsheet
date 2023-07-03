#include "Date.h"
#include "Cell.h"
#include <iostream>
#include <string>

class Test {
	public:
		void _getValue() const;
		void _getCollor() const;
		void  _toInt() const;
		void _toDouble() const;
		void _toDate();
		void _reset();
};


void Test::_getValue() const
{
	Cell obj;
	obj.setValue("100");
	
	if (obj.getValue() == "100") {
		std::cout << "pass\n";
	} else {
		std::cout << "fail\n";
	}
}

void Test::_getCollor() const
{
	Cell obj;
	Collor collor = Collor::white;
	obj.setCollor(collor);

	if(obj.getCollor() == Collor::white) {
		std::cout << "pass\n";
	} else {
		std::cout << "fail\n";
	}

}

void Test::_toInt() const 
{
	Cell obj;
	obj.setValue("-10");	
	if(obj.toInt() == -10) {
		std::cout << "pass\n";
	} else {
		std::cout << "fail\n";
	}
}

void Test::_toDouble() const
{
	Cell obj;
	obj.setValue("1.1");
	if (obj.toDouble() == 1.1) {
		std::cout << "pass\n";
	} else {
		std::cout << "fail\n";
	}
}

void Test::_toDate() 
{
	Cell obj;
	obj.setValue("4.5.2020");
	Date val;
	val = obj.toDate();
	Day d;
	d.setDay(4);


	Month m;
	m.setMonth(5);
	
	Year y;
	y.setYear(2020);


	Date date;
	date.setDate(d,m,y);

	Date ob;
	ob = obj.toDate(); 
	if (ob == date) {
		std::cout << "pass\n";
	} else {
		std::cout << "fail\n";
	}

}

void Test::_reset() 
{
	Cell  obj;
	obj.reset();
	if(obj.getValue() == "" && obj.getCollor() == Collor::white) {
		std::cout << "pass\n";
	} else {
		std::cout << "fail\n";
	}
}




int main()
{
	Test obj;
	obj._getValue();
	obj._getCollor();
	obj._toInt();
	obj._toDouble();
	obj._toDate() /*const*/;
	obj._reset();

}
