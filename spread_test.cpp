#include "Spreadsheet.h"

class SpreadTest
{	
	public:	
		void _setCellAt();
		void _setCellAtString();
		void _getCellAt();
		void _addRow();
		void _removeRow();
		void _addColumn();
		void _removeColumn();
		void _swapRows();
		void _swapColumn();
};


void SpreadTest::_setCellAt()
{
	Spreadsheet obj(5, 5);
	Cell ob;
	ob.setValue("1010");
	obj.setCellAt(2, 2, ob);
	
	if(obj.getCellAt(2, 2) == ob) {
		std::cout << "pass\n";
	} else {
		std::cout << "fail\n";
	}
}
void SpreadTest::_setCellAtString()
{
	Spreadsheet obj (5, 5);
	std::string str = "example";
	obj.setCellAt(2, 2, str);

	if (obj.getCellAt(2, 2).getValue() == "example") {
		std::cout << "pass\n";
	} else { 
		std::cout << "fail\n";
	}

}

void SpreadTest::_getCellAt()
{
	Spreadsheet obj(5, 5);
	Cell ob;
	ob.setValue("1010");
	obj.setCellAt(2, 2, ob);

	if(obj.getCellAt(2, 2) == ob) {
		std::cout << "pass\n";
	} else {
		std::cout << "fail\n";
	}
}

void SpreadTest::_addRow()
{
	Spreadsheet obj(4, 4);
	Cell ob;
	ob.setValue("100");
	obj.setCellAt(3, 3, ob);
	obj.addRow(2);
	
	if (obj.getCellAt(4, 3) == ob) {
		std::cout << "pass\n";
	} else {
		std::cout << "fail\n";
	}

}

void SpreadTest::_removeRow()
{
	Spreadsheet obj(4, 4);
	Cell ob;
	ob.setValue("100");
	obj.setCellAt(3, 3, ob);
	obj.addRow(2);

	if (obj.getCellAt(4, 3) == ob) {
		std::cout << "pass\n";
	} else {
		std::cout << "fail\n";
	}

	obj.removeRow(3);

	if (obj.getCellAt(3, 3) == ob) {
		std::cout << "pass\n";
	} else {
		std::cout << "fail\n";
	}
}

void SpreadTest::_addColumn()
{
	Spreadsheet obj(4, 4);
	Cell ob;
	ob.setValue("100");
	obj.setCellAt(3, 3, ob);
	obj.addColumn(2);
	if (obj.getCellAt(3, 4) == ob)
	{
		std::cout << "pass\n";
	} else {
		std::cout << "fail\n";
	}

}


void SpreadTest::_removeColumn() 
{
	Spreadsheet obj(4, 4);
	Cell ob;
	ob.setValue("100");
	obj.setCellAt(3, 3, ob);
	obj.addColumn(2);

	if (obj.getCellAt(3, 4) == ob) {
		std::cout << "pass\n";
	} else {
		std::cout << "fail\n";
	}

	obj.removeColumn(3);

	if (obj.getCellAt(3, 3) == ob) {
		std::cout << "pass\n";
	} else { 
		std::cout << "fail\n";
	}
}

void SpreadTest::_swapRows()
{
	Spreadsheet obj(4, 4);
	Cell ob1, ob2;
	ob1.setValue("100");
	ob2.setValue("200");
	obj.setCellAt(2, 2, ob1);
	obj.setCellAt(3, 2, ob2);
	obj.swapRows(3, 4);

	if(obj.getCellAt(3, 2) == ob1 && obj.getCellAt(2, 2) == ob2) {
		std::cout << "pass\n";
	} else {
		std::cout << "fail\n";
	}
}

void SpreadTest::_swapColumn()
{
	Spreadsheet obj(4, 4);
	Cell ob1, ob2;
	ob1.setValue("100");
	ob2.setValue("200");
	obj.setCellAt(2, 2, ob1);
	obj.setCellAt(2, 3, ob2);
	obj.swapColumn(3, 4);
	
	if (obj.getCellAt(2, 2) == ob2 && obj.getCellAt(2, 3) == ob1) {
		std::cout << "pass\n";
	} else {
		std::cout << "fail\n";
	}

}
int main()
{
	SpreadTest obj;
	obj._setCellAt();	
	obj._setCellAtString();
	obj._getCellAt();
	obj._addRow();
	obj._removeRow();
	obj._addColumn();
	obj._removeColumn();
	obj._swapRows();
	obj._swapColumn();
}
