#include <iostream>
#include <map>
#include <set>
using namespace std;

class Person {
public:
	Person(string first_name, string last_name, int birth_year) {
		this->birth_year = birth_year;
		first_name_map[birth_year] = first_name;
		last_name_map[birth_year] = last_name;
	}

	void ChangeFirstName(int year, const string& first_name) {
		// добавить факт изменения имени на first_name в год year
		if (birth_year < year) {
			first_name_map[year] = first_name;
		}
	}

	void ChangeLastName(int year, const string& last_name) {
		// добавить факт изменения фамилии на last_name в год year
		if (birth_year < year) {
			last_name_map[year] = last_name;
		}
	}

	string GetFullName(int year) {
		// получить имя и фамилию по состоянию на конец года year
		if (birth_year > year) {
			return "No person";
		}
		string first_name = GetNearestMapValue(first_name_map, year);
		string last_name = GetNearestMapValue(last_name_map, year);
		return FormProperOut(first_name, last_name);
	}

	string GetFullNameWithHistory(int year) {
		// получить все имена и фамилии по состоянию на конец года year
		if (birth_year > year) {
			return "No person";
		}
		string first_name = GetHistoryFromMapValues(first_name_map, year);
		string last_name = GetHistoryFromMapValues(last_name_map, year);
		return FormProperOut(first_name, last_name);
	}
private:
	map<int, string> last_name_map;
	map<int, string> first_name_map;
	int birth_year;

	string GetNearestMapValue(const map<int, string>& m, int target) {
		string nearest_value = "";
		for (auto rit = m.rbegin(); rit != m.rend(); ++rit) {
			if (rit -> first <= target) {
				nearest_value = rit -> second;
				break;
			}
		}
		return nearest_value;
	}

	string GetHistoryFromMapValues(const map<int, string>& m, int target) {
		string actual = "";
		string history = "";
		set<string> uniq_validation;
		for (auto rit = m.rbegin(); rit != m.rend(); ++rit) {
			if (rit -> first <= target) {
				if (actual == "") {
					actual = rit -> second;
					uniq_validation.insert(rit -> second);
				} else {
					if (uniq_validation.count(rit -> second) == 0 && rit -> second != actual) {
						if (history == "") {
							history += " (" + rit -> second;
						} else {
							history += ", " + rit -> second;
						}
					}
				}
			}
		}
		if (history != "") {
			history += ")";
		}
		return actual + history;
	}

	string FormProperOut(string first_name, string last_name) {
		if (first_name == "" && last_name == "") {
			return "Incognito";
		} else {
			if (last_name == "" && first_name != "") {
				return first_name + " with unknown last name";
			} else if (first_name == "" && last_name != "") {
				return last_name + " with unknown firsrt name";
			} else {
				return first_name + " " + last_name;
			}
		}
	}

};

int main() {
	Person person("Polina", "Sergeeva", 1960);
	for (int year : {1959, 1960}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeFirstName(1965, "Appolinaria");
	person.ChangeLastName(1967, "Ivanova");
	for (int year : {1965, 1967}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	return 0;
}
