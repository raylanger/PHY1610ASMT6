#include "solver.h"
#include "vectors.h"
#include <iostream>

int main(){

    int N = 50;

    rvector<double> d = get_d(N), off_d = get_offd(N), b = get_b(N);

    // std::cout << d.size() << off_d.size() << b.size() << "\n";
    rvector<double> v = solver(d,off_d,b);

    std::cout << v << "\n";

    return 0;
}