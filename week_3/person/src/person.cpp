#include <iostream>
#include <map>
using namespace std;

/*struct FullName {
	string first_name;
	string last_name;
};*/

int findNearestKey(const map<int, string>& m, int target) {
	int nearest_key = 0;
	for (auto rit = m.rbegin(); rit != m.rend(); ++rit) {
		if (rit -> first <= target) {
			nearest_key = rit -> first;
			break;
		}
	}
	return nearest_key;
}

class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
		first_name_map[year] = first_name;
	}
	void ChangeLastName(int year, const string& last_name) {
		last_name_map[year] = last_name;
	}
	string GetFullName(int year) {
		int first_name_key = findNearestKey(first_name_map, year);
		int last_name_key = findNearestKey(last_name_map, year);
		int first_name_count = first_name_map.count(first_name_key);
		int last_name_count = last_name_map.count(last_name_key);
		if (first_name_count == 0 && last_name_count == 0) {
			return "Incognito";
		} else {
			if (last_name_count == 0 && first_name_count > 0) {
				return first_name_map[first_name_key] + " with unknown last name";
			} else if (first_name_count == 0 && last_name_count > 0) {
				return last_name_map[last_name_key] + " with unknown firsrt name";
			} else {
				return first_name_map[first_name_key] + " " + last_name_map[last_name_key];
			}
		}
	}
private:
	map<int, string> last_name_map;
	map<int, string> first_name_map;
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
