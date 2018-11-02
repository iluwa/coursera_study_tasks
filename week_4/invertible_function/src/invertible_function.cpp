#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Image {
	double quality;
	double freshness;
	double rating;
};

struct Params {
	double a;
	double b;
	double c;
};

class FunctionPart {
public:
	FunctionPart(char new_operation, double new_value) {
		operation = new_operation;
		value = new_value;
	}
	double Apply(double initial_value) const {
		if (operation == '+') {
			return initial_value + value;
		} else {
			return initial_value - value;
		}
	}
	void Invert() {
		if (operation == '+') {
			operation = '-';
		} else {
			operation = '+';
		}
	}
private:
	char operation;
	double value;
};

class Function {
public:
	double Apply(double initial_value) const {
		for (const auto& part : parts) {
			initial_value = part.Apply(initial_value);
		}
		return initial_value;
	}
	void AddPart(char new_operation, double new_value) {
		parts.push_back(FunctionPart(new_operation, new_value));
	}
	void Invert() {
		for (auto& part : parts) {
			part.Invert();
		}
		reverse(begin(parts), end(parts));
	}
private:
	vector<FunctionPart> parts;
};

Function MakeWeightFunction(const Params& params,
                            const Image& image) {
	Function function;
	function.AddPart('-', image.freshness * params.a + params.b);
	function.AddPart('+', image.rating * params.c);
	return function;
}

double ComputeImageWeight(const Params& params, const Image& image) {
	Function function = MakeWeightFunction(params, image);
	return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params,
                              const Image& image,
                              double weight) {
	Function function = MakeWeightFunction(params, image);
	function.Invert();
	return function.Apply(weight);
}

int main() {
	Image image = {10, 2, 6};
	Params params = {4, 2, 6};
	cout << ComputeImageWeight(params, image) << endl;
	cout << ComputeQualityByWeight(params, image, 46) << endl;
	return 0;
}
