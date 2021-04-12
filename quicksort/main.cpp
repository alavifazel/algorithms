#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int partition(vector<int> &vec, int l, int r);
void printVector(vector<int> vec);

void quicksort(vector<int> &vec, int l, int r) {
    if(l >= r) return;
    int pivotIndex = partition(vec, l, r);
    cout << '\n';
    quicksort(vec, l, pivotIndex-1);
    quicksort(vec, pivotIndex+1, r);
}

int partition(vector<int> &vec, int l, int r) {
    cout << l << " " << r << endl;
    int pivotIndex = r;
    int i = l-1;
    for(int j = l; j < r; j++) {
        if(vec[j] < vec[pivotIndex]) {
            i++;
            std::swap(vec[i], vec[j]); 
            printVector(vec);
        }
    }
    std::swap(vec[pivotIndex], vec[i+1]);
    printVector(vec);
    return i+1;
}

void printVector(vector<int> v) {
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << '\n';
}

int main() {
    vector<int> v = {4,2,-3,-5,3,6,7,8,-2};
    quicksort(v, 0, v.size()-1);
    cout << "Sorted vector:\n";
    printVector(v);
}