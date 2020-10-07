#include <iostream>
#include <string>
#include "BST.h"

using std::cout;
using std::string;

int main() {
    BST::BST<int,string> b;
    b.put(10, "AAA");
    b.put(20, "BBB");
    b.put(300, "CCC");
    
   cout << b.get(10) << '\n'; 

    auto Q = b.keys();
    queue<int> tmp_q = Q;
    while (!tmp_q.empty()) {
        auto q_element = tmp_q.front();
        std::cout << q_element <<"\t";
        tmp_q.pop();
    }
    cout << '\n';
}
