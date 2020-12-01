#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <cctype>
#include <fstream>
#include <iomanip>


using namespace std;


class Date {
public:
   
    Date() {
         year = 0;
         month = 0;
         day = 0;
    }

    explicit Date(int newYear, int newMonth, int newDay) {
        year = newYear;
        month = newMonth;
        day = newDay;
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

    void SetDay() {
        cin >> day;
    }

    void SetMonth() {
        cin >> month;
    }

    void SetYear() {
        cin >> year;
    }

    friend istream& operator>>(istream& stream, Date& date) {
        date.SetYear();
        date.SetMonth();
        date.SetDay();
        return stream;
    }

    friend ostream& operator<<(ostream& stream, const Date& date) {
        stream  << setfill('-') << date.GetYear();
        stream << fixed << setw(3) << setfill('-') << date.GetMonth();
        stream << fixed << setw(3) << setfill('-') << date.GetDay();
        return stream;
    }

private:
    int day;
    int month;
    int year;
};



bool operator<(const Date& lhs, const Date& rhs) {
    int Lyear = lhs.GetYear();
    int Lmonth = lhs.GetMonth();
    int Lday = lhs.GetDay();

    int Ryear = rhs.GetYear();
    int Rmonth = rhs.GetMonth();
    int Rday = rhs.GetDay();
  
    if (Lyear < Ryear) {
        return true;
    }
    else if(Lmonth < Rmonth && Lyear == Ryear) {
        return true;
    }
    else if (Lday < Rday && Lyear == Ryear && Lmonth == Rmonth) {
        return true;
    }
    else {
        return false;   
    }
};

class Database {
public:
    void AddEvent(const Date& date, const string& event) {
        mData[date] = event;
        cout << "mdata[date]: " << mData[date];
    };
    bool DeleteEvent(const Date& date, const string& event) {
    
    };
    int  DeleteDate(const Date& date) {
    
    };

    void Find(const Date& date) const {
        
    };

    void Print() const {
    
    };
    
private:
    map<Date, string> mData;
};

int main() {
    Database database;
    Date date{3, 2, 1};

   

    string command;
    while (getline(cin, command, ' ')) {
        if (command == "Add") {
            string event;
            cin >> event;
            database.AddEvent(date, event);
        }
        else if (command == "Del") {

        }
        else if (command == "Find") {

        }
        else if (command == "Print") {

        }
    }

    return 0;
}


