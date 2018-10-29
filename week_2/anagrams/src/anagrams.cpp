#include <iostream>
#include <map>
#include <vector>
using namespace std;

void print_vector(const vector<string>& v) {
	for (const auto& item : v) {
		cout << item << endl;
	}
}

map<char, int> BuildCharCounters(const string& s) {
	map<char, int> result;
	for (const char& c : s) {
		++result[c];
	}
	return result;
}

int main() {
	int n;
	cin >> n;
	vector<string> result;
	for (int i = 0; i < n; i++) {
		string word1, word2;
		cin >> word1 >> word2;
		if (BuildCharCounters(word1) == BuildCharCounters(word2)) {
			result.push_back("YES");
		} else {
			result.push_back("NO");
		}
	}
	print_vector(result);

	return 0;
}
