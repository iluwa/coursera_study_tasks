#include <iostream>
#include <map>
using namespace std;

struct FullName {
	string first_name;
	string last_name;
};

class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
		names[year] = {first_name, ""};
	}
	void ChangeLastName(int year, const string& last_name) {
		names[year] = {"", last_name};
	}
	string GetFullName(int year) {
		/*auto it = names.lower_bound(year);
		if (it == names.end()) {
			return "end";
		}
		if(it == names.begin()) {
		    return "begin";
		}
		return "Year: ";*/
		/*if (it == names.begin()) {
			return "Incognito";
		} else {
			if (it->second.last_name == "") {
				return it->second.first_name + " with unknown last name";
			} else if (it->second.first_name == "") {
				return it->second.last_name + " with unknown firsrt name";
			} else {
				return it->second.first_name + " " + it->second.last_name;
			}
		}*/
		return "";
	}
private:
	map<int, FullName> names;
};


int main() {
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}
	return 0;
}
