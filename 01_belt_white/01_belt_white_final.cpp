/*
** Final assignment
** Artem Barinov
** Feb 27, 2021
*/
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>
#include <iomanip>

using namespace std;

class Date {
    public:
    Date(){year = 0; month = 0; day = 0;}
    Date(int new_year, int new_month, int new_day) {
        year = new_year;
        if (new_month < 1 || new_month > 12) {
            throw invalid_argument("Month value is invalid: " + to_string(new_month));
        }
        month = new_month;
        if (new_day < 1 || new_day > 31) {
            throw invalid_argument("Day value is invalid: " + to_string(new_day));
        }
        day = new_day;
    }
    
    int GetYear() const {
        return year;
    }

    int GetMonth() const {
        return month;
    }

    int GetDay() const { 
        return day;
    }
    private:
    int year;
    int day ;
    int month ;

};

bool operator< (const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() == rhs.GetYear()) {
        if (lhs.GetMonth() == rhs.GetMonth()) {
            return lhs.GetDay() < rhs.GetDay();
        }
        return lhs.GetMonth() < rhs.GetMonth();
    }
    return lhs.GetYear() < rhs.GetYear();
}

bool operator==(const Date& lhs, const Date& rhs) {
    return (lhs.GetYear() == rhs.GetYear()) && (lhs.GetMonth() == rhs.GetMonth()) && (lhs.GetDay() == rhs.GetDay());
}

ostream& operator<<(ostream& stream, const Date& date) {
    stream << setfill('0');
    stream << setw(4) << date.GetYear() << "-" << setw(2) << date.GetMonth() << "-" <<setw(2) << date.GetDay();
    return stream;
}

istream& operator>>(istream& stream, Date& date) {
    int year = 0;
    int month = 0;
    int day = 0;
    string str;
    stream >> str;
    stringstream ss(str);
    runtime_error ex("Wrong date format: " + str);
    set<char> letmein = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '-'};
    int mcount = 0;
    for(const char& symbol : str) {
        if(letmein.count(symbol) == 0) {
            throw ex;
        }
        if(symbol == '-') {
            mcount++;
        }
        else {
            mcount = 0;
        }
        if(mcount > 2) {
            throw ex;
        }
    }
    if(count(begin(str),end(str), '-') < 2) {
        throw ex;
    }
    if(str[str.size() - 1] == '-') {
        throw ex;
    }
    ss >> year;
    ss.ignore(1);
    ss >> month;
    ss.ignore(1);
    ss >> day;
    date = Date{year, month, day};
    return stream;
}

class Database {
    public:
    void AddEvent(const Date& date, const string& event) {
        db[date].insert(event);
    }
    bool DeleteEvent(const Date& date, const string& event) {
        if(db.count(date) == 0) {
          return false;
        }
        bool flag = db[date].count(event) != 0;
        db[date].erase(event);
        return flag;
    }
    int DeleteDate(const Date& date) {
        int size = db[date].size();
        db.erase(date);
        return size;
    }

    void Find(const Date& date) const {
        if(db.count(date) == 0) {
            return;
        }
        for(const auto& i: db.at(date)) {
          cout << i << endl;
        }
    }
    void Print() const {
        for (const auto& i : db) {
            for (const string& event : i.second) {
                cout << i.first << " " << event << endl;
            }
        }
    }

    private:
    map<Date, set<string>> db;
};

void Add(stringstream& ss, Database& db) {
    Date date;
    string event;
    ss >> date >> event;
    db.AddEvent(date, event);
}

void Del(stringstream& ss, Database& db) {
    Date date;
    string event;
    ss >> date >> event;
    if(event.empty()) {
        cout << "Deleted " << db.DeleteDate(date) << " events" << endl;
    }
    else {
        if(db.DeleteEvent(date, event)) {
            cout << "Deleted successfully" << endl;
        }
        else {
            cout << "Event not found" << endl;
        }
    }
}

void Find(stringstream& ss, Database& db) {
    Date date;
    ss >> date;
    db.Find(date);
}

int main() {
    Database db;
    string cline;
    while(getline(cin, cline)) {
        stringstream ss(cline);
        string command;
        ss >> command;
        try {
            if(command == "Add") {
                Add(ss, db);
            }
            else if(command == "Del") {
                Del(ss, db);
            }
            else if(command == "Find") {
                Find(ss, db);
            }
            else if(command == "Print") {
                db.Print();
            }
            else if(command == "") {

            }
            else {
                cout << "Unknown command: " << command << endl;
            }
        }
        catch(runtime_error & e){
            cout << e.what() << endl;
            return 0;
        }
        catch(invalid_argument& e){
            cout << e.what() << endl;
            return 0;
        }
    }
    return 0;
}