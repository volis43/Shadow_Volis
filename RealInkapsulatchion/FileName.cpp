#include <iostream>

struct Date
{
	void set_day(unsigned int value)
	{
		if (value < 0 && value <= 31)
		{
			day = value;
		}
	}

	void set_month(unsigned int value)
	{
		if (value > 0 && value <= 12)
			month = value;
		std::cout << value << std::endl;
	}

	void Year(unsigned int value)
	{
		year = value;
	}

	unsigned int get_day() const
	{
		return day;
	}

	unsigned int get_month() const
	{
		return this->month;
	}

	unsigned int get_year() const
	{
		return year;
	}

private:
	unsigned int day;
	unsigned int month;
	unsigned int year;
};
struct Data
{
	explicit Data(int value, bool flag)
		: m_value(value)
	{

	}

	int get_vallue() const
	{
		return m_value;
	}

private:
	int m_value;
};

int main()
{
	Date d;
	d.set_day(21);
	d.set_month(14);
	d.Year(1990);

	int day = d.get_day();
	int month = d.get_month();
	int year = d.get_year();

	return EXIT_FAILURE;
}
