#include "date.h"
#include <iostream>
#include <string>
#include <cmath>

#ifndef CELL_H
#define CELL_H

enum class Collor {green, orange, red, white};

class Cell
{
	private:
		std::string m_str;
	 	Collor m_collor = Collor::white;
	public:
		Cell& operator=(const Cell& rhs);
	public:
		void setValue(const std::string& str);
		void setCollor(Collor);
		std::string getValue() const;
		Collor getCollor() const;
		int toInt();
		double toDouble();
		Date toDate();
		void reset();
	//	friend bool operator==(Cell& first, Cell& second);
		bool operator==(Cell& rhs);
};

//bool operator==(const Cell& first, const Cell& second);


#include "impl_Cell.h"
#endif

