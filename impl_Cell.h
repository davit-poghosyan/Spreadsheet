Cell& Cell::operator=(const Cell& rhs)
{
	m_str = rhs.m_str;
	m_collor = rhs.m_collor;
	return *this;
}

void Cell::setValue(const std::string& str)

{
	m_str = str;
}

void Cell::setCollor(Collor cl)
{
	m_collor = cl;
}

std::string Cell::getValue() const
{	
	return m_str;
}

Collor Cell::getCollor() const
{
	return m_collor;
}

int Cell::toInt()
{
	int num = 0;
	
	if(m_str[0] == '-') {
		for(int i = 1; i < m_str.size(); ++i) {
			num = num * 10 + m_str[i] - 48;
		}

		num = num * (-1);
	} else {

		for (int i = 0; i < m_str.size(); ++i) {
			num = num * 10 + m_str[i] - 48;
		}
	}

	return num;
}	

double Cell::toDouble()
{
	double num = 0;
	double index;
	if (m_str[0] == '-') {
		for (int i = 1; i < m_str.size(); ++i) {
			if (m_str[i] == '.' || m_str[i] == ',') {
				index = i;
				continue;
			}

			num = num * 10 + m_str[i] - 48;
		}
		num = num / pow(10.0,(index - 1));
		num = num * (-1);
	} else {
		for (int i = 0; i < m_str.size(); ++i) {
			if (m_str[i] == '.' || m_str[i] == ',') {
				index = i;
				continue;
			}
			num = num * 10 + m_str[i] - 48;
		}
		num = num / pow(10.0, index);	
	}
	return num; 
}

Date Cell::toDate()
{
	int i = 0;
	int day = 0;
	for (i; i < m_str.size(); ++i) {
		if (m_str[i] == '.' || m_str[i] == ',') {
			break;
		}
		day = day * 10 + m_str[i] - 48;
	}
	++i;
	Day d;
	d.setDay(day);

	
	int month = 0;
	for (i; i < m_str.size(); ++i) {
		if (m_str[i] == '.' || m_str[i] == ',') {
			break;
		}
		month = month * 10 + m_str[i] - 48;
	}
	++i;
	Month m;
	m.setMonth(month);
	

	int year = 0;
	for (i; i < m_str.size(); ++i) {
		year = year * 10 + m_str[i] - 48;
	}
	Year y;
	y.setYear(year);

	Date date;
	date.setDate(d, m, y);

	return date;	
}

void Cell::reset()
{
	m_str = "";
	m_collor = Collor::white;	
}


bool Cell::operator==(Cell& rhs)
{
	return (m_str == rhs.m_str && m_collor == rhs.m_collor); 

}
/*
bool operator==(Cell& first// Cell& second)
{
	if (first.m_str == second.m_str && first.m_collor == second.m_collor) {
		return true;
	}
	return false;
}

*/


