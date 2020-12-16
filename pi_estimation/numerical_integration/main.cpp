// A simple fun program to estimate Pi value with integration

#include <iostream>
#include <functional>
#include <cmath>
using namespace std;

double integrate(std::function<double(double)> f, 
		double a, double b, size_t k=10000)
{
	double result{0};
	double p = (b-a)/k;
	for(double x = a; x < b; x += p) {
		result += f(x)*p; 
	}
	return result;
}

int main() {
	auto f = [](double x){ return sqrt(1 - x*x); };
	cout.precision(40);
	for(size_t i = 0; i < 1'000'000; i+=10) {
		double circleArea = 2*integrate(f, -1, 1, i);
		cout << circleArea << '\n';
	}
}
