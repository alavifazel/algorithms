#include <iostream>
#include <vector>
#include <map>

using std::vector;
using std::map;

template<class InputType>
class DFA {
    public:
        DFA(vector<map<InputType,int>*> states,  int state):
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
        vector<map<InputType, int>*> states;
};

int main() {
    using InputType = int;
    vector<map<InputType, int>*> states;
    map<InputType, int> lookupTableRow;
    lookupTableRow[0] = 1;
    lookupTableRow[1] = 2;

    states.push_back(&lookupTableRow);
    states.push_back(&lookupTableRow);
    states.push_back(&lookupTableRow);
    DFA<int> dfa(states, 0);

    InputType input;
    while(std::cin >> input) {
        std::cout << dfa.transition(input) << '\n';
    }
}
