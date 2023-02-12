#include "Cell.h"
#include <iostream>
#include <string>
#ifndef SPREADSHEET_H
#define SPREADSHEET_H


class Spreadsheet
{
	private:
	 	int m_row;
		int m_column;
		Cell** m_cells;
	public:
		Spreadsheet();
		Spreadsheet(int row, int column);
		Spreadsheet& operator=(const Spreadsheet& rhs);
	public:
		void setCellAt(int row, int column, const Cell& cl);
		void setCellAt(int row, int column, const std::string& cl);
		Cell& getCellAt(int row, int column) const;
		void addRow(int row);
		void removeRow(int row);
		void addColumn(int column);
		void removeColumn(int column);
		void swapRows(int row1, int row2);
		void swapColumn(int column1, int column2);
		friend class SpreadTest;
};

#include "impl_spreadsheet.h"
#endif // spreadsheet_h
