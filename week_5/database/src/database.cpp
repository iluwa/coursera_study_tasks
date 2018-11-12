#include <iostream>
#include <sstream>
#include <exception>
#include <map>
#include <set>
#include <iomanip>
using namespace std;

void EnsureNextSymbolAndSkip(stringstream& stream, const char& symbol) {
	if (stream.peek() != symbol) {
		throw invalid_argument("");
	}
	stream.ignore(1);
}

class Date {
public:
	Date(string date) {
		try {
			int new_year = 0;
			int new_month = 0;
			int new_day = 0;

			stringstream ss(date);
			ss >> new_year;
			EnsureNextSymbolAndSkip(ss, '-');
			ss >> new_month;
			EnsureNextSymbolAndSkip(ss, '-');
			ss >> new_day;

			if (new_month > 12 || new_month < 1) {
				throw runtime_error("Month value is invalid: " + to_string(new_month));
			}
			if (new_day > 31 || new_day < 1) {
				throw runtime_error("Day value is invalid: " + to_string(new_day));
			}

			year = new_year;
			month = new_month;
			day = new_day;
		} catch (invalid_argument&) {
			throw runtime_error("Wrong date format: " + date);
		}
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
	int month;
	int day;
};

ostream& operator<<(ostream& stream, const Date& date) {
	stream << setw(4) << setfill('0') << date.GetYear() << '-'
			<< setw(2) << setfill('0') << date.GetMonth() << '-'
			<< setw(2) << setfill('0') << date.GetDay();
	return stream;
}

bool operator<(const Date& lhs, const Date& rhs) {
	if (lhs.GetYear() == rhs.GetYear()) {
		if (lhs.GetMonth() == rhs.GetMonth()) {
			return lhs.GetDay() < rhs.GetDay();
		} else {
			return lhs.GetMonth() < rhs.GetMonth();
		}
	} else {
		return lhs.GetYear() < rhs.GetYear();
	}
}

class Database {
public:
	void AddEvent(const Date& date, const string& event) {
		data[date].insert(event);
	}

	bool DeleteEvent(const Date& date, const string& event) {
		if (data.count(date) == 0) {
			return false;
		}
		if (data[date].count(event) == 0) {
			return false;
		}
		data[date].erase(event);
		return true;
	}

	int DeleteDate(const Date& date) {
		if (data.count(date) == 0) {
			return 0;
		}
		int count = data[date].size();
		data.erase(date);
		return count;;
	}

    set<string> Find(const Date& date) const {
    	if (data.count(date) == 0) {
    		return {};
    	}
    	return data.at(date);
    }

	void Print() const {
		for (const auto& item : data) {
			for (const auto& event : item.second) {
				cout << item.first << " " << event << endl;
			}
		}
	}

private:
	map<Date, set<string>> data;
};

int main() {
	Database db;

	string line;
	while (getline(cin, line)) {
		try {
			if (line != "") {
				stringstream ss(line);
				string command;
				string param_date;
				string param_event;
				ss >> command >> param_date >> param_event;
				if (command == "Add") {
					db.AddEvent(Date(param_date), param_event);
				} else if (command == "Del") {
					if (param_event != "") {
						if (db.DeleteEvent(Date(param_date), param_event)) {
							cout << "Deleted successfully" << endl;
						} else {
							cout << "Event not found" << endl;
						}
					} else {
						int count = db.DeleteDate(Date(param_date));
						cout << "Deleted " << count << " events" << endl;
					}
				} else if (command == "Find") {
					set<string> events = db.Find(Date(param_date));
					for (const string& event : events) {
						cout << event << endl;
					}
				} else if (command == "Print") {
					db.Print();
				} else {
					cout << "Unknown command: " << command << endl;;
				}
			}
		} catch (const exception& e) {
			cout << e.what() << endl;
		}
	}

	return 0;
}
