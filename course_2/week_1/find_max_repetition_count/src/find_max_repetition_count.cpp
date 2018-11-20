#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

enum class Lang {
  DE, FR, IT
};

struct Region {
  string std_name;
  string parent_std_name;
  map<Lang, string> names;
  int64_t population;
};

bool operator<(const Region& lhs, const Region& rhs) {
	return tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) <
			tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}

int FindMaxRepetitionCount(const vector<Region>& regions) {
	int result = 0;
	map<Region, int> m;
	for (auto const& region : regions) {
		result = max(result, ++m[region]);
	}
	return result;
}

int main() {
	vector<Region> v = {
		      {
		          "Moscow",
		          "Russia",
		          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
		          89
		      }, {
		          "Russia",
		          "Eurasia",
		          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
		          89
		      }, {
		          "Moscow",
		          "Russia",
		          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
		          89
		      }, {
		          "Moscow",
		          "Russia",
		          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
		          89
		      }, {
		          "Russia",
		          "Eurasia",
		          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
		          89
		      },
		  };
	cout << FindMaxRepetitionCount(v) << endl;

	v = {
		      {
		          "Moscow",
		          "Russia",
		          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
		          89
		      }, {
		          "Russia",
		          "Eurasia",
		          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
		          89
		      }, {
		          "Moscow",
		          "Russia",
		          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
		          89
		      }, {
		          "Moscow",
		          "Toulouse",
		          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
		          89
		      }, {
		          "Moscow",
		          "Russia",
		          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
		          31
		      },
		  };
	cout << FindMaxRepetitionCount(v) << endl;
	return 0;
}
