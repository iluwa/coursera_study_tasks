#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
	int n = 0;
	cin >> n;
	map<string, set<string>> synonyms;
	string command = "";
	string arg1 = "";
	string arg2 = "";
	for (int i = 0; i < n; i++) {
		cin >> command;
		if (command == "ADD") {
			cin >> arg1 >> arg2;
			synonyms[arg1].insert(arg2);
			synonyms[arg2].insert(arg1);
		} else if (command == "COUNT") {
			cin >> arg1;
			if (synonyms.count(arg1) == 1) {
				cout << synonyms[arg1].size() << endl;
			}
			else {
				cout << "0" << endl;
			}
		} else if (command == "CHECK") {
			cin >> arg1 >> arg2;
			bool isExists = false;
			if (synonyms.count(arg1) == 1) {
				if (synonyms[arg1].count(arg2) == 1) {
					isExists = true;
					cout << "YES" << endl;
				}
			}

			if (!isExists) {
				cout << "NO" << endl;
			}
		} else {
			cout << "Unknown command" << endl;
		}
	}

	return 0;
}
