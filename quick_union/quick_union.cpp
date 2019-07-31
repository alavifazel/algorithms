#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Union {
public:

    Union(int n): id(n) {
        for(size_t i = 0; i < id.size(); i++){
            id[i] = int(i); // just to get rid of compiler warning
        }
        for(size_t i = 0; i < id.size(); i++){
            if(id[i] == i){
                rootSizes.push_back(1);
            }
        }
    }

    Union(vector<int> v): id{v}{
        for(size_t i = 0; i < id.size(); i++){
            if(id[i] == i){
                rootSizes.push_back(1);
            }
        }
    }

    void print(){
        for(const auto & e : id){
            cout << e << ' ';
        }
        cout << '\n';

    }
    void printRootsizes(){
        for(const auto & e : rootSizes){
            cout << e << ' ';
        }
        cout << '\n';

    }
    bool is_connected(int p, int q) {
        if(root(p) == root(q)){ // could be written more concretely
            return true;
        } else{
            return false;
        }
    }

    void connect(int p, int q){
        auto rp = root(p);
        auto rq = root(q);
        cout << rootSizes[rp] << " " << rootSizes[rq] << endl;

        if(rootSizes[rp] < rootSizes[rq]) {
            id[rp] = rq;
            rootSizes[rq] += rootSizes[rp];
        } else {
            id[rq] = rp;
            rootSizes[rp] += rootSizes[rq];
        }
    }

private:
    std::vector<int> id;
    std::vector<int> rootSizes;
    int root(int p) {
        while(id[p] != p){
            p = id[p];
        }
        return p;
    }
};

int main() {
    Union u{10};
    u.connect(4,3);
    u.connect(3,5);
    u.connect(4,6);

    u.print();
}
