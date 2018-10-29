#include <iostream>
#include <set>
#include <map>
using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m) {
	set<string> values;
	for (const auto& item : m) {
		values.insert(item.second);
	}
	return values;
}

/*int main() {
	map<int, string> inp = {
		    {1, "odd"},
		    {2, "even"},
		    {3, "odd"},
		    {4, "even"},
		    {5, "odd"}
		};
	set<string> values = BuildMapValuesSet(inp);

	for (const string& value : values) {
	  cout << value << endl;
	}
	return 0;
}*/
