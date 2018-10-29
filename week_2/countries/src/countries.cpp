#include <map>
#include <iostream>
using namespace std;

void print_map(const map<string, string>& m) {
	for (const auto& item : m) {
		cout << item.first << "/" << item.second << " ";
	}
}

int main() {
	int n;
	cin >> n;
	map<string, string> countries;
	for (int i = 0; i < n; i++) {
		string command;
		cin >> command;
		string arg1, arg2;
		if (command == "CHANGE_CAPITAL") {
			cin >> arg1 >> arg2;
			if (countries.count(arg1) == 0) {
				cout << "Introduce new country " << arg1 << " with capital " << arg2 << endl;
				countries[arg1] = arg2;
			}
			else {
				if (countries[arg1] == arg2) {
					cout << "Country " << arg1 << " hasn't changed its capital" << endl;
				} else {
					cout << "Country " << arg1 << " has changed its capital from " << countries[arg1] << " to " << arg2 << endl;
					countries[arg1] = arg2;
				}
			}
		} else if (command == "RENAME") {
			cin >> arg1 >> arg2;
			if (countries.count(arg2) == 1 || countries.count(arg1) == 0 || arg1 == arg2) {
				cout << "Incorrect rename, skip" << endl;
			} else {
				cout << "Country " << arg1 << " with capital " << countries[arg1] << " has been renamed to " << arg2 << endl;
				countries[arg2] = countries[arg1];
				countries.erase(arg1);
			}
		} else if (command == "ABOUT") {
			cin >> arg1;
			if (countries.count(arg1) == 0) {
				cout << "Country " << arg1 << " doesn't exist" << endl;
			} else {
				cout << "Country " << arg1 << " has capital " << countries[arg1] << endl;
			}
		} else if (command == "DUMP") {
			if (countries.size() == 0) {
				cout << "There are no countries in the world" << endl;
			} else {
				print_map(countries);
				cout << endl;
			}

		} else {
			//do nothing
		}
	}
	return 0;
}
