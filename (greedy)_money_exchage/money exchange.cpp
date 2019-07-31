#include <iostream>
#include <vector>
#include <map>

using std::vector;
using std::cout;
using std::cin;
using std::map;

int mininumNumberOfCoins(int m, const vector<int>& cash_values) {
	map<int, int> tmp;
	for (int i = 0; i < cash_values.size(); ++i) {
		tmp.insert(std::pair<int, int>(cash_values[i], m / cash_values[i]));
		m %= cash_values[i];
	}
	int minimumNumberOfCoins{ 0 };
	for (const auto& e : tmp) {
		minimumNumberOfCoins += e.second;
	}
	return minimumNumberOfCoins;
}

int main() {
	int m;
	vector<int> cash_values{10,5,1};
	cin >> m;
	cout << mininumNumberOfCoins(m, cash_values) << '\n';
	return 0;
}