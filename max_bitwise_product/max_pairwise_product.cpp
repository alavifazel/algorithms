#include <iostream>
#include <vector>
using namespace std;

using std::vector;
using std::cin;

long long MaxPairwiseProduct(const vector<int>& numbers) {
  size_t n = numbers.size();
  
  int maxIndex1 = -1;
  for(int i = 0; i < n; ++i){
    if(maxIndex1 == -1 || numbers[i] > numbers[maxIndex1]){
      maxIndex1 = i;
    }
  }

  int maxIndex2 = -1;
  for(int i = 0; i < n; ++i){
    if((i != maxIndex1) && (maxIndex2 == -1 || numbers[i] > numbers[maxIndex2])) {
      maxIndex2 = i;
    }
  }

  return ((long long)numbers[maxIndex1]) * numbers[maxIndex2];
}

int main(){
  size_t n;
  cin >> n;
  vector<int> numbers(n);
  for(int i = 0; i < n; ++i){
    std::cin >> numbers[i];
  }

  std::cout << MaxPairwiseProduct(numbers) << endl;
  return 0;
}
