#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class Date
{
	friend ostream& operator<<(ostream &out, const Date &D)
	{
		out << D._year << '年' << D._month << '月' << D._day << '日' << endl;
	}
public:
	Date(int year = 1900, int month = 1, int day = 1)
		//:_year(year),_month(month),_day(day);
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
	}
	Date operator+(int days);
	Date operator-(int days);
	int operator-(const Date& d);//两个时间相减
	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);
	bool operator>(const Date& d)const
	{
		if (_year > d._year)
			return true;
		else if (_year < d._year)
			return false;
		else if (_month > d._month)
			return true;
		else if (_month < d._month)
			return false;
		else if (_day > d._day)
			return true;
		else
			return false;
	}
	bool operator>=(const Date& d)const
	{
		return !(*this < d);
	}
	bool operator<(const Date& d)const
	{
		if (_year < d._year)
			return true;
		else if (_year > d._year)
			return false;
		else if (_month < d._month)
			return true;
		else if (_month > d._month)
			return false;
		else if (_day < d._day)
			return true;
		else
			return false;
	}
	bool operator<=(const Date& d)const
	{
		return !(*this > d);
	}
	bool operator==(const Date& d)const
	{
		return (_year == d._year && _month == d._month && _day == d._day);
	}
	bool operator!=(const Date& d)const
	{
		//return (_year != d._year || _month != d._month || _day != d._day);
		return !(*this == d);
	}
public:
	int GetWeek(int year, int month, int day);//给出年月日判断是周几(蔡勒公式)
private:
	int _year;
	int _month;
	int _day;
};

bool IsLeap(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return false;
}
int GetDate(int year, int month)
{
	int days[13] = { 29, 31, 28, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2)
	{
		if (IsLeap(year))
			month = 0;
	}
	return days[month];
}
Date Date::operator+(int days)
{
	Date tmp = *this;
	int mdays = GetDate(tmp._year, tmp._month);
	while (days + tmp._day > mdays)
	{
		tmp._month++;
		if (tmp._month > 12)
		{
			tmp._month = 1;
			tmp._year++;
		}
		days -= mdays;
		mdays = GetDate(tmp._year, tmp._month);
	}
	tmp._day += days;
	return tmp;
}
/*
Date Date::operator-(int days)
{

}
//int operator-(const Date& d)
{

}
*/
Date& Date::operator++()
{
	*this = *this + 1;
	return *this;
}
Date Date::operator++(int)
{
	Date tmp = *this;
	++*this;
	return tmp;
}
//返回没引用（&），要调动拷贝构造
void main()
{
	Date D(2019,10,20);
	cout << D << endl;
	Date dt = dt + 100;
	cout << dt << endl;
	++dt;   //dt.operator++;
	dt++;   //dt.operator++(0);
}