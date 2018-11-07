#include <iostream>
#include <vector>
using namespace std;

struct Student {
	string first_name;
	string last_name;
	int day;
	int month;
	int year;
};

int main() {
	vector<Student> students;
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		Student student;
		cin >> student.first_name >> student.last_name >> student.day >> student.month >> student.year;
		students.push_back(student);
	}

	int m = 0;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		string command;
		size_t num;
		cin >> command >> num;
		--num;
		if (num > students.size() || num < 0) {
			cout << "bad request" << endl;
		} else {
			if (command == "name") {
				cout << students[num].first_name << " " << students[num].last_name << endl;
			} else if (command == "date") {
				cout << students[num].day << "." << students[num].month << "." << students[num].year << endl;
			} else {
				cout << "bad request" << endl;
			}
		}
	}

	return 0;
}
