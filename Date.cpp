#include "Date.h"
const int Date::days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
bool Date::leapYear()
{
    bool answer = ((mYear % 4 == 0) && (mYear % 100 != 0)) || (mYear % 400 == 0);

    return answer;
}
bool Date::endOfMonth(int testDay)
{
    if (mMonth == 2 && leapYear())
        return testDay == 29; // last day of Feb. in leap year
    else
        return testDay == days[mMonth];
}
void Date::increaseDate()
{
    // day is not end of month
    if (!endOfMonth(mDay))
        ++mDay; // increment day
    else
        if (mMonth < 12) // day is end of month and month < 12
        {
            ++mMonth; // increment month
            mDay = 1; // first day of new month
        }
        else // last day of year
        {
            ++mYear; // increment year
            mMonth = 1; // first month of new year
            mDay = 1; // first day of new month
        } // end else
}


bool Date::operator==(Date const& d) const      //overload equal to
{
    return (mMonth == d.mMonth) && (mDay == d.mDay) && (mYear == d.mYear);
}

bool Date::operator>(Date const& d) const       //overload greater than
{
    if ((mYear > d.mYear) ||
        ((mYear == d.mYear) && (mMonth > d.mMonth)) ||
        ((mYear == d.mYear) && (mMonth == d.mMonth) && (mDay > d.mDay)))
        return true;

    return false;
}

bool Date::operator<(Date const& d) const       //overload less than
{
    if ((mYear < d.mYear) ||
        ((mYear == d.mYear) && (mMonth < d.mMonth)) ||
        ((mYear == d.mYear) && (mMonth == d.mMonth) && (mDay < d.mDay)))
        return true;

    return false;
}
istream& operator >>(istream& read, Date& d) //friend read in
{
    char skipChar;
    string year, month, day;
    read >> d.mYear >> skipChar >> d.mMonth >> skipChar >> d.mDay;
    return read;
}
Date::Date(int year, int month, int day)
{

    this->mMonth = month;
    this->mDay = day;
    this->mYear = year;
}
Date::Date()
{
    this->mMonth = 0;
    this->mDay = 0;
    this->mYear = 0;
}
Date::Date(string date)
{
    setDateByStr(date);
}
int Date::getDay()
{
    return this->mDay;
}
int Date::getMonth()
{
    return this->mMonth;
}
int Date::getYear()
{
    return this->mYear;
}
string Date::toStr() const
{
    string day = to_string(mDay);
    string month = to_string(mMonth);
    string year = to_string(mYear);
    string date = year + "-" + month + "-" + day;
    return date;
}
void Date::setDateByStr(string date)
{
    istringstream iss(date);
    string token;
    getline(iss, token, '-');
    this->mYear = stoi(token);
    getline(iss, token, '-');
    this->mMonth = stoi(token);
    getline(iss, token, '-');
    this->mDay = stoi(token);
}

Date& Date::operator++()
{
    increaseDate(); // increment date
    return *this; // reference return to create an lvalue

}
Date Date::operator++(int)
{
    Date temp = *this;
    increaseDate();
    return temp;
}
Date Date::presentDate() const
{
    time_t now = time(0);
    tm* ltm = localtime(&now);
    return Date(1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday);
}