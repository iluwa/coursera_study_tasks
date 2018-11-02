#include <iostream>
using namespace std;

class ReversibleString {
public:
	ReversibleString() {}
	ReversibleString(const string& s) {
		data = s;
	}

	void Reverse() {
		for (int i = 0; i < (int) data.length() / 2; ++i) {
			char tmp = data[i];
			data[i] = data[data.length() - i - 1];
			data[data.length() - i - 1] = tmp;
		}
		//»ли так reverse(begin(data), end(data));
	}

	string ToString() const {
		return data;
	}
private:
	string data;
};
/*
int main() {
	ReversibleString s("live");
	s.Reverse();
	cout << s.ToString() << endl;

	s.Reverse();
	const ReversibleString& s_ref = s;
	string tmp = s_ref.ToString();
	cout << tmp << endl;

	ReversibleString empty;
	cout << '"' << empty.ToString() << '"' << endl;
	return 0;
}*/
