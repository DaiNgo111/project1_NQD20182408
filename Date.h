#pragma once
#ifndef DATE_H
#define DATE_H
#include <iostream>
#include<string>
#include<ctime>
#include<sstream>
using namespace std;
class Date
{
private:
    int mDay;
    int mMonth;
    int mYear;
    static const int days[];
    void increaseDate();
public:
    Date();
    Date(int year, int month, int day);
    Date(string date);
    string toStr() const;
    int getDay();
    int getMonth();
    int getYear();
    void setDateByStr(string);
    bool operator==(Date const& d) const;   //overload equal to
    bool operator>(Date const& d) const;    //overload greater than
    bool operator<(Date const& d) const;    //overload less than
    bool endOfMonth(int); // is date at the end of month
    bool leapYear(); // is date in a leap year
    Date& operator++(); // prefix increment operator
    Date operator++(int); // postfix increment operator
    friend istream& operator>>(istream& read, Date& d);   //overload friend read
    Date presentDate() const;

};

#endif