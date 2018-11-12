#include <iostream>
#include <set>
using namespace std;

int main() {
	int n;
	cin >> n;
	set<string> input_set;
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		input_set.insert(input);
	}

	cout << input_set.size() << endl;
	return 0;
}
