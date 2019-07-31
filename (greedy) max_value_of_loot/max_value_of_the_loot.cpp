#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using std::vector;
using std::sort;
using std::map;
using std::cout;

template <typename T>
T min(T a, T b) {
	if (a <= b) {
		return a;
	}
	return b;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
	double value = 0.0;

	map<int, int> m;
	map<double, int, std::greater<int>> valuePerWeightToIndex;
	for (int i = 0; i < weights.size(); ++i) {
		valuePerWeightToIndex.insert(std::pair<double, int>((double)values[i] / weights[i], i));
	}

	for (auto i : valuePerWeightToIndex) {
		if (capacity == 0) {
			return value;
		}
		int mm = min(capacity, weights[i.second]);
		value += mm * (i.first);
		capacity -= mm;
	}
	return value;
}


int main() {
	int n;
	int capacity;
	std::cin >> n >> capacity;
	vector<int> values(n);
	vector<int> weights(n);
	for (int i = 0; i < n; i++) {
		std::cin >> values[i] >> weights[i];
	}

	double optimal_value = get_optimal_value(capacity, weights, values);

	std::cout.precision(10);
	std::cout << optimal_value << std::endl;
	return 0;
}
