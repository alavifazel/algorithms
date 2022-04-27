#include <iostream>
#include <memory>
#include <vector>
#include <map>

using std::vector;
using std::map;
using std::shared_ptr;
using std::make_shared;

template<class InputType>
class DFA {
    public:
        DFA(vector<shared_ptr<map<InputType,int>>> states,  int state):
            states{states},
            state(state) { }

        int transition(InputType input) {
            state = (*states[state])[input];
            return state;
        }

        int getState() {
            return state;
        }

    private:
        int state;
        vector<shared_ptr<map<InputType,int>>> states;
};

int main() {
    using InputType = int;
    vector<shared_ptr<map<InputType, int>>> states;
    map<InputType, int> lookupTableRow;
    lookupTableRow[0] = 1;
    lookupTableRow[1] = 2;

    for(size_t i = 0; i < 3; ++i)
        states.push_back(make_shared<map<InputType, int>>(lookupTableRow));

    DFA<int> dfa(states, 0);

    InputType input;
    while(std::cin >> input) {
        std::cout << dfa.transition(input) << '\n';
    }
}
