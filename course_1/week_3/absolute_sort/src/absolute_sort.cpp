#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void PrintVector(const vector<int>& v) {
	for (const auto& item : v) {
		cout << item << " ";
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end(), [](int a, int b){
		if (abs(a) < abs(b)) {
			return true;
		}
		return false;
	});
	PrintVector(v);
	return 0;
}
