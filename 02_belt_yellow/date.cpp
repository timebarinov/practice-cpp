#include "date.h"
#include <iomanip>

Date::Date(int new_year, int new_month, int new_day) {
    year = new_year;    
    month = new_month;    
    day = new_day;
}

int Date::GetYear() const {
    return year;
}

int Date::GetMonth() const {
    return month;
}

int Date::GetDay() const {
    return day;
}

Date ParseDate(istream& stream) {
    int year;
    stream >> year;
    stream.ignore();
    int month;
    stream >> month;
    stream.ignore();
    int day;
    stream >> day;

    return {year, month, day};
};

bool operator< (const Date& lhs, const Date& rhs) {
    return (make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) <
            make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()));
}
bool operator> (const Date& lhs, const Date& rhs) {
    return (make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) >
            make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()));
};

bool operator>=(const Date& lhs, const Date& rhs) {
    return (make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) >=
            make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()));
};
bool operator<=(const Date& lhs, const Date& rhs) {
    return (make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) <=
            make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()));
};

bool operator==(const Date& lhs, const Date& rhs) {
    return (make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) ==
            make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()));
}

bool operator!=(const Date& lhs, const Date& rhs) {
    return (make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) !=
            make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()));
};

ostream& operator<<(ostream& stream, const Date& date) {
    stream << setfill('0');
    stream << setw(4) << date.GetYear() << "-" << setw(2) <<
            date.GetMonth() << "-" <<setw(2) << date.GetDay();
    return stream;
}

