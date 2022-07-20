#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <utility>
#include <algorithm>

using namespace std;

class Node {
 private:
     char c;
     int count;
     shared_ptr<Node> left;
     shared_ptr<Node> right;
 public:
     Node(){}
     Node(int count) {
        if(count > 0) this->count = count;
        else throw std::runtime_error("Invalid count"); 
     };
     Node(int count, char c): Node(count) { this->c = c; };
     void addLeft(shared_ptr<Node> node) { left = std::move(node); }
     shared_ptr<Node> getLeft() { return left; };
     void addRight(shared_ptr<Node> node){ right = std::move(node); }
     shared_ptr<Node> getRight() { return right; };
     char getC() { return c; }
     int getCount() { return count; }
};

void traverse(shared_ptr<Node> n, vector<pair<char,string>>&code, string currentCode) { 
    if(n == nullptr) return;
    if(n->getC()) {
        code.push_back(make_pair(n->getC(), currentCode)); 
    }
    traverse(n->getLeft(), code, currentCode + "0");
    traverse(n->getRight(), code, currentCode + "1");
}

class Tree {
private:
    vector<shared_ptr<Node>> nodes;
    vector<pair<char,string>> code;
public:
    Tree(vector<pair<int, char>> v) {
        for(size_t i = 0; i < v.size(); ++i) {
            nodes.push_back(make_shared<Node>(v[i].first, v[i].second));
        }
        while(nodes.size() > 1) {
            std::sort(nodes.begin(), nodes.end(),
                    [](shared_ptr<Node> a, shared_ptr<Node> b){
                        return a->getCount() < b->getCount(); 
                    });
            auto newNode = make_shared<Node>(nodes[0]->getCount() + nodes[1]->getCount());
            newNode->addLeft(nodes[0]);
            newNode->addRight(nodes[1]);
            nodes.push_back(newNode);
            nodes.erase(nodes.begin(), nodes.begin() + 2);
        }
        vector<pair<char,string>> code;
        traverse(nodes[0], code, "");
        this->code = code;
    }
    vector<pair<char,string>> getCode() { return code; }
};

int main() {
    vector<pair<int,char>> v;
    v.push_back(make_pair(2, 'A'));
    v.push_back(make_pair(6, 'B'));
    v.push_back(make_pair(4, 'C'));
    v.push_back(make_pair(5, 'D'));
    v.push_back(make_pair(1, 'E'));

    Tree t(v);
    auto code = t.getCode();
    for(auto c: code) {
        cout << c.first << " " << c.second << endl;
    }
}
