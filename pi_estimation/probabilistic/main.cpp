#include <iostream>
#include <random>
#include <iomanip>
using namespace std;

double rand_real(double min = -1, double max = 1);

int main(){
  int inCircle = 0;
  int i = 0;
  for(;;) {
    auto x = rand_real();
    auto y = rand_real();
    auto distance = sqrt(x*x + y*y);
    if(distance < 1){
      inCircle++;
    } 
    cout << ((float)inCircle/i) * 4 << setprecision(20) << '\n';
    i++;
  }
}


double rand_real(double min, double max) {
  static random_device rd;
  static mt19937 generator(rd());
  static uniform_real_distribution<double> distribution(min,max);  
  return distribution(generator);
}
