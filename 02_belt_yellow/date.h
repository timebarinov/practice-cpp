#pragma once

#include <iostream>
#include <algorithm>

using namespace std;

class Date {
    public:    
    Date(int new_year, int new_month, int new_day);

    int GetYear() const;

    int GetMonth() const;

    int GetDay() const; 

    private:
    int year;
    int day;
    int month;

};

Date ParseDate(istream& stream);

bool operator< (const Date& lhs, const Date& rhs);

bool operator> (const Date& lhs, const Date& rhs);

bool operator>=(const Date& lhs, const Date& rhs);

bool operator<=(const Date& lhs, const Date& rhs);

bool operator==(const Date& lhs, const Date& rhs);

bool operator!=(const Date& lhs, const Date& rhs);

ostream& operator<<(ostream& stream, const Date& date);

