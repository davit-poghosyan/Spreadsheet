Spreadsheet::Spreadsheet()
{
	m_row = 0;
	m_column = 0;
	m_cells = nullptr;
}

Spreadsheet::Spreadsheet(int row, int column) 
{
	m_row = row;
	m_column = column;

	m_cells = new Cell*[m_row];
	for (int i = 0; i < m_row; ++i) {
		m_cells[i] = new Cell[m_column];
	}
}

Spreadsheet& Spreadsheet::operator=(const Spreadsheet& rhs)
{
	if (this == &rhs) {
		return *this;
	}

	for (int i = 0; i < m_row; ++i) {
		delete[] m_cells[i];
	}
	delete[] m_cells;
	m_cells = nullptr;


	m_row = rhs.m_row;
	m_column = rhs.m_column;

	m_cells = new Cell* [m_row];
	for (int i = 0; i < m_row; ++i) {
		m_cells[i] = new Cell [m_column];
	}

	for (int i = 0; i < m_row; ++i) {
		for(int j = 0; j < m_column; ++j) {
			m_cells[i][j] = rhs.m_cells[i][j];
		}
	}

	return *this;
}

Spreadsheet::~Spreadsheet()
{
	for (int i = 0; i < m_row; ++i) {
		delete[] m_cells[i];
	}
	delete[] m_cells;
	m_cells = nullptr;
}

void Spreadsheet::setCellAt(int row, int column, const Cell& cl)
{
	m_cells[row][column] = cl;
}

void Spreadsheet::setCellAt(int row, int column, const std::string& cl)
{
	
	m_cells[row][column].setValue(cl);	
}

Cell& Spreadsheet::getCellAt(int row, int column) const 
{
	return m_cells[row][column];
}


void Spreadsheet::addRow(int row)
{
	m_row = m_row + 1;
	Cell** tmp = new Cell* [m_row];
	for (int k = 0; k < m_row; ++k) {
		tmp[k] = new Cell [m_column];
	}

	int i = 0;
	
	for (i; i < row; ++i) {
		for (int j = 0; j < m_column; ++j) {
			tmp[i][j] = m_cells[i][j];
		}
	}
	
	int f = i;
	++i;
	
	for (i, f; i < m_row; ++i, ++f) {
		for (int j = 0; j < m_column; ++j) {
			tmp[i][j] = m_cells[f][j];
		}
	}

	for (int i = 0; i < m_row - 1; ++i) {
		delete[] m_cells[i];
	}
	

	m_cells = tmp;
	tmp = nullptr;
}


void Spreadsheet::removeRow(int row) 
{
	m_row = m_row - 1;
	Cell** tmp = new Cell* [m_row];
	for (int k = 0; k < m_row; ++k) {
		tmp[k] = new Cell [m_column];
	}

	int i = 0;

	for (i; i <  row - 1; ++i) {
		for (int j = 0; j < m_column; ++j) {
			tmp[i][j] = m_cells[i][j];
		}
	}
	
	int f = i;
	++i;

	for (i, f; i < m_row + 1; ++i, ++f) {
		for (int j = 0; j < m_column; ++j) {
			tmp[f][j] = m_cells[i][j];
		}
	}

	for (int i = 0; i < m_row + 1; ++i) {
		delete[] m_cells[i];
	}
	
	m_cells = tmp;
	tmp = nullptr;
}

void Spreadsheet::addColumn(int column) 
{
	m_column = m_column + 1;
	Cell** tmp = new Cell* [m_row]; 
	for (int i = 0; i < m_row; ++i) {
		tmp[i] = new Cell [m_column];
	}

	int j = 0;
	for (int i = 0; i < m_row; ++i) {
		for (j; j < column; ++j) {
			tmp[i][j] = m_cells[i][j];
		}
	}

	int f = j;
	++j;
	
	for (int i = 0; i < m_row; ++i) {
		for (int p = j, o = f ; p < m_column; ++p, ++o) {
			tmp[i][p] = m_cells[i][o];
		}
	}

	for (int i = 0; i < m_row; ++i) {
		delete[] m_cells[i];
	}

	m_cells = tmp;
	tmp = nullptr;
}

void Spreadsheet::removeColumn(int column)
{
	m_column = m_column - 1;	
	Cell** tmp = new Cell* [m_row];
	for (int i = 0; i < m_row; ++i) {
		tmp[i] = new Cell [m_column];
	}

	int j = 0;
	
	for (int i = 0; i < m_row; ++i) {
		for (j; j < m_column - 1; ++j) {
			tmp[i][j] = m_cells[i][j];
		}
	}

	int f = j;
	++j;

	for (int i = 0; i < m_row; ++i) {
		for (int p = j, o = f; p < m_column + 1; ++p, ++o) {
			tmp[i][o] = m_cells[i][p]; 
		}
	}

	for (int i = 0; i < m_row; ++i) {
		delete[] m_cells[i];
	}
	
	m_cells = tmp;
	tmp = nullptr;

}

void Spreadsheet::swapRows(int row1, int row2) 
{
	Cell* arr1 = new Cell [m_column];
	Cell* arr2 = new Cell [m_column];

	for (int i = 0; i < m_column; ++i) {
		arr1[i] = m_cells[row1 - 1][i];
	}

	for (int i = 0; i < m_column; ++i) {
		arr2[i] = m_cells[row2 - 1][i];
	}
	
	for (int i = 0; i < m_row; ++i) {
		for (int j = 0; j < m_column; ++j) {
			if (i == row1 - 1) {
				m_cells[i][j] = arr2[j];
			}
			if (i == row2 - 1) {
				m_cells[i][j] = arr1[j];
				
			}
		}
	}

}

void Spreadsheet::swapColumn(int column1, int column2)
{
	
	Cell* arr1 = new Cell [m_row];
	Cell* arr2 = new Cell [m_row];

	for (int i = 0; i < m_row; ++i) {
		arr1[i] = m_cells[i][column1 - 1];
	}

	for (int i = 0; i < m_row; ++i) {
		arr2[i] = m_cells[i][column2 - 1];
	}

	for (int j = 0; j < m_column; ++j) {
		for (int i = 0; i < m_row; ++i) {
			if (j == column1 - 1) {
				m_cells[i][j] = arr2[i];
			}
			if (j == column2 - 1) {
				m_cells[i][j] = arr1[i];
			}
		}
	}
}
