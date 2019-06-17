// test1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
using namespace std;
class CMyDate
{
private:
	int year;
	int month;
	int day;
	int check();
public:
	CMyDate();
	CMyDate(int y, int m, int d);
	int setDate(int y, int m, int d);
	void dispaly();
	CMyDate operator +(CMyDate &otemp);
	CMyDate operator + (int const &d);
	CMyDate addDate(CMyDate &om);
	int getYear();
	int getMonth();
	int getDay();
	void addoneday();
};
int CMyDate::check()
{
	int flatYearDays[13] = { 31,31,28,31,30,31,30,31,31,30,31,30,31 };
	int leapYearDays[13] = { 31,31,29,31,30,31,30,31,31,30,31,30,31 };
	int temp = 1;
	while (temp == 1 && month != 0 && day != 0)
	{
		if (year % 400 == 0 || (year % 4 != 0 && year % 100 != 0))
		{
			if (leapYearDays[month] < day)
			{
				day = day - leapYearDays[month];
				month++;
				temp = 1;
			}
			else
			{
				temp = 0;
			}
		}
		else
		{
			if (flatYearDays[month] < day)
			{
				day = day - leapYearDays[month];
				month++;
				temp = 1;
			}
			else
			{
				temp = 0;
			}
		}
	}
	while (month > 12)
	{
		month = month - 12;
		year++;
	}
	return 0;
}
CMyDate::CMyDate()
{
	year = 2019;
	month = 6;
	day = 10;
}
CMyDate::CMyDate(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}
int CMyDate::setDate(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
	check();
	return 0;
}
CMyDate CMyDate::operator+(CMyDate &otemp)
{
	CMyDate temp;
	temp.setDate(year + otemp.year, month + otemp.month, day + otemp.day);
	return temp;
}
CMyDate CMyDate::operator+(int const &d)
{
	CMyDate temp;
	temp.setDate(year, month, day + d);
	return temp;
}
CMyDate CMyDate::addDate(CMyDate &om)
{
	CMyDate temp;
	temp.setDate(year + om.year, month + om.month, day + om.day);
	return temp;
}
int CMyDate::getYear()
{
	return year;
}
int CMyDate::getMonth()
{
	return month;
}
int CMyDate::getDay()
{
	return day;
}
void CMyDate::addoneday()
{
	int flatYearDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int leapYearDays[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	day++;
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
	{
		if (leapYearDays[month - 1]<day)
		{
			day = 1;
			month++;
		}
	}
	else
	{
		if (flatYearDays[month - 1] < day)
		{
			day = 1;
			month++;
		}
	}
	if (month > 12)
	{
		month = 1;
		year++;
	}
}
void CMyDate::dispaly()
{
	cout << year << "年" << month << "月" << day << "日" << endl;
}
int main()
{
	CMyDate od1(2019, 6, 17), od2(50, 18, 90), od3;
	od3 = od1 + od2;
	od3.dispaly();
	CMyDate om;
	int count = 1;
	om.setDate(2000, 3, 23);
	om.dispaly();
	while (!((om.getYear() == 2019) && (om.getMonth() == 6) && (om.getDay()) == 17))
	{
		om.addoneday();
		count++;
	}
	cout << count << endl;
	return 0;
}
