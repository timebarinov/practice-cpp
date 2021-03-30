#pragma once

#include "date.h"
#include "node.h"
#include <map>
#include <set>
#include <vector>
#include <functional>
#include <sstream>
#include <algorithm>


using namespace std;

class Database {
    public:
    void Add(const Date& date, const string& event);

    void Print(ostream& stream) const;

    string Last(const Date& date) const;

    template <typename Function>
    vector<string> FindIf(const Function fn) const {
        vector<string> tmp;

        for (auto it : search_db) {
            for (auto j : it.second) {
                if (db.count(it.first) != 0 && db.at(it.first).count(j) != 0 && fn(it.first, j)) {
                    string str_date;
                    stringstream ss;
                    ss << it.first;
                    ss >> str_date;
                    tmp.push_back(str_date + " " + j);
                }
            }
        }
        return tmp;
    }

    template <typename Function>
    int RemoveIf(Function fn) {
        int count = 0;
        for (auto& i : search_db) {
            auto it = stable_partition(begin(i.second), end(i.second),
            [fn, i](string s) { return fn(i.first, s); });
            count += it - i.second.begin();
            i.second.erase(i.second.begin(), it);
        }
        for (auto it = db.begin(); it != db.end(); ) {
            for (auto i = it->second.begin(); i != it->second.end(); ) {
                auto next_i = next(i);
                if (fn(it->first, *i)) {
                    it->second.erase(*i);
                }
                i = next_i;
                if (it->second.empty()){
                    break;
                }
            }            
            auto next_it = next(it);
            if (it->second.size() == 0) {
                db.erase(it->first);
            }
            it = next_it;
            if (db.empty()){
                break;
            }
        }
        return count;
    }
    
    
    private:
    map<Date, set<string>> db;
    map<Date, vector<string>> search_db;
};

