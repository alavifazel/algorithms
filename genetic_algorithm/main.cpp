#include "GA.h"

double f(vector<double> x) {
    double eq[5];
    eq[0] = pow(2*x[0] + 2*x[1] + 3*x[2] + 1*x[3] + 5*x[4] - 6, 2);
    eq[1] = pow(2*x[0] + 4*x[1] + 3*x[2] + 2*x[3] + 4*x[4] - 1, 2);
    eq[2] = pow(2*x[0] + 1*x[1] + 3*x[2] + 2*x[3] + 3*x[4] - 1, 2);
    eq[3] = pow(4*x[0] + 5*x[1] + 6*x[2] + 7*x[3] + 8*x[4] - 1, 2);
    eq[4] = pow(5*x[0] + 4*x[1] + 3*x[2] + 2*x[3] + 1*x[4] - 1, 2);

    return eq[0]+eq[1]+eq[2]+eq[3]+eq[4];
}

int main() {
    GA GAObj(f, 5);
    GAObj.evolve();
}

