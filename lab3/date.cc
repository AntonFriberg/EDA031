#include <ctime>  // time and localtime
#include <iostream>
#include "date.h"
#include <string>
#include <iomanip>
using namespace std;
int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() {
	time_t timer = time(0); // time in seconds since 1970-01-01
	tm* locTime = localtime(&timer); // broken-down time
	year = 1900 + locTime->tm_year;
	month = 1 + locTime->tm_mon;
	day = locTime->tm_mday;
}

Date::Date(int y, int m, int d) {
	year=y;
	month=m;
	day=d;
}

int Date::getYear() const {
	return year;
}

int Date::getMonth() const {
	return month;
}

int Date::getDay() const {
	return day;
}

void Date::next() {
	if(daysPerMonth[month-1]==day){
		if(month==12){
			year++;
			month=1;
		} else {
			month++;
		}
		day=1;
	} else {
		day++;
	}
}

	ostream &operator<<(ostream &os, const Date &d){
		os<<setfill('0')<<setw(4)<<d.getYear()<<'-'
			<<setfill('0')<<setw(2)<<d.getMonth()<<'-'
				<<setfill('0')<<setw(2)<<d.getDay();
		return os;
	}

	istream &operator>>(istream &is,  Date &d){
			int year;
			int month;
			int day;
			is>>year>>month>>day;
			month=month*(-1);
			day=day*(-1);
			if(year<0 || month<1 || month > 12 || day < 1 || day>d.daysPerMonth[month-1]){
				is.setstate(ios_base::failbit);
			} else {
				d.year=year;
				d.month=month;
				d.day=day;
			}
			return is;
	}
