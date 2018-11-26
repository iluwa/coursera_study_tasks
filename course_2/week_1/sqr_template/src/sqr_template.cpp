#include <iostream>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

template <typename T> T Sqr(const T& n);
template <typename First, typename Second> pair<First, Second> Sqr(const pair<First, Second>& p);
template <typename T> vector<T> Sqr(const vector<T>& v);
template <typename Key, typename Value> map<Key, Value> Sqr(const map<Key, Value>& m);

template <typename T>
T Sqr(const T& n) {
	return pow(n, 2);
}

template <typename T>
vector<T> Sqr(const vector<T>& v) {
	vector<T> res;
	for (const auto& item : v) {
		res.push_back(Sqr(item));
	}
	return res;
}

template <typename First, typename Second>
pair<First, Second> Sqr(const pair<First, Second>& p) {
	return make_pair(Sqr(p.first), Sqr(p.second));
}

template <typename Key, typename Value>
map<Key, Value> Sqr(const map<Key, Value>& m) {
	map<Key, Value> res;
	for (const auto& [k, v] : m) {
		res[k] = Sqr(v);
	}
	return res;
}

int main() {
	// Пример вызова функции
	vector<int> v = {1, 2, 3};
	cout << "vector:";
	for (int x : Sqr(v)) {
	  cout << ' ' << x;
	}
	cout << endl;

	map<int, pair<int, int>> map_of_pairs = {
	  {4, {2, 2}},
	  {7, {4, 3}}
	};
	cout << "map of pairs:" << endl;
	for (const auto& x : Sqr(map_of_pairs)) {
	  cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
	}
	return 0;
}
