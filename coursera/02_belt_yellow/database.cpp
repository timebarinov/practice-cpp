#include "database.h"

void Database::Add(const Date& date, const string& event) {    
    if(db[date].count(event) == 0){
        search_db[date].push_back(event);
        db[date].insert(event);
    }
}

void Database::Print(ostream& stream) const {
    for (const auto &pair : search_db) {
        if(!pair.second.empty()) {
            for(const string& e : pair.second) {
                stream << pair.first << ' ' << e << endl;
            }
        }
    }

}

string Database::Last(const Date& date) const {
    if (db.empty()) {
        return "No entries";
    }
    auto map_low = db.lower_bound(date);
    auto tmp = map_low;
    if (map_low->first == date) {
        tmp = map_low;
    } else if (map_low == db.end()) {
        tmp = prev(map_low);
    } else if (map_low == db.begin() && map_low->first != date){
        return "No entries";
    } else {
        tmp = prev(map_low);
    }
    map_low = tmp;
    string str_low;
    if (search_db.count(map_low->first) != 0)
        str_low = search_db.at(map_low->first).back();

    auto low_date = map_low->first;
    stringstream s;
    string str_date;
    s << low_date;
    s >> str_date;
    return str_date + " " + str_low;
}