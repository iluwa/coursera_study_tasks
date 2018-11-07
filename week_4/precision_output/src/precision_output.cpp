#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
	ifstream input("input.txt");
	/*if (input) {
		string line;
		cout << fixed << setprecision(3);
		while (getline(input, line)) {
			cout << std::stod(line) << endl;
		}
	}
	*/
	double a;
	cout << fixed << setprecision(3);
	while (input >> a) {
        cout << a << endl;
	}

	return 0;
}
